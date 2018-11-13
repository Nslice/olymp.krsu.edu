#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

/*
5                 4               4                  5
2, 3, 7, 11, 4    4 ,8 ,12, 16    100, 17, 81, 82    2, 3, 4, 5, 6
*/

int gcd(int p, int q);
bool check(const vector<int>& vec, int val);


int main()
{
	int N;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	vector<int> buffer;
	int maxcount = 0;


	for (int i = 0; i < vec.size(); i++)
	{
		buffer.push_back(vec[i]);

		int j = i + 1;
		while (j < vec.size())
		{
			if (check(buffer, vec[j]))
				buffer.push_back(vec[j]);
			j++;
		}
		j = 0;
		while (j < i)
		{
			if (check(buffer, vec[j]))
				buffer.push_back(vec[j]);
			j++;
		}

		maxcount = (buffer.size() > maxcount) ? buffer.size() : maxcount;
		buffer.clear();
	}


	cout << maxcount << endl;

	system("pause");
	return 0;
}


int gcd(int p, int q)
{
	if (q == 0) return p;
	int remainder = p % q;
	return gcd(q, remainder);
}


bool check(const vector<int>& vec, int val)
{
	for (int i : vec)
	{
		if (gcd(i, val) != 1)
			return false;
	}
	return true;
}
