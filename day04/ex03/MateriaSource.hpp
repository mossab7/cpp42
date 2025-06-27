#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#define MATIRIA_MAX 100

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[4];
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
