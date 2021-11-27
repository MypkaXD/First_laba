// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef ADD_H
#define ADD_H

long double sumSin(unsigned long int n, long double x);

long double sumArcSin(unsigned long int n, long double x);

long double sumArcTan(unsigned long int n, long double x);

long double sumLn(unsigned long int n, long double x);

long double sumArth(unsigned long int n, long double x);

// Заканчиваем директивой препроцессора
#endif