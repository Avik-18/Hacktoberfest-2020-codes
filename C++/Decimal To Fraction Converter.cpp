#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n;
	long long num, denom = 10000000, counter = 1, counter1 = 1;
	cout << "Enter the number : ";
	cin >> n;
	n = n * 10000000.0;
	num = static_cast<long long>(n);
	while (counter1 <= 10)
	{
		counter = 1;
		while ((counter <= num && counter <= denom))
		{
			if ((num % counter == 0) && (denom % counter == 0))
			{
				num /= counter;
				denom /= counter;
			}
			counter++;
		}
		counter1++;
	}
	cout << endl << num << " / " << denom;

	cout << "\n\n";
	system("pause");
	return 0;
}