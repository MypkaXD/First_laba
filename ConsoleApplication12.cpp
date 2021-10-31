#include <iostream>

long double fact(long long int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)
		return 1;
	else if (n < 0)
		std::cout << "Неверное значение n" << std::endl;
	else if (n > 1)
	{
		while (n > 1)
			return (n * fact(n - 1));
	}
}

long double degree(long long int n, double x)
{
	if (n == 1)
		return x;
	else if (n == 0)
		return 1;
	else if (n > 1)
	{
		while (n != 1)
			return (degree((n - 1), x) * x);
	}
}

long double sumCos(long long int n, long double x)
{
	long double sumAll = 0;
	while (n != -1)
	{
		sumAll += (((degree(n, -1)) * (degree(2 * n, x))) / (fact(2 * n)));
		n -= 1;
	}
	return sumAll;
}

long double sumCoren(long long int n, long double x)
{
	long double sumAll = 0;
	while (n != -1)
	{
		sumAll += ((degree(n, -1)) * fact(2 * n) * degree(n, x) / ((1 - 2 * n) * (degree(2, fact(n))) * degree(n, 4)));
		n -= 1;
	}
	return sumAll;
}

long double sumExp(long long int n, long double x)
{
	long double sumAll = 0;
	while (n != -1)
	{
		sumAll += ((degree(n,x))/fact(n));
		n -= 1;
	}
	return sumAll;
}

long double epsilond(long long int n, long double x, int coef)
{
	if (coef == 1)
		return ((((degree(n, -1)) * (degree(2 * n, x))) / (fact(2 * n))));
	else if (coef == 2)
		return ((degree(n, -1)) * fact(2 * n) * degree(n, x) / ((1 - 2 * n) * (degree(2, fact(n))) * degree(n, 4)));
	else if (coef == 3)
		return ((degree(n, x)) / fact(n));
}

long double result(int coef)
{
	std::cout << "Введите значение n, где n - целое число" << std::endl;
	long long int n;
	std::cin >> n;
	std::cout << "Введите значение x, где x - любое число" << std::endl;
	long double x;
	std::cin >> x;
	std::cout << "Погрешность = " << epsilond(n, x, coef) << std::endl;
	if (coef == 1)
		return (sumCos(n, x));
	else if (coef == 2)
	{
		if (degree(2, x) <= 1)
			return (sumCoren(n, x));
		else
		{
			std::cout << "Введено неверное значение x, попробуйте ввести другие данные" << std::endl;
			return(result(coef));
		}
	}
	else if (coef == 3)
	{
		return sumExp(n, x);
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::cout.precision(6000);
	std::cout << "Введите 1, если Вы хотите найти Cos(x) \nВведите 2, если Вы хотите найти корень из (1+x), где модуль x <= 1 \nВведите 3, если Вы хотите найти e в степени x " << std::endl;
	int coef;
	std::cin >> coef;
	std::cout <<"Результат = " << result(coef) << std::endl;
	return 0;
}
