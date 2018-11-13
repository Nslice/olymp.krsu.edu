#include <iostream>


int main()
{
	int n;
	int sum = 0;

	std::cin >> n;

	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	sum += n;

	std::cout << sum << std::endl;


	system("pause");
	return 0;
}