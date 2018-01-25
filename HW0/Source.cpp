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
ifstream fin("ssort.in");
ofstream fout("ssort.out");

// print the array
void print()
{
	for (int i = 0; i < nums.size(); i++)
		fout << nums[i] << "\t";
	fout << "\n";
}

// bubble sort algorithm
void ssort()
{
	int i, j, min;

	// have an index to the first unsorted element
	for (i = 0; i < nums.size(); i++)
	{
		// find the smallest number
		min = i;
		for (j = i + 1; j < nums.size(); j++)
			if (nums[j] < nums[min])
				min = j;

		// swap min and i
		int temp = nums[min];
		nums[min] = nums[i];
		nums[i] = temp;

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
	ssort();

	return 0;
}
