// tablica mnozenja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

void zaglavlje();
void vodoravnacrta(int duljina);
void tablicamnozenja(int brojac);

const char oCrta = 179;
const char vCrta = 196;
int broj;
int maxumnozak;
int umnozakduljina;
string umnozak;
string crta;
string soCrta;
ostringstream convert;

int main()
{
	do
	{
		cout << "Unesi broj od 1 do 18: ";
		cin >> broj;
		cout << endl;
	} while (broj > 18 || broj < 1);

	vodoravnacrta(broj);
	tablicamnozenja(broj);
	getchar();
	return 0;
}

void vodoravnacrta(int duljina)
{
	convert.str("");
	convert << char(vCrta);
	soCrta = convert.str();
	
	convert.str("");
	convert << dec << (duljina*duljina);
	umnozak = convert.str();
	umnozakduljina = umnozak.size();
	for (int i = 1; i <= duljina*(umnozakduljina+1)+maxumnozak+2+umnozakduljina; i++)
	{
		crta.insert(0, soCrta);
	}
}

void zaglavlje()
{
	cout << crta << endl;

	convert.str("");
	convert << dec << (broj*broj);
	umnozak = convert.str();
	maxumnozak = umnozak.size();
	for (int i = 1; i <= maxumnozak+1; i++) cout << " ";
	for (int i = 1; i <= broj; i++)
	{
		convert.str("");
		convert << std::dec << i;
		umnozak = convert.str();
		umnozakduljina = umnozak.size();
		while (umnozakduljina < maxumnozak)
		{
			umnozak.insert(0, " ");
			umnozakduljina++;
		}		
		cout << oCrta << umnozak;
	}
	cout << oCrta << endl << crta << endl;
}

void tablicamnozenja(int brojac)
{
	zaglavlje();
	for (int a = 1; a <= brojac; a++)
	{
		convert.str("");
		convert << std::dec << a;
		umnozak = convert.str();
		umnozakduljina = umnozak.size();
		while (umnozakduljina < maxumnozak)
		{
			umnozak.insert(0, " ");
			umnozakduljina++;
		}
		cout << oCrta << umnozak;
		for (int b = 1; b <= brojac; b++)
		{
			convert.str("");
			convert << std::dec << (a*b);
			umnozak = convert.str();
			umnozakduljina = umnozak.size();
			while (umnozakduljina < maxumnozak)
			{
				umnozak.insert(0, " ");
				umnozakduljina++;
			}
			cout << oCrta << umnozak;
		}
		cout << oCrta << endl << crta << endl;
	}

}
