#include "Character.hpp"

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
	}
	return (*this);
}

void Character::_addTrackedMatiria(AMateria *m)
{
	for (size_t i = 0; i < _trackedMtSize; i++)
	{
		if (_trackedMatiria[i] == m)
			return;
	}

	if (_trackedMtSize >= TRACKED_MAX)
	{
		delete _trackedMatiria[0];

		for (size_t i = 0; i < TRACKED_MAX - 1; i++)
		{
			_trackedMatiria[i] = _trackedMatiria[i + 1];
		}

		_trackedMtSize = TRACKED_MAX - 1;
	}

	_trackedMatiria[_trackedMtSize] = m;
	_trackedMtSize++;
}

Character::~Character()
{
	std::cout << "character destructor is called for " << _name << std::endl;
	for (size_t i = 0; i < _size; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	for (size_t i = 0; i < _trackedMtSize; i++)
	{
		if (_trackedMatiria[i])
			delete _trackedMatiria[i];
	}
}

Character::Character()
{
	std::cout << "character constructor is called for " << _name << std::endl;
	_size = 0;
	_trackedMtSize = 0;
	_name = "default";
	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;
	for (size_t i = 0; i < TRACKED_MAX; i++)
		_trackedMatiria[i] = NULL;
}

Character::Character(const std::string &name)
{
	_name = name;
	_size = 0;
	_trackedMtSize = 0;
	std::cout << "character constructor is called for " << _name << std::endl;
	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;
	for (size_t i = 0; i < TRACKED_MAX; i++)
		_trackedMatiria[i] = NULL;
}

Character::Character(const Character &other)
{
	_name = other._name;
	_size = 0;
	_trackedMtSize = 0;
	std::cout << "character copy constructor is called for " << _name << std::endl;

	for (size_t i = 0; i < MATERIA_MAX; i++)
		inventory[i] = NULL;
	for (size_t i = 0; i < TRACKED_MAX; i++)
		_trackedMatiria[i] = NULL;

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
		std::cout << _name << " slots are full" << std::endl;
		return;
	}
	inventory[_size] = m;
	_size++;
}

void Character::unequip(int idx)
{
	if (idx < 0 || (unsigned int)idx >= _size)
		return;

	AMateria *unequipped = inventory[idx];
	inventory[idx] = NULL;
	if (unequipped != NULL)
		_addTrackedMatiria(unequipped);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || (unsigned int)idx >= _size)
		return;
	if (inventory[idx] == NULL)
		return;
	inventory[idx]->use(target);
}
