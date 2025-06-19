#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    std::cout << "Cat created." << std::endl;
}
Cat::Cat(const std::string &type) : Animal(type) {
    std::cout << "Cat of type " << _type << " created." << std
::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copied." << std::endl;
}
Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}
Cat::~Cat() {
    std::cout << "Cat of type " << _type << " destroyed." << std
::endl;
}
void Cat::makeSound() const {
    std::cout << "Meow! I am a " << _type << "." <<
    std::endl;
}