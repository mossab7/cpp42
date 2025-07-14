#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	IAnimal *animals[10];
	for (int i = 0; i < 5; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = 5; i < 10; ++i)
	{
		animals[i] = new Cat();
	}

	{
		Dog tmp = *(Dog *)animals[0];
		tmp.makeSound();
	}

	{
		Cat tmp(*(Cat *)animals[5]);
		tmp.makeSound();
	}

	for (int i = 0; i < 10; ++i)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	return 0;
}
