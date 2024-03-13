#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 


using namespace std;



class CPredmet {
public:
	string opis;
	int kolicina;

	CPredmet(string _opis, int _kolicina) : opis(_opis), kolicina(_kolicina) {};

	CPredmet() {};
};

class CPlaza {
public:
	int velicina;
	double x_kord, y_kord;
	vector<CPredmet> Predmeti;

	CPlaza(int _velicina, double _x_kord, double _y_kord) : velicina(_velicina), x_kord(_x_kord), y_kord(_y_kord) {};

	void dodajPredmet(CPredmet pr) { this->Predmeti.push_back(pr); }
};

int main()
{
	int n, m;
	vector<CPlaza> Plaze;

	cout << "Unesite broj plaza: (N):";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int vel;
		double x, y;
		
		cout << "Unesite velicinu i lokaciju za " << i + 1 << ". plazu:" << endl;
		cin >> vel;
		cin >> x >> y;

		Plaze.push_back(CPlaza(vel, x, y));
	}

	cout << "Unesite broj predmeta (M):";
	cin >> m;

	for (int i = 0; i < m; i++) {
		int pripada, kol;
		string op;

		cout << "Unesite redni broj plaze kojoj pripada " << i + 1 << ".predmet:";
		cin >> pripada;

		cout << "Unesite kolicinu i opis predmeta: ";
		cin >> kol >> op;

		CPredmet predmet(op, kol);
		Plaze[pripada - 1].dodajPredmet(predmet);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d. %lf %lf D=%d - predmeti: ", (i + 1), Plaze[i].x_kord, Plaze[i].y_kord, Plaze[i].velicina);
		//cout << i + 1 << ". " << Plaze[i].x_kord << " " << Plaze[i].y_kord << " D=" << Plaze[i].velicina << " - predmeti: ";

		for (size_t j = 0; j < Plaze[i].Predmeti.size(); j++)
			cout << Plaze[i].Predmeti[j].kolicina << " " << Plaze[i].Predmeti[j].opis << " ";

		cout << endl;
	}
	return 0;
}

