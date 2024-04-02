#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Matrica {
public:
    vector<int*> redak; // svaki redak matrice je pokazivac na niz
    vector<int> stupac; // broj stupaca za svaki redak matrice

    void dodaj(int brStupaca, int* _redak); // dodaje novi redak matrici
    Matrica() {}
    Matrica(const Matrica& m);
    Matrica& operator = (const Matrica& m);
    Matrica(Matrica&& m);
    void ispis();
    ~Matrica();
};

