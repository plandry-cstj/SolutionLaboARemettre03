// But : L�utilisateur a un maximum de 5 chances. Le programme v�rifie que l�utilisateur a bien entr� un nombre entre 0 et
//		 100 et lui indique s�il gagne ou dans le cas contraire lui indique le nombre d�essais restant et lui redemande un nombre.
// Auteur : Pierre-Olivier Landry
// Date : 2020-10-04

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int iRandom;				// Permet de m�moriser le nombre choisi al�atoirement par l'ordinateur
	int nombre;
	int chances = 5;

	srand(time(0));				// Pour activer l'al�atoire dans le programme
	iRandom = rand() % 101;		// L'ordinateur calcule un nombre al�atoire entre 0 et 100 et le stocke dans iRandom

	// Le programme lit le nombre entr� par l'utilisateur
	cout << "Hey ! Je pense � un nombre entre 0 et 100. Essaie de le deviner, tu as 5 chances." << endl ;
	cin >> nombre;

	// Le nombre entr� est plus petit que 0 ou plus grand que 100
	while (nombre < 0 || nombre > 100)
	{
		cout << "\nErreur ! Tu dois entrer un nombre entre 0 et 100" << endl;
		cin >> nombre;
	}

	chances--;

	while (nombre != iRandom && chances > 0)
	{
		if (nombre < iRandom)
		{
			// Le nombre entr� est plus petit que 0 ou plus grand que 100
			while (nombre < 0 || nombre > 100)
			{
				cout << "\nErreur ! Tu dois entrer un nombre entre 0 et 100" << endl;
				cin >> nombre;
			}

			// Le nombre entr� est plus petit que iRandom
			cout << "\nTon nombre est trop petit." << endl;
			cin >> nombre;
			chances--;
		}
		else
		{
			// Le nombre entr� est plus grand que iRandom
			cout << "\nTon nombre est trop grand." << endl ;
			cin >> nombre;
			chances--;
		}
	}

	if (chances <= 0)
	{
		cout << "\nMalheureusement tu as utilis� toutes tes chances." << " Le nombre auquel je pensais �tait " << iRandom << endl;
	}

	// Le nombre entr� est pareil que iRandom
	if (nombre == iRandom)
	{
		cout << "Bravo ! Je pensais bien � " << iRandom << "." << endl;
	}

	return 0;
}


/* Plan de tests

nombre				iRandom				Texte affich�
20					4					Ton nombre est trop grand.
78					98					Ton nombre est trop petit.
200					65					Erreur. Tu dois entrer un nombre entre 0 et 100
-298				27					Erreur. Tu dois entrer un nombre entre 0 et 100
*/