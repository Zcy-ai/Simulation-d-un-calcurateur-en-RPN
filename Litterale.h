#ifndef PROJECT_LITTERALE_H
#define PROJECT_LITTERALE_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>

class Litterale {
public:
    virtual std::string toString() = 0; // Obtenir une chaine

    [[nodiscard]] virtual double toDouble() const { return 0; }; // Obtenir un nombre a virgule flottante

    virtual ~Litterale() = default; // Destructeur virtuel
};

class LitteraleNumerique : public Litterale {
public:
    std::string toString() override = 0; // Obtenir une chaine

    virtual LitteraleNumerique *simplifier() = 0; // Simplifier et redefinir les types

    [[nodiscard]] double toDouble() const override = 0; // Obtenir un nombre a virgule flottante
};

class LitteraleAtome : public Litterale {
private:
    std::string nom_atome; // atome

public:
    std::string toString() override { return nom_atome; } // Obtenir une chaine

    explicit LitteraleAtome(std::string str_atome) : nom_atome(std::move(str_atome)) {} // Constructeur
};

class LitteraleExpression : public Litterale {
private:
    std::string nom_expression; // expression

public:
    std::string toString() override { return nom_expression; } // Obtenir une chaine

    explicit LitteraleExpression(std::string expression) : nom_expression(std::move(expression)) {} // Constructeur
};

class LitteraleSymbol : public Litterale {
private:
    std::string nom_symbol;  // symbol

    std::map<std::string, std::string> symbolTable; // Stocker les symboles associes à STO

    static LitteraleSymbol *instance; // LitteraleSymbol

    LitteraleSymbol() = default; // constructeur prive

    ~LitteraleSymbol() override = default; // destructeur prive

public:
    std::string toString() override { return nom_symbol; } // Obtenir une chaine

    LitteraleSymbol(const LitteraleSymbol &c) = delete; // Supprimer le constructeur de copie

    LitteraleSymbol &operator=(const LitteraleSymbol &c) = delete; // Supprimer l'operateur d'affectation

    static LitteraleSymbol &getInstance(); // Renvoie un seul objet de la classe LitteraleSymbol

    void insert(const std::string &a, const std::string &b); // Inserer une paire associee

    void remove(const std::string &a); // Supprimer une paire associee

    friend std::string getSymbol(const std::string &a, LitteraleSymbol &LS); // Obtenir la valeur dans la paire d'associations

    friend bool estExist(const std::string &a, LitteraleSymbol &LS); // si la paire d'associations existe dans map
};

class LitteraleProgramme : public Litterale {
private:
    std::list<Litterale *> elements;  // Litterale tableau de pointeurs

public:
    LitteraleProgramme() = default; // Constructeur

    explicit LitteraleProgramme(std::string programme); // Constructeur

    std::string toString() override; // Convertir en chaine

    Litterale *getFirstElement(); //Obtenir le premier element du tableau et supprimer-le

    unsigned int getLength(); // Obtenir la taille du tableau

    void elementsPushBack(Litterale *); //Ajouter a la fin du tableau
};

class LitteraleEntiere : public LitteraleNumerique {
private:
    int entiere;  // nombre entier

    friend class LitteraleFraction;  // class de nombre rationnel

    friend class LitteraleRationnelle;  // Classe de nombre reel

    explicit LitteraleEntiere(int); //destructeur prive

    friend LitteraleNumerique *toNumerique(double); // La seule fonction qui permet de creer des objets Entiere

public:
    std::string toString() override { return std::to_string(entiere); } // Obtenir une chaine

    LitteraleNumerique *simplifier() override; // Creer un objet pour la fonction toNumerique

    [[nodiscard]] double toDouble() const override; // Obtenir un nombre a virgule flottante
};

class LitteraleFraction : public LitteraleNumerique {
private:
    int numerateur;    // numerateur
    int denominateur;  // denominateur

    LitteraleFraction(int n, int d); // destructeur prive

