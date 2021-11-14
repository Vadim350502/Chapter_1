//#include "IT_Cource_CMakeProject_1.h"
#include <stdio.h>
#include <cstdlib>
#include <locale.h>


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#define RAND_MAX 99

template < typename T >
void print(T num, int precision = 100)
{
	int pointIndex = 0;
	double dNum = num;

	//приводим число к виду 0.####################### если оно больше 1
	while (dNum >= 1)
	{
		dNum /= 10;
		pointIndex++;
	}

	//если один из целочисленных типов без всяких мантис и дробных частей, то знаков после точки нет вообще, поэтому точность переопределяем в ноль
	if (num - (int)num == 0)
		precision = 0;

	//вычисляем полное количество знаков на печать с учётом сделанного в начале приведения
	precision += pointIndex;

	//если есть минус печатаем его и убираем из числа чтобы не портил дальнейшую арифметику
	if (num < 0)
	{
		dNum *= -1;
		putchar('-');
	}

	//если число уже изначально было в виде 0.####################### (т.е. дробное) то печатаем 0
	if (pointIndex == 0)
		putchar('0');

	//печатаем оставшиеся цифры пока позволяет точность, к сожалению из-за прыгающей мантиссы так и не удалось получить нормальное, краткое и красивое условие на обрезку лишних нолей в конце автоматически,
	//поэтому они обрезаются только точностью в параметре по умолчанию, которая может быть переопределена извне
	do
	{
		if (pointIndex == 0)
			putchar('.');

		dNum *= 10;
		putchar((int)dNum + '0');
		dNum -= (int)dNum;
		pointIndex--;
		precision--;
	} while (precision != 0);
}


int main(int argc, char** args)
{
	int num;

	setlocale(LC_ALL, "RUSSIAN");	

	do
	{
		printf("Введите число от 0 до 100: \n");
	} while (scanf("%d", &num) <= 0);

	if (num < 0 || num > 99)
	{
		num = rand();
	}
		
	printf("Ваше число: \n");		
	print(num);

	return ferror(stdout) ? EXIT_FAILURE : EXIT_SUCCESS;
}
