#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#define MATERIA_SLOTS 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[MATERIA_SLOTS];
	size_t _size;

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP
