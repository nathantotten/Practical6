#include <iostream>

using namespace std;

// non-recursive

/*double rsquare(int n)
{

	double sum = 0.;
	for (double i = 1; i <= n; i++) {
		sum += 1. / (i * 1);
		return sum;
	}

}*/

// recursive
double rsquare(int n)
{
	// Base case
	if (n == 1)
		return 1.;

	// recursive case
	return rsquare(n - 1) + 1. / (double(n) * double(n));
}

int main()
{
	
	cout << rsquare(5) << "\n";
	cout << rsquare(6) << "\n";
	cout << "Limit = " << (3.1415926 * 3.1415926) / 6. << "\n";
	cout << rsquare(1000) << "\n";

	return 0;
}