#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    _brain = new Brain();
    if (!_brain) {
        std::cerr << "Memory allocation failed for Brain." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Dog created." << std::endl;
}
Dog::Dog(const std::string &type) : Animal(type) {
    std::cout << "Dog of type " << _type << " created." << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copied." << std::endl;
}
Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}
Dog::~Dog() {
    std::cout << "Dog of type " << _type << " destroyed." << std::endl;
    delete _brain;
}
void Dog::makeSound() const {
    std::cout << "Woof! I am a " << _type << "." <<
    std::endl;
}
