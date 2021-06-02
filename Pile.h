//
// Created on 2020/11/7.
//

#ifndef PROJECT_PILE_H
#define PROJECT_PILE_H

#include <vector>

#include "Litterale.h"

class Pile {
private:
    std::vector<Litterale *> litterales; // Tableau de pointeurs Litterale
    unsigned int nbAffiche = 4; // Imprimer le nombre maximum de tableau de pointeurs Litterale
    std::string message; // afficher les calculs et les informations d'exception
    static Pile *instance;  //Pointeur unique de classe de pile
    Pile() = default; // constructeur prive
    ~Pile() = default; // destructeur prive

public:
    Pile(const Pile &optFac) = delete; // Supprimer le constructeur de copie

    Pile &operator=(const Pile &optFac) = delete; // Supprimer l'operateur d'affectation

    static Pile &getInstance(); // Renvoie un seul objet de la classe Pile

    void affiche() const; // Imprimer la page de la calculatrice

    void push(Litterale *l); // Ajouter le dernier element du tableau de pointeur Litterale

    void pop(); // Supprimer le dernier element du tableau de pointeur Litterale

    [[nodiscard]] unsigned int taille() const; //Taille du tableau de pointeur Litterale

    [[nodiscard]] Litterale *top() const; // Renvoie le dernier element du tableau de pointeur Litterale

    void clear(); // Effacer le tableau de pointeurs Litterale

    void setMessage(const std::string &m); // Definir les informations de calcul et d'exception
};

#endif  // PROJECT_PILE_H
