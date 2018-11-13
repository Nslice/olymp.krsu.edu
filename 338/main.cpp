#include <iostream>
#include <string>

using namespace std;

int main()
{
	string number;
	cin >> number;
	
	int index = number.find_first_of("123456789");
	number = (index == string::npos) ? "0" : number.substr(index);

	int B = number.length();


	if (B % 2)
		cout << "unlucky" << endl;
	else
	{
		int sum1 = 0, sum2 = 0;
		int i = 0;

		for ( ; i < B / 2; i++)
			sum1 += stoi(number.substr(i, 1));

		for ( ; i < B; i++)
			sum2 += stoi(number.substr(i, 1));


		cout << (sum1 == sum2 ? "lucky" : "unlucky") << endl;
	}

	system("pause");
	return 0;
}