/*
Definirajte klasu Tekst koja predstavlja tekstualni tip podatka (kao string), s
tim da podrzava operacije *, - i +:
- operacija * umnozava tekst. Na primjer, ako je x = "abc" onda x * 3 daje novi
objekt tipa Tekst koji sadrzi tekst "abcabcabc". Ova operacija mora raditi i
kada je broj s lijeve strane, to jest x * 3 treba davati isti rezultat kao i
3 * x
- operacija - uklanja zadani znak iz teksta. Na primjer, ako je x = "uvala"
onda x - 'a' daje novi objekt tipa Tekst koji sadrzi tekst "uvl", to jest
bez slova 'a'
- operacija + spaja dva teksta u jedan novi tekst. Na primjer, ako je x = "ab"
i y = "cd", onda x + y daje novi objekt tipa Tekst koji sadrzi tekst "abcd"
- treba redefinirati i operator << da radi s objektima tipa Tekst

Ovu klasu treba definirati tako da funkcija main radi kako je ispod prikazano.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Tekst {
public:
    char* tekst;

    Tekst() = default;

    Tekst(const char* s) {
        tekst = new char[strlen(s) + 1];
        strcpy(tekst, s);

    };
    ~Tekst() {
        tekst = nullptr;
    }

    Tekst operator*(int br) const {
        char* result = new char[strlen(tekst) * br + 1];
        strcpy(result, tekst);
        for (int i = 1; i < br; ++i) {
            strcat(result, tekst);
        }

        return Tekst(result);
    }

    Tekst operator +(Tekst t) {
        char* result = new char[strlen(tekst) + strlen(t.tekst)];
        strcpy(result, tekst);
        strcat(result, t.tekst);

        return Tekst(result);
    }

    Tekst operator -(char a) {
        char* result = new char[strlen(tekst)];
        int brojac = 0;
        for (int i = 0; i < strlen(tekst); i++) {
            if (tekst[i] != a)
                result[brojac++] = tekst[i];
        }

        result[brojac] = '\0';

        return Tekst(result);
    }

};

Tekst operator*(int br, const Tekst& t) {
    return t * br;
}

ostream& operator <<(ostream& izlaz, Tekst t) {

    for(int i = 0; i < strlen(t.tekst); i++)
        izlaz << t.tekst[i];

    return izlaz;
}

int main()
{
    Tekst t = "abc";
    cout << t.tekst << endl;

    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    //// p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
}

