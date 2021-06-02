#include "Litterale.h"

/*simplifier*/
LitteraleNumerique *LitteraleEntiere::simplifier() { return new LitteraleEntiere(this->entiere); }

LitteraleNumerique *LitteraleFraction::simplifier() {
    if (this->denominateur == 1) {
        return new LitteraleEntiere(this->numerateur);
    } else {
        return new LitteraleFraction(this->numerateur, this->denominateur);
    }
}

LitteraleNumerique *LitteraleRationnelle::simplifier() {
    if (this->partie_decimale == 0) {
        return new LitteraleEntiere(this->partie_entiere);
    } else {
        return new LitteraleRationnelle(this->partie_entiere, this->partie_decimale);
    }
}

/*constructeur*/
LitteraleFraction::LitteraleFraction(int n, int d) : numerateur(n), denominateur(d) {
    simplification();
}

LitteraleEntiere::LitteraleEntiere(int m) : entiere(m) {}

void LitteraleFraction::simplification() {
    if (numerateur == 0) {
        denominateur = 1;
        return;
    }
    int a = numerateur, b = denominateur;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    numerateur /= a;
    denominateur /= a;
    if (denominateur < 0) {
        denominateur = -denominateur;
        numerateur = -numerateur;
    }
}

/*tostring*/
std::string LitteraleRationnelle::toString() {
    return std::to_string(this->partie_entiere) + "." + std::to_string(this->partie_decimale);
}

std::string LitteraleProgramme::toString() {
    std::stringstream ss;
    std::string str_all;
    for (auto a : this->elements) {
        ss << a->toString() << " ";
    }
    str_all = ss.str();
    size_t num_last_not_space = str_all.find_last_not_of(' ');
    str_all.erase(num_last_not_space + 1);
    return "[ " + str_all + " ]";
}

/*litteralsymbol operateur de map*/
LitteraleSymbol *LitteraleSymbol::instance = nullptr;

LitteraleSymbol &LitteraleSymbol::getInstance() {
    if (instance == nullptr) instance = new LitteraleSymbol();
    return *instance;
}

void LitteraleSymbol::insert(const std::string &a, const std::string &b) {
    symbolTable.insert(std::map<std::string, std::string>::value_type(a, b));
}

void LitteraleSymbol::remove(const std::string &a) {
    auto iter = symbolTable.find(a);
    if (iter != symbolTable.end()) symbolTable.erase(iter);
}

std::string getSymbol(const std::string &a, LitteraleSymbol &LS) {
    auto iter = LS.symbolTable.find(a);
    return iter->second;
}

bool estExist(const std::string &a, LitteraleSymbol &LS) {
    auto iter = LS.symbolTable.find(a);
    return !(iter == LS.symbolTable.end());
}

/*litteralprogramme operateur de list*/
LitteraleProgramme::LitteraleProgramme(std::string programme) {
    for (unsigned int i = 1; i < programme.size() && programme[i] != ']'; i++) {
        if (programme[i] == ' ')
            continue;
        else if (programme[i] == '[') {
            unsigned int j = 0;
            while (programme[i + j] != ']') j++;
            elementsPushBack(new LitteraleProgramme(programme.substr(i, j + 1)));
            i += j;
        } else {
            unsigned int j = 0;
            while (programme[i + j] != ' ') j++;
            elementsPushBack(toLitterale(programme.substr(i, j)));
            i += (j - 1);
        }
    }
}

Litterale *LitteraleProgramme::getFirstElement() {
    Litterale *temp = elements.front();
    elements.pop_front();
    return temp;
}

unsigned int LitteraleProgramme::getLength() { return elements.size(); }

void LitteraleProgramme::elementsPushBack(Litterale *newlitterale) {
    this->elements.push_back(newlitterale);
}

/*toDouble*/
double LitteraleEntiere::toDouble() const { return static_cast<double>(this->entiere); }

double LitteraleFraction::toDouble() const {
    return static_cast<double>(this->numerateur) / static_cast<double>(this->denominateur);
}

double LitteraleRationnelle::toDouble() const {
    std::stringstream ss;
    int size_decimale;
    std::string str_decimale;
    ss << this->partie_decimale;
    ss >> str_decimale;
    size_decimale = str_decimale.size();
    return this->partie_entiere + this->partie_decimale * pow(10, -size_decimale);
}

