/*
@author: Lawrence Wong
@version: 2/1/18
*/

#include <iostream>
#include <fstream>

using namespace std;

int ari(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
	ofstream fout("ari.csv");

	fout << "n,sum" << "\n";
	for (int i = 0; i <= 10; i++)
	{
		fout << i << "," << ari(i) << "\n";
	}

	return 0;
}
