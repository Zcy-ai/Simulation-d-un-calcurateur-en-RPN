#ifndef PROJECT_CONTROLEUR_H
#define PROJECT_CONTROLEUR_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

#include "Operateur.h"
#include "Pile.h"

class Controleur {
private:
    Pile &lirAff = Pile::getInstance(); // interface unique de type pile
    static Controleur *instance; // pointeur unique de la classe Controleur
    std::map<std::string, Operator *> OP; // operateur map std::map<std::string, Operator *>
    bool state = true; // Etat de fonctionnement de la calculatrice

    Controleur() = default; // constructeur prive

    ~Controleur() = default; // destructeur prive

    void estOperateur(const std::string &s); // identifie l'operateur, inscrit l'operateur map, et effectue l'operation

public:
    Controleur(const Controleur &c) = delete; // supprimer le constructeur de copie

    Controleur &operator=(const Controleur &c) = delete; // supprimer operateur d'assignation

    static Controleur &getInstance(); // Renvoie un seul objet de la classe Controleur

    void executer(); // fonction d'executer

    void commande(const std::string &s); // fonction d'accepter la commande

    void setException(const std::string &s); // Sortie anormale

    [[nodiscard]] bool getState() const; // Obtenir l'etat actuel de la calculatrice
};

#endif  // PROJECT_CONTROLEUR_H