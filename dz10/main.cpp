#include <iostream>

using namespace std;

void posledovatelnost(int m);

int main()
{
	int m;
	for (;;)
	{
		cin >> m;
		if (m > 0 && m < 500) break;
	}
	posledovatelnost(m);
    return 0;
}

void posledovatelnost(int m)
{
	int *a = new int[m];									//granizi otrezkov
	int *b = new int[m];
	int *poriadok = new int[m];								// ñ, buff2, save - peremennie dlia sortirovki
	int *dlina = new int[m];
	int c, buff = 0, min = 0, s=0;
	int *save_poriadok = new int[m];						//save_p, save_poriadok - peremennie dlia poiska posledovatelnosti
	int *save_p = new int[m];								// prichem save_poriadok soxraniaet okonchatelnii otvet
	int p;												// kol-vo vklyuchenii otrezka (ispolzyetsia v poiske posledovatelnosti)
	for (int i = 0; i < m; i++)								//vvod otrezkov and zapolnenie massiva nomerov otrezkov
	{
		cin >> a[i] >> b[i];
		poriadok[i] = i+1;
		dlina[i] = b[i] - a[i];
	}
	for (int i = 0; i < m; i++)							//sortirovka po vozrastaniyu zeni
	{
		min = dlina[i];
		c = i;
		for (int j = i + 1; j < m; j++)
		{
			if (dlina[j] < min)
			{
				min = dlina[j];
				c = j;
			}
		}
		buff = a[c];
		a[c] = a[i];
		a[i] = buff;
		buff = b[c];
		b[c] = b[i];
		b[i] = buff;
		buff = poriadok[c];
		poriadok[c] = poriadok[i];
		poriadok[i] = buff;
		buff = dlina[c];
		dlina[c] = dlina[i];
		dlina[i] = buff;
	}
	*save_p = 0;
	*save_poriadok = *poriadok;
	p = 0;
	for (int i = 0; i < m; i++)								//poisk maximalnoi posledovatelnosti
	{
		s = 0;
		save_p[s] = poriadok[i];
		for (int j = i; j < m; j++)								// poisk otrezkov, v kotorie vxodit i, a dalshe novaia and teraziia
		{																// verxnego zikla
			if (dlina[j] > dlina[i] && a[j] < a[i] && b[j] > b[i])
			{
				s++;
				save_p[s] = poriadok[j];
			}
		}
		if (s > p)
		{
			p = s;
			for (int k = 0; k <= p; k++)
			{
				save_poriadok[k] = save_p[k];
			}
		}
	}
	cout <<  p+1 << endl;
	for (int i = 0; i <= p; i++)	cout << " " << save_poriadok[i] << " ";
	delete[] a;
	delete[] b;
	delete[] poriadok;
	delete[] dlina;
	delete[] save_p;
	delete[] save_poriadok;
}
