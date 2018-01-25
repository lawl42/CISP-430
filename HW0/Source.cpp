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
ifstream fin("bsort.in");
ofstream fout("bsort.out");

// print the array
void print()
{
	for (int i = 0; i < nums.size(); i++)
		fout << nums[i] << "\t";
	fout << "\n";
}

// bubble sort algorithm
void bsort()
{
	int i, j;
	for (i = 0; i < nums.size(); i++)
	{
		for (j = nums.size() - 1; j > 0; j--)
			if (nums[j] < nums[j - 1])
			{
				nums[j] += nums[j - 1];
				nums[j - 1] = nums[j] - nums[j - 1];
				nums[j] -= nums[j - 1];
			}
		print();
	}
}

int main()
{
	// read in the numbers
	int n;
	while (fin >> n)
		nums.push_back(n);
	
	// sort!
	bsort();

	return 0;
}