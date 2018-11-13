#include <iostream>

using std::cout;
using std::endl;


int main()
{
	/*
		2 варианта последовательностей:
		-1 0 1 2 3 4 ... n
		 1 2 3 4 ....... n

		 может такая
		 -1 2 3 4 ...... n

	*/
	while (true)
	{
		int N;
		std::cin >> N;
		//int* arr = new int[N];
		int arr[250];

		arr[0] = 1;
		int sumMax = arr[0];
		for (int k = 1; k < N; k++)
		{
			arr[k] = abs(arr[k - 1] + 1);
			sumMax += arr[k];
		}

		arr[0] = -1;
		int sumMin = arr[0];
		for (int k = 1; k < N; k++)
		{
			arr[k] = abs(arr[k - 1] + 1);
			sumMin += arr[k];
		}




		std::cout << abs(sumMin) << std::endl;
		std::cout << abs(sumMax) << std::endl;

	}


	//delete[] arr;
	return 0;
}

/*
		min    max
  2 :    1,     3
  3 :    0,     6
  4 :    2,     10
  5 :    5,     15
*/