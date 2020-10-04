// But : Développer un programme qui entre les ventes brutes hebdomadaires de chaque représentant et qui calcule et
//		 affiche son salaire. Si l'utilisateur entre -1 il quitte le programme.
// Auteur : Pierre-Olivier Landry
// Date : 2020-10-03

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	// Déclaration des variables
	const int salaireSemaine = 250;
	int salaireTotal;
	int ventes;
	int prime;

	// L'utilisateur entre le total de ses ventes ou -1
	cout << "Veuillez entrer votre total des ventes (ou -1 pour quitter) : ";
	cin >> ventes;

	while (ventes < -1)
	{
		cout << "Erreur ! Vous ne pouvez pas entrer de nombres négatifs" << endl;
		cin >> ventes;
	}

	if (ventes == -1)
	{
		exit(0);
	}

	while (ventes != -1)
	{
		// Le programme calcule le 7.5%
		prime = ventes * 0.075;
		// Le programme calcule le salaire avec le 7.5%
		salaireTotal = salaireSemaine + prime;

		// Le programme affiche le salaire total hebdomadaire
		cout << "Votre salaire hebdomadaire est de " << salaireTotal << "$" << endl;

		// La boucle recommence
		cout << "\nVeuillez entrer votre total des ventes (ou -1 pour quitter) : ";
		cin >> ventes;
	}

	return 0;
}


/* Plan de tests

Total des ventes			Salaire/Texte affiché
2000$						400$
5000$						625$
-1500						Erreur ! Vous ne pouvez pas entrer de nombres négatifs
*/