#include "stdafx.h"
#include "css.h"
#include "CMastermind.h"
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

/*CMastermind - 2020
	- Projet BTS SN/IR
	
	TO DO:
		- Corriger le beug "OUT OF RANGE" (Toujour une erreur avec certaines propositions, exemple: "000000")
		- Rajouter plus de couleur 
		- Optimiser et rendre le code plus ergonomique 
*/


int main()
{
	int chx, essai;
	bool state = false;
	
	header();

	CMastermind Partie; 

	cout << "Bienvenue dans MasterMind V0.1.\nCe jeux en version CMD est une copie du jeu mastermind officiel.\n\n";
	cout << "Menu : " << "1) Jouer	2) Regles  3) Sortie" << endl;

	cin >> chx;

	switch (chx)
	{
	case(1):
		cout << "Voulez vous definir vos propres parametres (1) ou jouer en normal (2) : ";
		cin >> chx;
		switch (chx)
		{
		case(1):
			cout << "Veuillez choisir une solution : " << endl;
			cout << "Taille de code (Max 6) : ";
			cin >> chx;
			cout << "Nombre d'essais max : ";
			cin >> essai;
		
			while (chx > 6)
			{
				cout << "La taille du code est superieure a 6.\nVeuillez saisir un nouveau nombre : ";
				cin >> chx;
			}

			Partie.m_modifie(chx, essai);
			cout << endl;
			break;
		default:
			chx = 6;
			cout << "La partie vient d\'etre genere en mode normal (6 chiffres/8 essais)" << endl;
			Partie.choisirSolution();
			break;
		}

		do
		{
			cout << "Veuillez saisir votre proposition :";
			cin >> essai;

			while (to_string(essai).size() > chx) //Pour essayer de contrer l'erreur "OUT OF RANGE" 
			{
				cout << "Le code entre n'a pas la meme taille que le code genere : " << chx << ".\nVeuillez saisir un nouvel essai : ";
				cin >> chx;
			}

			Partie.saisirEssai(essai);
			state = Partie.get_m_fini();
		} while (state == false);

		system("PAUSE");
		system("CLS");

		break;
	case(2):
		Partie.usage();
		break;
	case(3):
		color(4);
		cout << "Quitting" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		color(7);
		return 0;
	default:
		break;
	}

	system("CLS"); //Peut prendre un certain temps en fonction de la machine
	main();
}

