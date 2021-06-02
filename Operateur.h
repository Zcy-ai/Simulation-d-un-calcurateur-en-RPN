#ifndef PROJECT_OPERATEUR_H
#define PROJECT_OPERATEUR_H

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

#include "Litterale.h"
#include "Pile.h"

class Operator {
private:
    std::string mes; // Types d'operateurs

public:
    Pile &lirAff = Pile::getInstance(); // interface unique de class pile

    LitteraleSymbol &symbols = LitteraleSymbol::getInstance(); // Interface unique de classe LitteraleSymbol

    explicit Operator(std::string m) : mes(std::move(m)){}; // Constructeur

    [[nodiscard]] virtual const std::string &type_of_litterale() const = 0; // Appeler getMes pour obtenir des informations

    virtual void Action() = 0; // Operation

    [[nodiscard]] const std::string &getMes() const { return mes; } // Obtenir des informations sur le type d'operateur
};

class Operator_Plus : public Operator {
public:
    explicit Operator_Plus(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Plus() = default;
};

class Operator_Minus : public Operator {
public:
    explicit Operator_Minus(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Minus() = default;
};

class Operator_Multi : public Operator {
public:
    explicit Operator_Multi(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Multi() = default;
};

class Operator_Div : public Operator {
public:
    explicit Operator_Div(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Div() = default;
};

class Operator_DivExact : public Operator {
public:
    explicit Operator_DivExact(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_DivExact() = default;
};

class Operator_Mod : public Operator {
public:
    explicit Operator_Mod(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Mod() = default;
};

class Operator_Neg : public Operator {
public:
    explicit Operator_Neg(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Neg() = default;
};

class Operator_Num : public Operator {
public:
    explicit Operator_Num(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Num() = default;
};

class Operator_Den : public Operator {
public:
    explicit Operator_Den(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Den() = default;
};

class Operator_Pow : public Operator {
public:
    explicit Operator_Pow(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Pow() = default;
};

class Operator_Sin : public Operator {
public:
    explicit Operator_Sin(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Sin() = default;
};

class Operator_Cos : public Operator {
public:
    explicit Operator_Cos(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Cos() = default;
};

class Operator_Tan : public Operator {
public:
    explicit Operator_Tan(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Tan() = default;
};

class Operator_ArcSin : public Operator {
public:
    explicit Operator_ArcSin(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_ArcSin() = default;
};

class Operator_ArcCos : public Operator {
public:
    explicit Operator_ArcCos(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_ArcCos() = default;
};

class Operator_ArcTan : public Operator {
public:
    explicit Operator_ArcTan(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_ArcTan() = default;
};

class Operator_Sqrt : public Operator {
public:
    explicit Operator_Sqrt(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Sqrt() = default;
};

class Operator_Exp : public Operator {
public:
    explicit Operator_Exp(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Exp() = default;
};

class Operator_Ln : public Operator {
public:
    explicit Operator_Ln(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Ln() = default;
};

class Operator_Equal : public Operator {
public:
    explicit Operator_Equal(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Equal() = default;
};

class Operator_NotEqual : public Operator {
public:
    explicit Operator_NotEqual(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_NotEqual() = default;
};

class Operator_LE : public Operator {
public:
    explicit Operator_LE(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_LE() = default;
};

class Operator_HE : public Operator {
public:
    explicit Operator_HE(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_HE() = default;
};

class Operator_Lesser : public Operator {
public:
    explicit Operator_Lesser(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Lesser() = default;
};

class Operator_Higher : public Operator {
public:
    explicit Operator_Higher(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Higher() = default;
};

class Operator_And : public Operator {
public:
    explicit Operator_And(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_And() = default;
};

class Operator_Or : public Operator {
public:
    explicit Operator_Or(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Or() = default;
};

class Operator_Not : public Operator {
public:
    explicit Operator_Not(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Not() = default;
};

class Operator_Eval : public Operator {
public:
    explicit Operator_Eval(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Eval() = default;
};

class Operator_Dup : public Operator {
public:
    explicit Operator_Dup(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Dup() = default;
};

class Operator_Drop : public Operator {
public:
    explicit Operator_Drop(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Drop() = default;
};

class Operator_Swap : public Operator {
public:
    explicit Operator_Swap(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Swap() = default;
};

class Operator_Clear : public Operator {
public:
    explicit Operator_Clear(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Clear() = default;
};

class Operator_Ift : public Operator {
public:
    explicit Operator_Ift(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Ift() = default;
};

class Operator_Sto : public Operator {
public:
    explicit Operator_Sto(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Sto() = default;
};

class Operator_Forget : public Operator {
public:
    explicit Operator_Forget(const std::string &m) : Operator(m) {}

    [[nodiscard]] const std::string &type_of_litterale() const override { return getMes(); }

    void Action() override;

    virtual ~Operator_Forget() = default;
};

Operator *toOperator(const std::string &s); // Obtenir le pointeur toOperator

std::tuple<double, std::string> getOneSetData(Pile &lirAff = Pile::getInstance()); // Obtenir un ensemble de donnees std::tuple<double, std::string>

std::tuple<double, double, std::string, std::string> getTwoSetData(Pile &lirAff = Pile::getInstance()); // Obtenir deux ensembles de donnees std::tuple<double, std::string>

void fromExpressionToSymbol(const std::string &s, Pile &lirAff = Pile::getInstance()); // Convertir les donnees de type Expression en donnees de type Symbole

#endif  // PROJECT_OPERATEUR_H