#include <iostream>
#include "add.h"

long double result(int coef)
{
	std::cout << "Введите значение n" << std::endl;
	unsigned long int n;
	std::cin >> n;
	std::cout << "Введите значение x" << std::endl;
	long double x;
	std::cin >> x;
	if (coef == 1)
		return sumSin(n, x);
	if (coef == 2)
		return sumArcSin(n, x);
	if (coef == 3)
		return sumArcTan(n, x);
	if (coef == 4)
		return sumLn(n, x);
	if (coef == 5)
		return sumArth(n, x);
}



int main()
{
	setlocale(LC_CTYPE, "Russian");
	std::cout.precision(6000);
	std::cout << "Введите 1, если хотите найти Sin(x), где n >= 0, x - любое число" << "\n" << "Введите 2, если хотите найти ArcSin(x), где n >= 0, модуль x <= 1" << "\n" << "Введите 3, если хотите найти ArcTan(x), где n >= 0, модуль x <= 1" << std::endl;
	int coef;
	std::cin >> coef;
	std::cout << "Результат равен = " << result(coef) << std::endl;
	return 0;
}