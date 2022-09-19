#include "stdafx.h"
#include "css.h"

void color(int m_Color)
{
	HANDLE  hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, m_Color);
}

void color_phrase(int m_Color, string m_phrase)
{
	color(m_Color);

	cout << m_phrase << endl;

	color(7);
}

void header()
{
	cout << R"( _____         _           _____ _       _  )"; color(6); cout << R"(  _____ ___   ___   )" << endl; color(7);
	cout << R"(|     |___ ___| |_ ___ ___|     |_|___ _| | )"; color(6); cout << R"( |  |  |   | |_  | )" << endl; color(7);
	cout << R"(| | | | .'|_ -|  _| -_|  _| | | | |   | . | )"; color(6); cout << R"( |  |  | | |_ _| |_)" << endl; color(7);
	cout << R"(|_|_|_|__,|___|_| |___|_| |_|_|_|_|_|_|___| )"; color(6); cout << R"(  \___/|___|_|_____|)" << endl; color(7);
	cout << R"(                                                                )" << endl;
	cout << endl;
	cout << R"([--------------------------------------------------------------])" << endl;
	cout << endl;
}