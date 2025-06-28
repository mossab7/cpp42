#include "Character.hpp"

AMateria **iniTrackedMateria()
{
	AMateria **items = new AMateria*[INIT_CAP];
	for (size_t i = 0; i < INIT_CAP; i++)
		items[i] = NULL;
	return items;
}

t_trackedMateria Character::_trackedMatiria = {
	iniTrackedMateria(),
	0,
	INIT_CAP
};

size_t Character::_refcount = 0;

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = NULL;
		}

		_name = other._name;
		_size = 0;

		for (size_t i = 0; i < other._size; i++)
		{
			if (other.inventory[i])
			{
				inventory[i] = other.inventory[i]->clone();
				_size++;
			}
			else
				inventory[i] = NULL;
		}

		for (size_t i = _size; i < MATERIA_MAX; i++)
			inventory[i] = NULL;
	}
	return (*this);
}

void Character::_addTrackedMatiria(AMateria *m)
{
	for (size_t i = 0; i < _trackedMatiria.size; i++)
	{
		if (_trackedMatiria.items[i] == m)
			return;
	}

	if (_trackedMatiria.cap <= _trackedMatiria.size)
	{
		size_t newCap = _trackedMatiria.cap == 0 ? INIT_CAP : _trackedMatiria.cap * CAP_FACTOR;
		AMateria **newItems = new AMateria*[newCap];

		for (size_t i = 0; i < _trackedMatiria.size; i++)
			newItems[i] = _trackedMatiria.items[i];
		for (size_t i = _trackedMatiria.size; i < newCap; i++)
			newItems[i] = NULL;

		if (_trackedMatiria.items)
			delete[] _trackedMatiria.items;
		_trackedMatiria.items = newItems;
		_trackedMatiria.cap = newCap;
	}

	_trackedMatiria.items[_trackedMatiria.size] = m;
	_trackedMatiria.size++;
}

Character::~Character()
{
	_refcount--;
	std::cout << "character destructor is called for " << _name << std::endl;
	for (size_t i = 0; i < _size; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	if (_refcount > 0)
		return;
	if (_trackedMatiria.size > 0)
	{
		for (size_t i = 0; i < _trackedMatiria.size; i++)
		{
			if (_trackedMatiria.items[i])
				delete _trackedMatiria.items[i];
		}
		delete[] _trackedMatiria.items;
		_trackedMatiria.items = NULL;
	}
	_trackedMatiria.size = 0;
	_trackedMatiria.cap = 0;
}

Character::Character()
{
	_refcount++;
	std::cout << "character constructor is called for " << _name << std::endl;
	_size = 0;
	_name = "default";
	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	_refcount++;
	_name = name;
	_size = 0;
	std::cout << "character constructor is called for " << _name << std::endl;
	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	_name = other._name;
	_size = 0;
	_refcount++;
	std::cout << "character copy constructor is called for " << _name << std::endl;

	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;

	for (size_t i = 0; i < other._size; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
			_size++;
		}
	}
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (_size >= MATERIA_MAX)
	{
		_addTrackedMatiria(m);
		return;
	}
	for (size_t i = 0; i < _trackedMatiria.size; i++)
	{
		if (m == _trackedMatiria.items[i])
		{
			for (size_t j = i; j < _trackedMatiria.size; j++)
			{
				_trackedMatiria.items[j] = _trackedMatiria.items[j + 1];
			}
		}
	}
	inventory[_size] = m;
	_size++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx >= _size)
		return;

	AMateria *unequipped = inventory[idx];
	if (unequipped != NULL)
		_addTrackedMatiria(unequipped);

	for (size_t i = idx; i < _size - 1; i++)
		inventory[i] = inventory[i + 1];
	inventory[_size - 1] = NULL;
	_size--;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || (unsigned int)idx >= _size)
		return;
	if (inventory[idx] == NULL)
		return;
	inventory[idx]->use(target);
}
