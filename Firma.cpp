#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Zaposlenik{
public:
	string ime;
	string prezime;
	int broj_godina;

	Zaposlenik(string _ime, string prezime_) : ime(_ime), prezime(prezime_) {
		cout << "Zaposlenik constructor called" << endl;
	}

	~Zaposlenik() {
		cout << "Zaposlenik destructor called" << endl;
	}
};


class Firma{
public:
	string ime;
	string oib;
	string adresa;
	vector<Zaposlenik> vZaposlenici;

	Firma(string _ime, string _oib, string _adresa) {
		if (_ime.length() >= 5)
			ime = _ime;
		else
			cout << "Ime ima premalo znakova, minimalni broj znakova je 5!" << endl;
		

		if (provjeriOIB(_oib))
			oib = _oib;
		else
			cout << "OIB nije valjan!" << endl;

	}

	void dodajZaposlenika1(Zaposlenik z);
	void dodajZaposlenika2(Zaposlenik& z);
	void dodajZaposlenika3(Zaposlenik* z);
	void ispisSvihZaposlenika();
	Zaposlenik nadjiZaposlenika1(string ime, string prezime);
	Zaposlenik* nadjiZaposlenika2(string ime, string prezime);
	//Zaposlenik& nadjiZaposelnika3(string ime, string prezime);

private:
	bool provjeriOIB(string _oib) {
		if (_oib.length() != 11)
			return 0;
		
		for (int i = 0; i < _oib.length(); i++)
			if (_oib[i] < '0' || _oib[i] > '9')
				return 0;

		return 1;
	}
};

void Firma::dodajZaposlenika1(Zaposlenik z) {
	vZaposlenici.push_back(z);
}

void Firma::dodajZaposlenika2(Zaposlenik& z) {
	vZaposlenici.push_back(z);
}

void Firma::dodajZaposlenika3(Zaposlenik* z) {
	vZaposlenici.push_back(*z);
}

void Firma::ispisSvihZaposlenika() {
	for (int i = 0; i < vZaposlenici.size(); i++) {
		cout << vZaposlenici[i].ime << " " << vZaposlenici[i].prezime << endl;
	}
}


Zaposlenik Firma::nadjiZaposlenika1(string ime, string prezime) {
	for (int i = 0; i < vZaposlenici.size(); i++) {
		if (vZaposlenici[i].ime == ime && vZaposlenici[i].prezime == prezime) {
			vZaposlenici[i].ime = "Zaposlenik"; 
			vZaposlenici[i].prezime = "Jedan";
			return vZaposlenici[i];
		}
	}
}

Zaposlenik* Firma::nadjiZaposlenika2(string ime, string prezime){
	for (int i = 0; i < vZaposlenici.size(); i++) {
		if (vZaposlenici[i].ime == ime && vZaposlenici[i].prezime == prezime) {
			return &(vZaposlenici[i]);
		}
	}
	return nullptr;
}

//Zaposlenik& nadjiZaposelnika3(string ime, string prezime){
//	for (int i = 0; i < vZaposlenici.size(); i++) {
//		if (vZaposlenici[i].ime == ime && vZaposlenici[i].prezime == prezime) {
//			return vZaposlenici[i];
//		}
//	}
//}

int main()
{
	Firma f1("Fir", "12345678910", "Adadada");
	Firma f2("Firma", "1234567891", "Adadada");
	Firma f3("Firma", "12345678910", "Adadada");
	cout << endl;

	Zaposlenik z1("Ivan", "Horvat");
	f3.dodajZaposlenika1(z1);
	cout << endl;


	Zaposlenik z2("Marko", "Marulic");
	f3.dodajZaposlenika2(z2);
	cout << endl;


	Zaposlenik z3("Stef", "Novak");
	f3.dodajZaposlenika3(&z3);
	cout << endl;

	f3.ispisSvihZaposlenika();
	cout << endl;

	f3.nadjiZaposlenika1("Ivan", "Horvat");
	cout << endl;

	Zaposlenik* z4 = f3.nadjiZaposlenika2("Marko", "Marulic");
	z4->ime = "Sven";
	z4->prezime = "Svenic";

	cout << endl;

	//f3.nadjiZaposlenika3("Ivan", "Horvat");
	//cout << endl;

	f3.ispisSvihZaposlenika();
	cout << endl;

}

