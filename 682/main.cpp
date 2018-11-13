#include <iostream>


int main()
{
	int n1 = 0, n2 = 1;
	int N, steps;

	std::cin >> N;

	while (n2 <= N)
	{
		n2 = n2 + n1;
		n1 = n2 - n1;
	}

	steps = (n2 - N < N - n1) ? n2 - N : N - n1;
	std::cout << steps << std::endl;

	system("pause");
	return 0;
}