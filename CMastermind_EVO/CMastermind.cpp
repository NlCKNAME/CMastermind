#include "stdafx.h"
#include "CMastermind.h"
#include "css.h"


CMastermind::CMastermind()
{
	m_taille_code = 6;
	m_nb_essaisMax = 8;
};

CMastermind::CMastermind(int m_taille_code, int m_nb_essaiMax)
{
	this->m_taille_code = m_taille_code;
	this->m_nb_essaisMax = m_nb_essaiMax;
	choisirSolution();
};

void CMastermind::m_modifie(int m_taille_code, int m_nb_essaiMax)
{
	this->m_taille_code = m_taille_code;
	this->m_nb_essaisMax = m_nb_essaiMax;
	choisirSolution();
};

void CMastermind::usage()
{
	cout << "Voici les regles du jeu : \nPour commencer, il faut dans un premier temps choisir entre un mode de jeu defini par vous ou alors\navec des parametres pre-defini (Code de 6 chiffres avec 8 essais).\nVotre but est de, comme sur le vrai Mastermind, trouver le code genere par \nl'ordinateur sans depasser le nombre d'essai maximum." << endl;

	system("PAUSE"); //Peut prendre un certain temps en fonction de la machine
};

void CMastermind::choisirSolution()
{
	srand(time(NULL));

	m_secret = to_string(rand() % 999999 + 100000);
	m_secret.resize(m_taille_code);
};

void CMastermind::saisirEssai(int m_essai)
{
	this->m_essai = to_string(m_essai);
	m_nb_essais += 1;

	verifierEssai();
};

void CMastermind::verifierEssai()
{
	string memo = m_secret;
	bool trouve;

	//m_code = "      ";

	for (int i = 0; i < m_taille_code; i++)
	{
		m_code[i] = '_';
	}

	for (int i = 0; i < m_taille_code; i++)
	{
		trouve = false;
		
		for (int j = 0; (j < m_taille_code) && (trouve == false); j++)
		{
			if (m_essai[i] == memo[j])
			{
				if (i == j)
				{
					m_code[i] = 'V';
					memo[i] = '_';
				}else
				{
					m_code[i] = 'X';
					memo[i] = '_';
				}

				trouve = true;
			}
		}
	}

	if (m_secret == m_essai)
	{
		m_fini = true;
	}

	if (m_nb_essais == m_nb_essaisMax)
	{
		m_fini = true;
	}

	AfficherResultat();
};

void CMastermind::AfficherResultat()
{
	cout << "voici le resultat de votre essai : ";

	for (int i = 0; i < m_code.size(); i++)
	{
		switch (m_code[i])
		{
		case('_'):
			cout << m_code[i];
			break;
		case('V'):
			color(2);
			cout << m_code[i];
			color(7);
			break;
		case('X'):
			color(4);
			cout << m_code[i];
			color(7);
			break;
		default:
			break;
		}
	}

	cout << endl;

	cout << "Il reste : " << m_nb_essaisMax - m_nb_essais << " essai(s)." << endl;

	if (m_fini == true)
	{
		cout << "La partie est terminee." << endl;
		cout << "voici le code secret : ";
		color_phrase(2, m_secret);
	}
	else
	{
		cout << "La partie n'est pas terminee." << endl;
	}

	//cout << "voici le resultat de votre essai : " << m_code << endl;

	cout << endl;
};

bool CMastermind::get_m_fini()
{
	return m_fini;
}