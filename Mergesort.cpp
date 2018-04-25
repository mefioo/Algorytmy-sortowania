#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <Windows.h>

using namespace std;

void scalanie(int* tab, int poczatek, int koniec)
{
	if (koniec - poczatek>0)
	{
		scalanie(tab, poczatek, (koniec - poczatek) / 2 + poczatek);
		scalanie(tab, (koniec - poczatek) / 2 + poczatek + 1, koniec);
	}

	int p = poczatek, k = koniec, i=0, srodek = (koniec - poczatek) / 2 + poczatek, j=srodek+1;
	int *pom = new int[k - p + 1];

	///
	i = 0;
	if (koniec - poczatek != 0)
	{
		while (p != srodek + 1 || j != koniec + 1)
		{
			if (p != srodek + 1 && j != koniec + 1)
			{
				if (tab[p] < tab[j])
				{
					pom[i] = tab[p];
					p++;
				}
				else
				{
					pom[i] = tab[j];
					j++;
				}
			}
			else
			{
				if (p == srodek + 1 && j == koniec + 1)
					break;
				if (p == srodek + 1)
				{
					pom[i] = tab[j];
					j++;
				}
				else
				{
					pom[i] = tab[p];
					p++;
				}
			}
			i++;
		}

		///
		j = poczatek;
		for (i = 0; i <= koniec - poczatek; i++)
		{
			tab[j] = pom[i];
			j++;
		}
		delete[] pom;
	}
};



int main()
{
	srand(time(NULL));
	int n = 1000000, liczba, i, j;
	int *tab = new int[n];

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < n ; i++)
		{
			liczba = n-i;
			tab[i] = liczba;
//			cout << tab[i] << endl;
		}
//		for (i = 0; i < n; i++)
//	{
//			liczba = rand();
//			tab[i] = liczba;
//			//	cout << tab[i] << endl;
//		}
		cout << endl;
		DWORD start = GetTickCount();
		scalanie(tab, 0, n - 1);
		DWORD stop = GetTickCount();
		cout << stop - start << endl;
	}
//	cout << endl << endl << "Posortowane: "<<endl;
	for (i = 0; i<n; i++)
	{
	//	cout << tab[i] << endl;
	}
	cin >> n;
	delete []tab;
	return 0;
}