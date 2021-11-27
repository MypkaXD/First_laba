#include <iostream>

long double sumSin(unsigned long int n, long double x)
{
	long double S = x;
	long double sum = 0;
	for (int i = 1; i < n;)
	{
		sum += S;
		S *= ((-1) * x * x) / ((2 * i) * (2 * i + 1));
		i += 1;
	}
	if (S < 0)
	{
		S = (-1) * S;
		std::cout << "Погрешность равна = " << S << std::endl;
	}
	else std::cout << "Погрешность равна = " << S << std::endl;
	return sum;
}