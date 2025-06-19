#include "Cat.hpp"


Cat::Cat() : Animal("Cat") {
    _brain = new Brain();
    if (!_brain) {
        std::cerr << "Memory allocation failed for Brain." << std::endl;
        exit(EXIT_FAILURE);
    }
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
    std::cout << "Cat of type " << _type << " destroyed." << std::endl;
    delete _brain;
}
void Cat::makeSound() const {
    std::cout << "Meow! I am a " << _type << "." <<
    std::endl;
}