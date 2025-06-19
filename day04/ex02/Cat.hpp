#ifndef CAT_HPP
#define CAT_HPP

#include "IAnimal.hpp"
#include "Brain.hpp"

class Cat : public IAnimal {
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const std::string &type);
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        void makeSound() const;
};

#endif // CAT_HPP