#include <iostream>

long double fact(unsigned long int n)
{
	while (n > 1)
		return (n * fact(n - 1));
	return 1;
}

long double degree(int n, double x)
{
	while (n != 1)
		return (degree((n - 1), x) * x);
	return x;
}

long double sumExp(unsigned long int n, long double x)
{
	long double sumAll = 0;
	while (n != -1)
	{
		if (n == 0)
			return sumAll;
		else
		{
			sumAll += ((degree(x, n)) / (fact(n)));
			n -= 1;
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::cout.precision(6000);
	std::cout << "Введите значение n, где n - целое число" << std::endl;
	unsigned long int n;
	std::cin >> n;
	std::cout << "Введите значение x, где x - любое число" << std::endl;
	long double x;
	std::cin >> x;
	std::cout << fact(n)<< "\n" << degree(n, x) << std::endl;
	std::cout << sumExp(n, x) << std::endl;
	return 0;
}
