#include <iostream>

using namespace std;

void outer_points(int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	outer_points(n, m);
    return 0;
}

void outer_points(int n, int m)
{
	int *prinadlegnost = new int[m];										// peremennaia, nakaplivayuchaia kol-vo otrezkov, v kotorix sod. tochka
	int *tochka = new int[m];
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i <n; i++)												// vivod otrezkov
	{
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tochka[i];
		prinadlegnost[i] = 0;
	}
	for (int i = 0; i < m; i++)													// proverka tochek na soderchanie v otrezkax
	{
		for (int j = 0; j < n; j++)
		{
			if (tochka[i] >= a[j] && tochka[i] <= b[j])	prinadlegnost[i] ++;
		}
	}
	for (int i = 0; i < m; i++)													// vivod rezyltata
	{
		cout << n - prinadlegnost[i] << " ";
	}

}
