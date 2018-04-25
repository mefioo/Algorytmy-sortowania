#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <Windows.h>

using namespace std;

void Heapsort(double* tab, int ilosc)
{
	int pom = 0, i = ilosc, n, j = ilosc, licznik = ilosc;
	double *tabpom = new double[licznik];
	bool zmiana = 0;
	while(ilosc>=0)
	{
		for (i = ilosc; i >= 0; i--)  
		{
			zmiana = 0;
			j = i;
			if (i != 0)
			{
				if (i % 2 == 0)
					n = (i - 2) / 2;
				else
					n = (i - 1) / 2;
				if (tab[i] > tab[n])
				{
					pom = tab[n];
					tab[n] = tab[i];
					tab[i] = pom;
					zmiana = 1;
				}
			}
 			n = i;
			while (zmiana)
			{
				n = 2 * n + 1;
				zmiana = 0;
				if (n <= ilosc)
				{
					if (n + 1 <= ilosc)
					{
						if (tab[n] < tab[n + 1])
							n++;
						if (tab[n] > tab[j])
						{
							tab[n] = pom;
							tab[n] = tab[j];
							tab[j] = pom;
							zmiana = 1;
							if (n % 2 == 0)
								j = 2 * j + 2;
							else
								j = 2 * j + 1;
						}
					}
					else
					{
						if (tab[n] > tab[j])
						{
							tab[n] = pom;
							tab[n] = tab[j];
							tab[j] = pom;
							j = 2 * j + 1;
							zmiana = 1;
						}
					}
				}
			}
		}
		tabpom[ilosc] = tab[0];
		ilosc--;
		for (i = 0; i <= ilosc; i++)
		{
			tab[i] = tab[i + 1];
		}
	}
	for (i = 0; i <= licznik; i++)
	{
		tab[i] = tabpom[i];
	}
	//delete[] tabpom; ///TU 
};

void Introspektywne(double* tab, int poczatek, int koniec, int wywolania)
{

	int p = poczatek, k = koniec, pivot = tab[(k + p) / 2], i;
	int pom;

	if (wywolania)
	{
		
		while (p <= k)
		{
			while (tab[p] < pivot)
				p++;
			while (tab[k] > pivot)
				k--;
			if (p <= k)
			{
				pom = tab[p];
				tab[p] = tab[k];
				tab[k] = pom;
				p++;
				k--;
			}
		}

		wywolania--;
		if (poczatek < k)
			Introspektywne(tab, poczatek, k, wywolania);
		if (koniec > p)
			Introspektywne(tab, p, koniec, wywolania);
	}
	else
	{
		double *tabpom = new double[koniec - poczatek];
		for (i = 0; i <= koniec - poczatek; i++)
		{
			tabpom[i] = tab[poczatek + i];
		}
		Heapsort(tabpom, koniec-poczatek);
		for (i = 0; i <= koniec - poczatek; i++)
		{
			tab[poczatek + i] = tabpom[i];
		}
		//delete[] tabpom;
	}
	
	
};


int main()
{
	srand(time(NULL));
	int n = 1000000, liczba, i, j, wywolania=2*log2(n);
	double *tab = new double[n];
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < n; i++)
		{
			liczba = n-i;
			tab[i] = liczba;
			//			cout << tab[i] << endl;
		}
//		for (i = 0; i < n; i++)
//		{
//			liczba = rand();
//			tab[i] = liczba;
//			//	cout << tab[i] << endl;
//		}
		cout << endl;
		DWORD start = GetTickCount();
		Introspektywne(tab, 0, n - 1, wywolania);
		DWORD stop = GetTickCount();
		cout << stop - start << endl;
	}
	for (i = 0; i < n; i++)
	{
//		cout << tab[i] << endl;
	}
	delete[] tab;
	cin >> n;
	return 0;
}