    friend LitteraleNumerique *toNumerique(double); // Fonctions permettant de creer des objets Fraction

    friend LitteraleNumerique *getFraction(int, int); // Fonctions permettant de creer des objets Fraction

public:
    std::string toString() override { // Obtenir une chaine
        return std::to_string(numerateur) + "/" + std::to_string(denominateur);
    }

    LitteraleNumerique *simplifier() override; // Creer un objet pour la fonction toNumerique

    [[nodiscard]] double toDouble() const override; //Obtenir un nombre a virgule flottante

    void simplification(); // Reduction de fraction
};

class LitteraleRationnelle : public LitteraleNumerique {
private:
    int partie_entiere;   // nombre entier
    int partie_decimale;  // fraction decimale

    LitteraleRationnelle(int e, int d) : partie_entiere(e), partie_decimale(d) {} // destructeur prive

    friend LitteraleNumerique *toNumerique(double); // La seule fonction qui permet de creer des objets Rationale

public:
    std::string toString() override; // Obtenir une chaine

    LitteraleNumerique *simplifier() override; //  Creer un objet pour la fonction toNumerique

    [[nodiscard]] double toDouble() const override; // Obtenir un nombre a virgule flottante
};

LitteraleNumerique *toNumerique(double); // La seule fonction qui permet de creer des objets numeriques

LitteraleNumerique *getFraction(int, int); // Fonctions permettant de creer des objets Fraction

Litterale *toLitterale(const std::string &s); // Convertir en Litterale

std::string estQuelType(const std::string &s); // Determinez quel type

bool estUnOperateurNotParameter(const std::string &s); // Determiner s'il s'agit d'un operateur sans parametre

bool estUnOperateurUnaire(const std::string &s); // Determiner s'il s'agit d'un operateur unaire

bool estUnOperateurBinaire(const std::string &s); // Determinez s'il s'agit d'un operateur binaire

std::string getSymbol(const std::string &a, LitteraleSymbol &LS = LitteraleSymbol::getInstance()); // Obtenir la valeur dans la paire d'associations

bool estExist(const std::string &a, LitteraleSymbol &LS = LitteraleSymbol::getInstance()); // si la paire d'associations existe dans map

class LitteraleFactory {
public:
    virtual ~LitteraleFactory()=default;
    [[nodiscard]] virtual Litterale* FactoryMethod(const std::string &s) const = 0;
    [[nodiscard]] virtual std::string ProductType() const = 0;
};

class LitteraleAtomeFactoty : public  LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return new LitteraleAtome(s);
    }
    [[nodiscard]] std::string ProductType() const override { return "Atome";}
};

class LitteraleExpressionFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return new LitteraleExpression(s);
    }
    [[nodiscard]] std::string ProductType() const override { return "Expression";}
};

class LitteraleSymbolFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return toLitterale(getSymbol(s));
    }
    [[nodiscard]] std::string ProductType() const override { return "Symbol";}
};

class LitteraleProgrammeFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return new LitteraleProgramme(s);
    }
    [[nodiscard]] std::string ProductType() const override { return "Programme";}
};

class LitteraleEntiereFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return toNumerique(std::stod(s));
    }
    [[nodiscard]] std::string ProductType() const override { return "Entiere";}
};

class LitteraleFractionFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        unsigned int pos = s.find('/');
        unsigned int len = s.length();
        std::string t1 = s.substr(pos + 1, len - pos);
        int denominateur = std::stoi(t1);
        std::string t2 = s.substr(0, pos);
        int numerateur = std::stoi(t2);
        return getFraction(numerateur, denominateur);
    }
    [[nodiscard]] std::string ProductType() const override { return "Fraction";}
};

class LitteraleRationnelleFactoty : public LitteraleFactory {
public:
    [[nodiscard]] Litterale* FactoryMethod(const std::string &s) const override {
        return toNumerique(std::stod(s));
    }
    [[nodiscard]] std::string ProductType() const override { return "Rationnelle";}
};

#endif  // PROJECT_LITTERALE_H