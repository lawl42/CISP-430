/*
@author: Lawrence Wong
@version: 1/24/18
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// initialize vectors and iostream
vector<int> nums;
ifstream fin("isort.in");
ofstream fout("isort.out");

// print the array
void print()
{
	for (int i = 0; i < nums.size(); i++)
		fout << nums[i] << "\t";
	fout << "\n";
}

// insertion sort algorithm
void isort()
{
	int i, j, k;
	for (i = 1; i < nums.size(); i++)
	{
		int j = i - 1;
		int k = nums[i];
		
		while (j >= 0 && k < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = k;

		print();
	}
}

int main()
{
	// read in the numbers
	int n;
	while (fin >> n)
		nums.push_back(n);
	print();

	// sort!
	isort();

	return 0;
}
