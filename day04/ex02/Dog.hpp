#ifndef DOG_HPP
#define DOG_HPP

#include "IAnimal.hpp"
#include "Brain.hpp"

class Dog : public IAnimal {
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const std::string &type);
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        void makeSound() const;
};


#endif // DOG_HPP