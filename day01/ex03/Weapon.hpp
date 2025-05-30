#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	std::string&	getType();
	void			setType( std::string weapon );
	Weapon();
	Weapon( std::string weapon );
	Weapon &operator=(const Weapon &other);
	Weapon( const Weapon &other );
	~Weapon();
};





#endif //WEAPON_HPP
