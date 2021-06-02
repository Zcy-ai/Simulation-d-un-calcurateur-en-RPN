#include "Controleur.h"

int main() {
    Controleur &controleur = Controleur::getInstance();
    while (controleur.getState())
        try {
            controleur.executer();
        } catch (std::exception &ex) {
            controleur.setException(ex.what());
        }
}