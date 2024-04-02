#include <iostream>
#include <vector>
#include <string.h>
#include "Matrica.h"

using namespace std;

int main()
{
	Matrica m;
	m.dodaj(3, new int[3] { 1, 6, 2 });  // dodaj novi redak od 3 stupca
	m.dodaj(5, new int[5] { 5, 3, 4, 7, 0 });
	m.dodaj(4, new int[4] { 6, 2, 6, 5 });
	m.ispis();// ispis matrice redak po redak
}


