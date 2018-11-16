#include <iostream>

using namespace std;


int main()
{
	int C3;  // трехсомовых монет
	int C10; // дестисомовых монет
	int S;   // кол-во сом
	
	cin >> C3;
	cin >> C10;
	cin >> S;



	int count = 0;

	while (C10 > 0)
	{
		if (S >= 10)
		{
			S -= 10;
			C10--;
			count++;
		}
		else if (S >= 3)
		{
			S -= 3;
			C3--;
			count++;
		}
		else break;
	}

	cout << ((S > 0) ? 0 : count) << endl;

	system("pause");
	return 0;
}