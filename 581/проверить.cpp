#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

/*
5             4            4               5
2 3 7 11 4    4 8 12 16    100 17 81 82    2 3 4 5 6
*/

int main()
{
	int N ;
	std::cin >> N;
	vector<int> input(N);
	for (int& i : input)
		std::cin >> i;

	vector<vector<int>> vec(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 2; j <= input[i] / 2; j++)
		{
			if (input[i] % j == 0)
				vec[i].push_back(j);
		}
		vec[i].push_back(input[i]);
	}


	int counter, max = 0;

	vector<int>::const_iterator check;
	vector<int> heap;
	/*
	13
	2 3 7 11 13 8 6 9 4 17 22 76 81

	*/
	int lock = vec.size();
	for (int i = 0; i < N; i++)
	{
		counter = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == lock) continue;
			check = std::find_first_of(heap.cbegin(), heap.cend(), vec[j].cbegin(), vec[j].cend());
			if (check == heap.cend())
			{
				heap.insert(heap.cend(), vec[j].cbegin(), vec[j].cend());
				counter++;
			}
		}
		heap.erase(heap.begin(), heap.end());
		lock = i;
		max = (counter > max) ? counter : max;
	}

	cout << max << endl;


	system("pause");
	return 0;
}