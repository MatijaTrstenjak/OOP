#include "Matrica.h"

void Matrica::dodaj(int brStupaca, int* _redak) {
    int* noviRedak = new int[brStupaca];
    for (int i = 0; i < brStupaca; ++i) {
        noviRedak[i] = _redak[i];
    }
    redak.push_back(noviRedak);
    stupac.push_back(brStupaca);
}

void Matrica::ispis() {
    for (size_t i = 0; i < redak.size(); ++i) {
        for (int j = 0; j < stupac[i]; ++j) {
            std::cout << redak[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrica::Matrica(const Matrica& m) {
    for (size_t i = 0; i < m.redak.size(); ++i) {
        dodaj(m.stupac[i], m.redak[i]);
    }
}

Matrica::Matrica(Matrica&& m) {
    redak = std::move(m.redak);
    stupac = std::move(m.stupac);
    m.redak.clear();
    m.stupac.clear();
}

Matrica::~Matrica() {
    for (size_t i = 0; i < redak.size(); ++i) {
        delete[] redak[i];
    }
}

Matrica& Matrica::operator=(const Matrica& m) {
    if (this == &m) 
        return *this;

    for (size_t i = 0; i < redak.size(); ++i) {
        delete[] redak[i];
    }
    redak.clear();
    stupac.clear();

    for (size_t i = 0; i < m.redak.size(); ++i) {
        dodaj(m.stupac[i], m.redak[i]);
    }

    return *this;
}