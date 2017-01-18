#include <iostream>

using namespace std;

void unusual_diofant(int a, int b, int c);

int main()
{
	int a,b,c;																		//zikl, dayushii pravo vvoda do momenta,
	{																						//poka polzovatelu eto neobxodimo
		cin >> a >> b >> c;
		if (a%b == 0 || b%a == 0)
		{
			cout << "none"<<endl;
		}
		else if (a / b < 0 || b / a < 0)
		{
			cout << "inf"<<endl;
		}
		else
		{
			unusual_diofant(a, b, c);
		}

	}
    return 0;
}

void unusual_diofant(int a, int b, int c)
{
	int x = 0;
	int y = 0;
	float Y = 0.0;
	for (;;)															//vichislenie neotrizhatelnix kornei yravneniia
	{
		Y = (c - a*static_cast<float>(x)) / b;
		y = static_cast<int>(Y);
		if(y < 0) break;
		if ((Y - y) == 0) cout << x << " " << y  << endl;
		x++;
	}
}
