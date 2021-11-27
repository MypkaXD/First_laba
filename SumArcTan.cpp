#include <iostream>

long double sumArcTan(unsigned long int n, long double x)
{
	long double S = x;
	long double S_last = 0;
	long double sum = 0;
	for (int i = 1; i <= n;)
	{
		sum += S;
		S *= ((-1) * x * x * (2 * i - 1)) / (2 * i + 1);
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