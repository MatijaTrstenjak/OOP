/*
Neka je zadana sljedeća funkcija "main":

int main() {
    try {
        test(2);
        cout << "nastavak try-bloka...\n";
    } catch (const PrevelikBroj& e) {
        cout << e.poruka() << endl;
    } catch (const PremaliBroj& e) {
        cout << e.poruka() << endl;
    } catch (...) {
        cout << "... neka druga greska!";
    }

    cout << "nastavak main funkcije\n";
}

Nadopunite ovaj program tako da pokretanje funckije "main" daje sljedeći ispis:

pocetak testa
pocetak primjera
prevelik broj
nastavak main funkcije
*/




#include <iostream>
using namespace std;

class PrevelikBroj
{
public:
    const string poruka() const {
        return "prevelik broj";
    }
};
class PremaliBroj
{
public:
    const string poruka() const {
        return "premali broj";
    }
};


void test(int a) {
    cout << "pocetak testa" << endl;
    cout << "pocetak primjera" << endl;

    if (a > 1)
        throw PrevelikBroj();

    else if (a < 1)
        throw PremaliBroj();
}


int main() {
    try {
        test(1);
        cout << "nastavak try-bloka...\n";
    }
    catch (const PrevelikBroj& e) {
        cout << e.poruka() << endl;
    }
    catch (const PremaliBroj& e) {
        cout << e.poruka() << endl;
    }
    catch (...) {
        cout << "... neka druga greska!";
    }

    cout << "nastavak main funkcije\n";
}
