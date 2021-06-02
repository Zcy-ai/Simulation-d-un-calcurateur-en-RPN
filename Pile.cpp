//
// Created on 2020/11/7.
//

#include "Pile.h"

Pile *Pile::instance = nullptr;

Pile &Pile::getInstance() {
    if (instance == nullptr) instance = new Pile;
    return *instance;
}

void Pile::affiche() const {
    system("clear");
    std::cout << std::endl << "*********************************************" << std::endl;
    std::cout << "M : " << message << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (unsigned int i = nbAffiche; i > 0; i--)
        if (i <= litterales.size())
            std::cout << i << ": " << litterales[litterales.size() - i]->toString() << std::endl;
        else
            std::cout << i << ": " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void Pile::push(Litterale *l) { litterales.push_back(l); }

void Pile::pop() { litterales.pop_back(); }

unsigned int Pile::taille() const { return litterales.size(); }

Litterale *Pile::top() const { return litterales[taille() - 1]; }

void Pile::clear() { litterales.clear(); }

void Pile::setMessage(const std::string &m) { message = m; }
