#include <iostream>
#include "Operateur.h"

void Operator_Plus::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    double res = v2 + v1;
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " + " + str1 + " = " + lirTemp->toString());
}

void Operator_Minus::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    double res = v2 - v1;
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " - " + str1 + " = " + lirTemp->toString());
}

void Operator_Multi::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    double res = v2 * v1;
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " * " + str1 + " = " + lirTemp->toString());
}

void Operator_Div::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    if (v1 == 0) {
        lirAff.push(toNumerique(v2));
        lirAff.push(toNumerique(v1));
        throw std::logic_error("Division by zero");
    } else {
        double res = v2 / v1;
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(str2 + " / " + str1 + " = " + lirTemp->toString());
    }
}

void Operator_DivExact::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    if ((v1 - int(v1) == 0) && (v2 - int(v2) == 0)) {
        double res = int(v2) / int(v1);
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(str2 + " DIV " + str1 + " = " + lirTemp->toString());
    } else {
        lirAff.push(toNumerique(v2));
        lirAff.push(toNumerique(v1));
        throw std::logic_error(str2 + " ou " + str1 + "n'est pas une entiere");
    }
}

void Operator_Mod::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    if ((v1 - int(v1) == 0) && (v2 - int(v2) == 0)) {
        double res = int(v2) % int(v1);
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(str2 + " MOD " + str1 + " = " + lirTemp->toString());
    } else {
        lirAff.push(toNumerique(v2));
        lirAff.push(toNumerique(v1));
        throw std::logic_error(str2 + " ou " + str1 + "n'est pas une entiere");
    }
}

void Operator_Neg::Action() {
    auto[v1, str1] = getOneSetData();
    double res = (-v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" Neg(" + str1 + ") = " + lirTemp->toString());
}

void Operator_Num::Action() {
    auto[v1, str1] = getOneSetData();
    double res = v1 - int(v1);
    if (res == 0) {
        Litterale *lirTemp = toNumerique(v1);
        lirAff.push(lirTemp);
        lirAff.setMessage(" Num(" + str1 + ") = " + lirTemp->toString());
    } else if (std::to_string(res).length() > 3) {
        lirAff.push(toNumerique(v1));
        throw std::logic_error("Ne peut pas agir sur la Rationnelle");
    } else {
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(" Num(" + str1 + ") = " + lirTemp->toString());
    }
}

void Operator_Den::Action() {
    auto[v1, str1] = getOneSetData();
    double res = v1 - int(v1);
    if (res == 0) {
        Litterale *lirTemp = toNumerique(1);
        lirAff.push(lirTemp);
        lirAff.setMessage(" Den(" + str1 + ") = " + lirTemp->toString());
    } else if (std::to_string(res).length() > 3) {
        lirAff.push(toNumerique(v1));
        throw std::logic_error("Ne peut pas agir sur la Rationnelle");
    } else {
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(" Den(" + str1 + ") = " + lirTemp->toString());
    }
}

void Operator_Pow::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    double res = pow(v2, v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + "^" + str1 + " = " + lirTemp->toString());
}

void Operator_Sin::Action() {
    auto[v1, str1] = getOneSetData();
    double res = sin(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" SIN(" + str1 + ") = " + lirTemp->toString());
}

void Operator_Cos::Action() {
    auto[v1, str1] = getOneSetData();
    double res = cos(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" COS(" + str1 + ") = " + lirTemp->toString());
}

void Operator_Tan::Action() {
    auto[v1, str1] = getOneSetData();
    double res = tan(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" TAN(" + str1 + ") = " + lirTemp->toString());
}

void Operator_ArcSin::Action() {
    auto[v1, str1] = getOneSetData();
    double res = asin(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" ARCSIN(" + str1 + ") = " + lirTemp->toString());
}

void Operator_ArcCos::Action() {
    auto[v1, str1] = getOneSetData();
    double res = acos(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" ARCCOS(" + str1 + ") = " + lirTemp->toString());
}

void Operator_ArcTan::Action() {
    auto[v1, str1] = getOneSetData();
    double res = atan(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" ARCTAN(" + str1 + ") = " + lirTemp->toString());
}

void Operator_Sqrt::Action() {
    auto[v1, str1] = getOneSetData();
    if (v1 < 0) {
        lirAff.push(toNumerique(v1));
        throw std::logic_error("Impossible de mettre au carre un nombre negatif");
    } else {
        double res = sqrt(v1);
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(" SQRT(" + str1 + ") = " + lirTemp->toString());
    }
}

void Operator_Exp::Action() {
    auto[v1, str1] = getOneSetData();
    double res = exp(v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(" Exp(" + str1 + ") = " + lirTemp->toString());
}

void Operator_Ln::Action() {
    auto[v1, str1] = getOneSetData();
    if (v1 <= 0) {
        lirAff.push(toNumerique(v1));
        throw std::logic_error("Impossible de mettre au carre un nombre negatif");
    }
    else {
        double res = log(v1) / log(exp(1));
        Litterale *lirTemp = toNumerique(res);
        lirAff.push(lirTemp);
        lirAff.setMessage(" Ln(" + str1 + ") = " + lirTemp->toString());
    }
}

void Operator_Equal::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 == v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " == " + str1 + " = " + lirTemp->toString());
}

