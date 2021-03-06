/*
@author: Lawrence Wong
@version: 2/1/18
*/

#include <iostream>
#include <fstream>

using namespace std;

int geo(int n, int a)
{
    int sum = 0, j = 1;
    for (int i = 1; i <= n; i++)
    {
        j *= a;
        sum += j;
    }
    return sum;
}

int main()
{
	// ofstream fout("geo.csv");

	cout << "n\ta\tsum" << "\n";
	for (int i = 1; i <= 5; i++)
	{
	    for (int j = 1; j <= 5; j++)
    		cout << i << "\t" << j << "\t" << geo(i, j) << "\n";
	}

	return 0;
}
