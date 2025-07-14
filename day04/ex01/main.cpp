#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Animal *animals[10];
    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; ++i) {
        animals[i] = new Cat();
    }
    {
        Dog dog;
        dog = *(Dog *)animals[0];
        dog.makeSound();
    }
    for (int i = 0; i < 10; ++i) {
        animals[i]->makeSound();
        delete animals[i];
    }

    return 0;
}