#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _size(0)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (size_t i = 0; i < 4; ++i)
		_materias[i] = NULL;
}
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (size_t i = 0; i < _size; ++i)
		delete _materias[i];
}
MateriaSource::MateriaSource(const MateriaSource &other) : _size(other._size)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (size_t i = 0; i < 4; ++i)
		_materias[i] = NULL;
	for (size_t i = 0; i < _size; ++i)
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < _size; ++i)
			delete _materias[i];
		_size = other._size;
		for (size_t i = 0; i < _size; ++i)
			_materias[i] = other._materias[i]->clone();
		for (size_t i = _size; i < MATERIA_SLOTS; ++i)
			_materias[i] = NULL;
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria *m)
{
	if (_size < 4 && m)
	{
		_materias[_size] = m->clone();
		_size++;
		delete m;
	}
	else if (m)
	{
		delete m;
	}
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}
