#include "stdafx.h"
#include "CMastermind.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

/*CMastermind - 2020
	- Projet BTS SN/IR (Version comme demandé dans le pdf, voir version EVO pour une version plus développée)

	Présence d'une erreur "OUT OF RANGE"
*/


int main()
{
	int chx, essai;
	bool state = false;

	cout << "Veuillez choisir une solution : " << endl;
	cout << "Taille de code (Max 6) : ";
	cin >> chx;
	cout << "Nombre d'essais max : ";
	cin >> essai;

	CMastermind Partie(chx, essai);

	do
	{
		cout << "Veuillez saisir votre proposition :";
		cin >> essai;

		Partie.saisirEssai(essai);
		state = Partie.get_m_fini();

	} while (state == false);

	system("PAUSE"); //Peut prendre un certain temps en fonction de la machine
	system("CLS"); //Idem
	main();
}
