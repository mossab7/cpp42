#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("InvalidMateria");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(1);
	me->use(1, *bob);
	bob->equip(tmp);
	bob->use(0, *me);

	std::cout << "-----------------------------------------" << std::endl;
	bob->use(-1,*me);
	bob->equip(NULL);
	bob->equip(new Cure);
	bob->equip(new Ice);
	bob->equip(new Cure);
	bob->use(1,*me);
	{
		Character npc(*(Character *)bob);
		npc.use(0,*bob);
		npc.use(2,*me);
	}
	std::cout << "------------------------------------------" << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}


