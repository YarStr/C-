#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
	for (long long i = 2; i < sqrt(n) + 1; ++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int k;
	fin >> k;

	int count = 0;
	int num = 2;

	vector <int> vec;
	while (count < 3571)
	{
		if (isPrime(num) == true)
		{
			++count;
			vec.push_back(num);
		}
		num++;
	}

	fout << vec[vec[k - 1] - 1];

	return 0;
}
