#pragma once
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

class  CMastermind {
public:
	CMastermind();

	CMastermind(int m_taille_code, int m_nb_essaiMax);

	void usage();

	void choisirSolution();

	void saisirEssai(int m_essai);

	void verifierEssai();

	void AfficherResultat();

	bool get_m_fini();
private:
	string m_secret;
	string m_essai;
	string m_code = "      ";
	int m_nb_essais = 0;
	int m_nb_essaisMax = 8;
	bool m_fini = false;
	int m_taille_code = 6;
};