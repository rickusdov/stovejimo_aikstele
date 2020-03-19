// olimpiada_aikstele_2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

const int riba = 5000;

struct Duomenys
{
	int laikas;
	int numeris;
	int rezultatas_laikas;
	int rezultatas_numeris;
};
Duomenys d[riba];

void skaitymas(int& n, Duomenys d[]);
void skaiciavimas(int n, Duomenys d[], int& m);
void rikiavimas(int n, Duomenys d[], int m, int& k);
void isvedimas(int k, Duomenys d[]);

int main()
{
	int n, m, k;
		skaitymas(n, d);
		skaiciavimas(n, d, m);
		rikiavimas(n, d, m, k);
		isvedimas(k, d);
}
void skaitymas(int& n, Duomenys d[])
{
	ifstream fd("duom.txt");
	fd >> n;
	for (int i = 1; i <= n; i++)
	{
		fd >> d[i].laikas >> d[i].numeris;
	}

}
void skaiciavimas(int n, Duomenys d[], int & m)
{
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		d[i].rezultatas_laikas = 0;
		for (int j = 1; j <= n; j++)
		{
			if (d[i].numeris == d[j].numeris && i != j)
			{

				d[i].rezultatas_laikas = d[j].laikas - d[i].laikas;
				d[i].rezultatas_numeris = d[i].numeris;
				
				
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i].rezultatas_laikas > 0)
		{
			m++;
			d[m].rezultatas_laikas = d[i].rezultatas_laikas;
			d[m].rezultatas_numeris = d[i].rezultatas_numeris;
			
		}
		
	}
	
}
void rikiavimas(int n, Duomenys d[], int m, int & k)
{
	k = 0;
	bool rikiuote = true;
	int laikinas_numeris[riba];
	int laikinas_laikas[riba]; // laikini kintamieji atrusiavimui
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i].numeris == d[j].numeris && i != j)
			{
				if (d[i].laikas < d[j].laikas)
				{
					k++;
					laikinas_numeris[k] = d[j].numeris;
					laikinas_laikas[k] = d[j].laikas;
					d[k].rezultatas_laikas = d[j].laikas - d[i].laikas;
				}
			}
		}
	}

	while (rikiuote)
	{
		rikiuote = false;
		for (int i = 1; i <= k-1; i++)
		{
			if (laikinas_laikas[i] > laikinas_laikas[i + 1])
			{
				swap(laikinas_laikas[i], laikinas_laikas[i + 1]);
				swap(laikinas_numeris[i], laikinas_numeris[i + 1]);
				swap(d[i].rezultatas_laikas, d[i + 1].rezultatas_laikas);
				rikiuote = true;
			}
		}
	}
	for (int i = 1; i <= k; i++)
	{
		d[i].rezultatas_numeris = laikinas_numeris[i];
	}

}
void isvedimas(int k, Duomenys d[])
{
	ofstream out("rez.txt");
	for (int i = 1; i <= k; i++)
	{
		out << d[i].rezultatas_numeris << " " << d[i].rezultatas_laikas << endl;
	}
}
