#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
    initTemplates();
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    initTemplates();
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone();
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        clearTemplates();
        for (int i = 0; i < 4; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    clearTemplates();
}

void MateriaSource::initTemplates() {
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
            templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = m->clone();
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource is full! Cannot learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
            std::cout << "MateriaSource creating " << type << std::endl;
            return templates[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know how to create " << type << std::endl;
    return NULL;
}