/*toNumerique*/
LitteraleNumerique *toNumerique(double num_double) {
    if (num_double == static_cast<int>(num_double))
        return new LitteraleEntiere(static_cast<int>(num_double));
    bool sign = true;
    if (num_double < 0) {
        num_double = -num_double;
        sign = false;
    }
    std::stringstream ss;
    int num_partie_entiere;
    int num_mantisse;
    char ch;
    ss << num_double;
    ss >> num_partie_entiere >> ch >> num_mantisse;
    if (!sign) {
        num_partie_entiere = -num_partie_entiere;
    }
    std::string str_mantisse = std::to_string(num_mantisse);
    if (str_mantisse.length() > 3)
        return LitteraleRationnelle(num_partie_entiere, num_mantisse).simplifier();
    else {
        int n = num_partie_entiere;
        int d = 1;
        for (unsigned int i = 0; i < std::to_string(num_mantisse).length(); i++) {
            std::string temp(1, str_mantisse[i]);
            n = n * 10 + std::stoi(temp);
            d *= 10;
        }
        return LitteraleFraction(n, d).simplifier();
    }
}

LitteraleNumerique *getFraction(int n, int d) { return new LitteraleFraction(n, d); }

Litterale *toLitterale(const std::string &s) {
    std::string type = estQuelType(s);
    LitteraleFactory* lirFac = nullptr;
    if (type == "Programme")
        lirFac = new LitteraleProgrammeFactoty();
    else if (type == "Expression")
        lirFac = new LitteraleExpressionFactoty();
    else if (type == "Symbol") {
        lirFac = new LitteraleSymbolFactoty();
    } else if (type == "OperateurNotParameter" || type == "OperateurUnaire" ||
               type == "OperateurBinaire")
        lirFac = new LitteraleAtomeFactoty();
    else if (type == "Fraction") {
        lirFac = new LitteraleFractionFactoty();
    } else if (type == "Rationnelle") {
        lirFac = new LitteraleRationnelleFactoty();
    } else if (type == "Entiere") {
        lirFac = new LitteraleEntiereFactoty();
    } else
        throw std::invalid_argument("erreur de saisie");
    return lirFac->FactoryMethod(s);
}

std::string estQuelType(const std::string &s) {
    if (s.find('[') != std::string::npos)
        return "Programme";
    else if (s.find('\"') != std::string::npos)
        return "Expression";
    else if (estExist(s))
        return "Symbol";
    else if (estUnOperateurNotParameter(s))
        return "OperateurNotParameter";
    else if (estUnOperateurUnaire(s))
        return "OperateurUnaire";
    else if (estUnOperateurBinaire(s))
        return "OperateurBinaire";
    else if (s.find('/') != std::string::npos)
        return "Fraction";
    else if (s.find('.') != std::string::npos)
        return "Rationnelle";
    else if ((std::stod(s) - int(std::stod(s))) == 0)
        return "Entiere";
    else
        throw std::invalid_argument("erreur de saisie");
}

bool estUnOperateurNotParameter(const std::string &s) {
    if (s == "DUP") return true;
    if (s == "DROP") return true;
    if (s == "SWAP") return true;
    if (s == "CLEAR") return true;
    if (s == "UNDO") return true;
    if (s == "REDO") return true;
    if (s == "IFT") return true;
    if (s == "IFTF") return true;
    if (s == "WHILE") return true;
    return false;
}

bool estUnOperateurUnaire(const std::string &s) {
    if (s == "NEG") return true;
    if (s == "SQRT") return true;
    if (s == "EXP") return true;
    if (s == "LN") return true;
    if (s == "COS") return true;
    if (s == "SIN") return true;
    if (s == "TAN") return true;
    if (s == "ARCSIN") return true;
    if (s == "ARCCOS") return true;
    if (s == "ARCTAN") return true;
    if (s == "NUM") return true;
    if (s == "DEN") return true;
    if (s == "NOT") return true;
    if (s == "EVAL") return true;
    if (s == "FORGET") return true;
    return false;
}

bool estUnOperateurBinaire(const std::string &s) {
    if (s == "+") return true;
    if (s == "-") return true;
    if (s == "*") return true;
    if (s == "/") return true;
    if (s == "DIV") return true;
    if (s == "MOD") return true;
    if (s == "POW") return true;
    if (s == "=") return true;
    if (s == "!=") return true;
    if (s == "<") return true;
    if (s == ">") return true;
    if (s == "<=") return true;
    if (s == ">=") return true;
    if (s == "AND") return true;
    if (s == "OR") return true;
    if (s == "STO") return true;
    return false;
}
