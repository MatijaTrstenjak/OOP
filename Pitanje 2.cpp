#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Proizvod {
protected:
    string naziv;
    double cijena;

public:
    Proizvod(string _naziv, double _cijena) : naziv(_naziv), cijena(_cijena) {}

    virtual void print() const = 0;

    virtual double getKoefKvalitete() const = 0;

    double getCijena() const {
        return cijena;
    }
};

class LegoIgracka : public Proizvod {
private:
    int brKomada;

public:
    LegoIgracka(string _naziv, double _cijena, int _brKomada) : Proizvod(_naziv, _cijena), brKomada(_brKomada) {}

    void print() const override {
        cout << "Lego igracka: " << naziv << ", Cijena: " << cijena << ", Broj komada: " << brKomada << endl;
    }

    double getKoefKvalitete() const override {
        return brKomada / cijena;
    }
};

class Automobil : public Proizvod {
private:
    int godProizvodnje;
    double maxBrzina;

public:
    Automobil(string _naziv, double _cijena, int _godProizvodnje, double _maxBrzina) : Proizvod(_naziv, _cijena), godProizvodnje(_godProizvodnje), maxBrzina(_maxBrzina) {}

    void print() const override {
        cout << "Automobil: " << naziv << ", Cijena: " << cijena << ", Godina proizvodnje: " << godProizvodnje
            << ", Maksimalna brzina: " << maxBrzina << endl;
    }

    double getKoefKvalitete() const override {
        return 1.0 / (2024 - godProizvodnje) * maxBrzina / 100.0 * cijena / 100000.0;
    }
};

int main() {
    vector<Proizvod*> vp = {
            new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756),
            new Automobil("BMW", 51230, 2013, 207.34),
            new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
            new Automobil("Yugo 45", 14500, 1988, 127.88),
    };

    for (int i = 0; i < vp.size(); i++) {
        vp[i]->print();
    }

    double maxKoef = 0.0;
    Proizvod* najkvalitetnijiProizvod = nullptr;
    for (int i = 0; i < vp.size(); i++) {
        if (vp[i]->getKoefKvalitete() > maxKoef) {
            maxKoef = vp[i]->getKoefKvalitete();
            najkvalitetnijiProizvod = vp[i];
        }
    }

    if (najkvalitetnijiProizvod != nullptr) {
        cout << "\nProizvod s najvecim koeficijentom kvalitete: ";
        najkvalitetnijiProizvod->print();
        cout << "Koeficijent kvalitete: " << maxKoef << endl;
    }
    else {
        cout << "\nNema dostupnih proizvoda." << endl;
    }

    for (int i = 0; i < vp.size(); i++) {
        delete vp[i];
    }

    return 0;
}
