//
// Created by 黎袁昊 on 2020/10/28.
//

#include "Controleur.h"

Controleur *Controleur::instance = nullptr;

Controleur &Controleur::getInstance() {
    if (instance == nullptr) instance = new Controleur();
    return *instance;
}

void Controleur::executer() {
    std::string s;
    do {
        lirAff.affiche();
        std::cout << "?-";
        std::getline(std::cin, s);
        if (s == "Q")
            state = false;
        else
            commande(s);
    } while (state);
}

void Controleur::commande(const std::string &s) {
    std::string type = estQuelType(s);
    LitteraleFactory *lirFac = nullptr;
    if (type == "Programme")
        lirFac = new LitteraleProgrammeFactoty;
    else{
        std::stringstream check(s);
        std::string intermediate;
        while (std::getline(check, intermediate, ' ')){
            std::string newType = estQuelType(intermediate);
            if (newType == "Expression")
                lirFac = new LitteraleExpressionFactoty;
            else if (newType == "Symbol") {
                std::string temp = getSymbol(intermediate);
                std::string moreNewType = estQuelType(temp);
                lirAff.push(toLitterale(temp));
                if (moreNewType == "Programme") estOperateur("EVAL");
            } else if (newType == "OperateurNotParameter")
                estOperateur(intermediate);
            else if (newType == "OperateurUnaire")
                if (lirAff.taille() >= 1)
                    estOperateur(intermediate);
                else
                    throw std::invalid_argument("pas assez d'arguments");
            else if (newType == "OperateurBinaire")
                if (lirAff.taille() >= 2)
                    estOperateur(intermediate);
                else
                    throw std::invalid_argument("pas assez d'arguments");
            else if (newType == "Fraction")
                lirFac = new LitteraleFractionFactoty;
            else if (newType == "Rationnelle")
                lirFac = new LitteraleRationnelleFactoty;
            else if (newType == "Entiere")
                lirFac = new LitteraleEntiereFactoty;
            else
                throw std::invalid_argument("Erreur de format d'entree");
            if (newType != "OperateurNotParameter" && newType != "OperateurUnaire" && newType != "OperateurBinaire" && newType != "Symbol") {
                lirAff.push(lirFac->FactoryMethod(intermediate));
                lirAff.setMessage("Ajouter des donnees de type de " + lirFac->ProductType());
            }
        }
    }
    if (type == "Programme") {
        lirAff.push(lirFac->FactoryMethod(s));
        lirAff.setMessage("Ajouter des donnees de type de " + lirFac->ProductType());
    }
}

void Controleur::estOperateur(const std::string &s) {
    auto iter = OP.find(s);
    if (iter != OP.end())
        iter->second->Action();
    else {
        Operator *opt = toOperator(s);
        OP[opt->type_of_litterale()] = opt;
        auto new_iter = OP.find(s);
        new_iter->second->Action();
    }
}

void Controleur::setException(const std::string &s) { lirAff.setMessage(s); }

bool Controleur::getState() const { return state; }
