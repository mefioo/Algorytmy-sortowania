#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdio>
#include <Windows.h>

using namespace std;

void quicksort(double* tab, int poczatek, int koniec)
{

	int p = poczatek, k = koniec, pivot = tab[(k + p) / 2];
	int pom;

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


	if (poczatek < k)
		quicksort(tab, poczatek, k);
	if (koniec > p)
		quicksort(tab, p, koniec);

};



int main()
{
	srand(time(NULL));
	int n = 50000, liczba, i, j;
	double *tab = new double [n];
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < n; i++)
		{
			liczba = n-i;
			tab[i] = liczba;
//			cout << tab[i] << endl;
		}
		for (i = n; i < n; i++)
		{
			liczba = rand();
			tab[i] = liczba;
			//	cout << tab[i] << endl;
		}
		cout << endl;
		DWORD start = GetTickCount();
		quicksort(tab, 0, n - 1);
		DWORD stop = GetTickCount();
		cout << stop - start << endl;
	}
	
	for (i = 0; i<n; i++)
	{

	//	cout << tab[i] << endl;

	}
	cin >> n;
	delete[] tab;
	return 0;
}