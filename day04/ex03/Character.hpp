#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MATERIA_MAX 4
#define INIT_CAP 100
#define CAP_FACTOR 2

typedef struct s_trackedMateria
{
	AMateria **items;
	size_t size;
	size_t cap;
} t_trackedMateria;

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *inventory[MATERIA_MAX];
	size_t _size;
	static t_trackedMateria _trackedMatiria;
	static size_t _refcount;
	void _addTrackedMatiria(AMateria *m);

public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	~Character();
	Character &operator=(const Character &other);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
