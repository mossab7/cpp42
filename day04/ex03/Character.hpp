#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MATERIA_MAX 4
#define TRACKED_MAX 100

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *inventory[MATERIA_MAX];
	size_t _size;
	AMateria *_trackedMatiria[TRACKED_MAX];
	size_t _trackedMtSize;
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
