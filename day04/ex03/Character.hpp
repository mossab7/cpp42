#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MATIRIA_MAX 100

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *inventory[MATIRIA_MAX];
        size_t    _size;
        AMateria *_trackedMatiria[100];
        size_t   _trackedMtSize;
        void _addTrackedMatiria(AMateria *m);
    public: 
    Character();
    Character(const std::string &name);
    ~Character();
    Character &operator=(const Character &other);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};


#endif  //CHARACTER_HPP