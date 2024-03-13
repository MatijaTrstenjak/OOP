#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Artikl {
public:
	string naziv;
	float kolicina, jedinicna_cijena;

	Artikl(string _naziv, float _kolicina, float _jedinicna_cijena) : naziv(_naziv), kolicina(_kolicina), jedinicna_cijena(_jedinicna_cijena) {};

	Artikl() {};

};

class Racun {
public:
	int broj_racuna;
	float ukupnaCijena = 0;
	vector<Artikl> Artikli;
	
	
	Racun(int br) : broj_racuna(br) {};
	Racun() {};

	void dodaj(Artikl artikl) 
	{ 
		this->Artikli.push_back(artikl); 
		ukupnaCijena += artikl.kolicina * artikl.jedinicna_cijena;
	}

	void najskupljiArtikl() {
		Artikl najskuplji("", 0, 0);

		for (int i = 0; i < this->Artikli.size(); i++) {
			if (this->Artikli[i].jedinicna_cijena * this->Artikli[i].jedinicna_cijena > najskuplji.jedinicna_cijena * najskuplji.kolicina)
				najskuplji = Artikli[i];
		}

		cout << "Najskuplje placeni artikl je " << najskuplji.naziv << "(" << najskuplji.kolicina * najskuplji.jedinicna_cijena << "kn)" << endl;
	}


};

class Kupac {
public:

	Racun racun;

	Kupac(Racun _racun) {
		racun.broj_racuna = _racun.broj_racuna;
	}
};



int main()
{
	Kupac Ante(Racun(1)); // Ante ima racun broj 1

	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg

	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg

	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca

	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

	Ante.racun.najskupljiArtikl();


}
