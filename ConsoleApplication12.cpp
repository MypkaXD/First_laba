#include <iostream>


long long factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n - 1);
}


double degree(double x, int n)
{
	if (n == 1) return x;
	return (x * degree(x, n - 1));
}

double sumForSin(int n, double x)
{
	double sumAll = 0;
	while (n != -1)
	{
		sumAll += (degree(-1, n) * degree(x, 2*n + 1)) / factorial(2 * n + 1);
		n -= 1;
	}
	return sumAll;
}

double sumForExp(int n, double x)
{
	double sumAll = 0;
	while (n != -1)
	{
		sumAll += (degree(x, n) / factorial(n));
		n -= 1;
	}
	return sumAll;
}

double sumForCos(int n, double x)
{
	double sumAll = 0;
	while (n != -1)
	{
		sumAll += (degree(x, 2*n) / factorial(2*n));
		n -= 1;
	}
	return sumAll;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::cout << "Что вы хотите вычислить?\nЕсли sin(x), то введите '1'\nЕсли e^x, то введите '2'\nЕсли cos(x), то введите '3'" << std::endl;
	int quest;
	std::cin >> quest;
	if (quest == 1)
	{
		std::cout << "Введите n, где n - натуральное число" << std::endl;
		int n;
		std::cin >> n;
		std::cout << "Введите x, где x - любое число" << std::endl;
		double x;
		std::cin >> x;
		std::cout << sumForSin(n, x) << std::endl;
		std::cout << "Погрешность равна =" << (degree(-1, n) * degree(x, 2 * n + 1)) / factorial(2 * n + 1) << std::endl;
	}
	else if (quest == 2)
	{
		std::cout << "Введите n, где n - натуральное число" << std::endl;
		int n;
		std::cin >> n;
		std::cout << "Введите x, где x - любое число" << std::endl;
		double x;
		std::cin >> x;
		std::cout << sumForExp(n, x) << std::endl;
		std::cout << "Погрешность равна =" << (degree(x, n) / factorial(n)) << std::endl;
	}
	else if (quest == 3)
	{
		std::cout << "Введите n, где n - натуральное число" << std::endl;
		int n;
		std::cin >> n;
		std::cout << "Введите x, где x - любое число" << std::endl;
		double x;
		std::cin >> x;
		std::cout << sumForCos(n, x) << std::endl;
		std::cout << "Погрешность равна =" << (degree(x, 2 * n) / factorial(2 * n))<<std::endl;
	}
	return 0;
}