void Operator_NotEqual::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 != v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " != " + str1 + " = " + lirTemp->toString());
}

void Operator_LE::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 <= v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " <= " + str1 + " = " + lirTemp->toString());
}

void Operator_HE::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 >= v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " >= " + str1 + " = " + lirTemp->toString());
}

void Operator_Lesser::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 < v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " < " + str1 + " = " + lirTemp->toString());
}

void Operator_Higher::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 > v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " > " + str1 + " = " + lirTemp->toString());
}

void Operator_And::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 && v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " & " + str1 + " = " + lirTemp->toString());
}

void Operator_Or::Action() {
    auto[v1, v2, str1, str2] = getTwoSetData();
    bool res = (v2 || v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage(str2 + " | " + str1 + " = " + lirTemp->toString());
}

void Operator_Not::Action() {
    auto[v1, str1] = getOneSetData();
    bool res = (!v1);
    Litterale *lirTemp = toNumerique(res);
    lirAff.push(lirTemp);
    lirAff.setMessage("!" + str1 + " = " + lirTemp->toString());
}

void Operator_Eval::Action() {
    Litterale *tempLir = lirAff.top();
    std::string tempStr = tempLir->toString();
    lirAff.pop();
    std::string type = estQuelType(tempStr);
    if (type == "Programme") {
        auto *LirProgramme = dynamic_cast<LitteraleProgramme *>(tempLir);
        while (LirProgramme->getLength()) {
            Litterale *tempL = LirProgramme->getFirstElement();
            std::string tempS = tempL->toString();
            std::string newType = estQuelType(tempS);
            LitteraleFactory *lirFac = nullptr;
            if (newType == "Programme")
                lirFac = new LitteraleProgrammeFactoty();
            else if (newType == "Expression"){
                lirFac = new LitteraleExpressionFactoty();
                Operator *opt = toOperator("EVAL");
                opt->Action();
            } else if (newType == "Symbol")
                lirAff.push(toLitterale(getSymbol(tempS)));
            else if (newType == "OperateurNotParameter") {
                Operator *opt = toOperator(tempS);
                opt->Action();
            } else if (newType == "OperateurUnaire")
                if (lirAff.taille() >= 1) {
                    Operator *opt = toOperator(tempS);
                    opt->Action();
                } else
                    throw std::invalid_argument("Erreur : pas assez d'arguments");
            else if (newType == "OperateurBinaire")
                if (this->lirAff.taille() >= 2) {
                    Operator *opt = toOperator(tempS);
                    opt->Action();
                } else
                    throw std::invalid_argument("Erreur : pas assez d'arguments");
            else if (newType == "Fraction")
                lirFac = new LitteraleFractionFactoty();
            else if (newType == "Rationnelle")
                lirFac = new LitteraleRationnelleFactoty();
            else if (newType == "Entiere")
                lirFac = new LitteraleEntiereFactoty();
            else
                throw std::invalid_argument("Symbole inconnu");
            if (newType != "OperateurNotParameter" && newType != "OperateurUnaire" && newType != "OperateurBinaire" && newType != "Expression") {
                lirAff.push(lirFac->FactoryMethod(tempS));
                lirAff.setMessage("Ajouter des donnees de type de " + lirFac->ProductType());
            }
        }
    } else if (type == "Expression") {
        auto temp = getSymbol(tempStr.substr(1, tempStr.size() - 2));
        fromExpressionToSymbol(tempStr);
        lirAff.setMessage("EVAL(" + tempStr + ") = " + temp);
    } else
        throw std::invalid_argument("EVAL(" + tempStr + ") est mal");
}

void Operator_Dup::Action() {
    Litterale *temp = lirAff.top();
    lirAff.push(temp);
    lirAff.setMessage("DUP Conserve une nouvelle donnee identique a la derniere de la pile");
}

void Operator_Drop::Action() {
    lirAff.pop();
    lirAff.setMessage("DROP Libere les dernieres donnees de la pile");
}

void Operator_Swap::Action() {
    Litterale *temp1 = lirAff.top();
    lirAff.pop();
    Litterale *temp2 = lirAff.top();
    lirAff.pop();
    lirAff.push(temp1);
    lirAff.push(temp2);
    lirAff.setMessage("SWAP Echange les deux derniers elements de la pile");
}

void Operator_Clear::Action() {
    lirAff.clear();
    lirAff.setMessage("CLEAR Vide la pile");
}

void Operator_Ift::Action() {
    Litterale *tempLir1 = lirAff.top();
    lirAff.pop();
    Litterale *tempLir2 = lirAff.top();
    lirAff.pop();
    std::string temp1Str = tempLir1->toString();
    std::string temp2Str = tempLir2->toString();
    std::string type = estQuelType(temp2Str);
    if (type == "Fraction" || type == "Rationnelle" || type == "Entiere") {
        double tempDouble = tempLir2->toDouble();
        if (tempDouble) {
            lirAff.push(tempLir1);
            Operator *tempOpt = toOperator("EVAL");
            tempOpt->Action();
            lirAff.setMessage("IFT " + temp2Str + " est vrai " + temp1Str + " effectue des calculs");
        } else
            lirAff.setMessage("IFT " + temp2Str + " est faux " + temp1Str + " abandonne");
    } else {
        lirAff.push(tempLir2);
        lirAff.push(tempLir1);
        throw std::invalid_argument("IFT " + temp2Str + " non operateur logique revenir a l'etat initial");
    }
}

void Operator_Sto::Action() {
    std::string str1 = lirAff.top()->toString();
    lirAff.pop();
    std::string str2 = lirAff.top()->toString();
    lirAff.pop();
    symbols.insert(str1.substr(1, str1.size() - 2), str2);
    lirAff.setMessage("STO " + str1 + " et " + str2 + " sonts lies");
}

void Operator_Forget::Action() {
    std::string str = lirAff.top()->toString();
    lirAff.pop();
    symbols.remove(str.substr(1, str.size() - 2));
    lirAff.setMessage("STO " + str + " association est supprimee");
}

Operator *toOperator(const std::string &s) {
    if (s == "+") return new Operator_Plus(s);
    else if (s == "-") return new Operator_Minus(s);
    else if (s == "*") return new Operator_Multi(s);
    else if (s == "/") return new Operator_Div(s);
    else if (s == "DIV") return new Operator_DivExact(s);
    else if (s == "MOD") return new Operator_Mod(s);
    else if (s == "NEG") return new Operator_Neg(s);
    else if (s == "NUM") return new Operator_Num(s);
    else if (s == "DEN") return new Operator_Den(s);
    else if (s == "POW") return new Operator_Pow(s);
    else if (s == "SIN") return new Operator_Sin(s);
    else if (s == "COS") return new Operator_Cos(s);
    else if (s == "TAN") return new Operator_Tan(s);
    else if (s == "ARCSIN") return new Operator_ArcSin(s);
    else if (s == "ARCCOS") return new Operator_ArcCos(s);
    else if (s == "ARCTAN") return new Operator_ArcTan(s);
    else if (s == "SQRT") return new Operator_Sqrt(s);
    else if (s == "EXP") return new Operator_Exp(s);
    else if (s == "LN") return new Operator_Ln(s);
    else if (s == "=") return new Operator_Equal(s);
    else if (s == "!=") return new Operator_NotEqual(s);
    else if (s == "<=") return new Operator_LE(s);
    else if (s == ">=") return new Operator_HE(s);
    else if (s == "<") return new Operator_Lesser(s);
    else if (s == ">") return new Operator_Higher(s);
    else if (s == "AND") return new Operator_And(s);
    else if (s == "OR") return new Operator_Or(s);
    else if (s == "NOT") return new Operator_Not(s);
    else if (s == "EVAL") return new Operator_Eval(s);
    else if (s == "DUP") return new Operator_Dup(s);
    else if (s == "DROP") return new Operator_Drop(s);
    else if (s == "SWAP") return new Operator_Swap(s);
    else if (s == "CLEAR") return new Operator_Clear(s);
//    else if (s == "UNDO") return "Undo";
//    else if (s == "REDO") return "Redo";
    else if (s == "IFT") return new Operator_Ift(s);
//    else if (s == "IFTF") return "Iftf";
//    else if (s == "WHILE") return "While";
    else if (s == "STO") return new Operator_Sto(s);
    else if (s == "FORGET") return new Operator_Forget(s);
    else throw std::logic_error("Erreur de saisie");
}

std::tuple<double, std::string> getOneSetData(Pile &lirAff) {
    double v1 = lirAff.top()->toDouble();
    std::string str1 = lirAff.top()->toString();
    lirAff.pop();
    return {v1, str1};
}

std::tuple<double, double, std::string, std::string> getTwoSetData(Pile &lirAff) {
    double v1 = lirAff.top()->toDouble();
    std::string str1 = lirAff.top()->toString();
    lirAff.pop();
    double v2 = lirAff.top()->toDouble();
    std::string str2 = lirAff.top()->toString();
    lirAff.pop();
    return {v1, v2, str1, str2};
}

void fromExpressionToSymbol(const std::string &s, Pile &lirAff) {
    auto temp = getSymbol(s.substr(1, s.size() - 2));
    std::string newType = estQuelType(temp);
    lirAff.push(toLitterale(temp));
    if (newType == "Programme") {
        Operator *opt = toOperator("EVAL");
        opt->Action();
    }
}
