#include <iostream>
#include <math.h>
using namespace std;

//Решить указанную в варианте задачу, используя функции с
//переменным числом параметров.
//
//
//Написать функцию(или макроопределение), которая
//находит площадь треугольника по его сторонам.

//Написать
//функцию square c переменным числом параметров, которая
//находит площадь n - угольника по заданным сторонам и углам.
//Написать вызывающую функцию main, которая обращается к
//функции square не менее трех раз с количеством
//параметров 3, 5, 8

float triangle(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	float S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;

}

int square(int num, int AB, ...)
{
	int SH=0;
	if (num < 8 && num < 5)
	{
		SH = (num / 2)+2;
	}
	if (num < 8 && num == 5)
	{
		SH = (num / 2) + 1;
	}
	if (num >=8 )
	{
		SH = num / 2;
	}
	int* arr = new int[SH];
	int* pr = &AB;
	float p = 0;
	int k=0;
	float x, S, SAll=0;
	int  SL=num/2, i = 0;
	while (SL--)
	{
		int a, b,co;
		a = *pr;
		++pr;
		co = *pr;
		++pr;
		b = *pr;

		x = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(co));
		arr[i] = x;
		p = (a + b + x) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - x));
		SAll += S;
		if (num==3)
		{
			return SAll;

		}
		++pr;
		i++;
 	}
	if (num==5)
	{
		arr[SH - 1] = *pr;
	}
	p = 0;
	for (int j = 0; j < SH; j++)
	{
		p += arr[j];
	}
	p = p / 2;
	for (int j = 0; j < SH; j++)
	{
		int t = arr[j];
		arr[j] = p - t;
	}
	for (int j = 0; j < SH; j++)
	{
		p *= arr[j];
	}
	S = SAll + sqrt(p);
	return S;

}

int main()
{
	setlocale(LC_ALL, "ru");
	int AB=-1, BC=10, CD=-1, DE=-1, EF=-1, FG=-1, GH=-1, HA=-1,CA=-1,EA=-1;
	int B, D, F, H;

	cout << "Введите параметры для вычисления площади треугольника с помощью функции triangle:" << endl;
	while ((AB > BC + CA || BC > AB + CA || CA > AB + BC) || (AB <= 0) || (BC <= 0) || (CA <= 0))
	{

		cout << "AB: ";
		cin >> AB;

		cout << "BC: ";
		cin >> BC;

		cout << "CA: ";
		cin >> CA;

		if ((AB > BC + CA || BC > AB + CA || CA > AB + BC) || (AB <= 0) || (BC <= 0) || (CA <= 0))
		{
			cout << "Ошибка! Одна сторона не может быть отрицательной или больше двух других" << endl;
		}
	}
	float x = triangle(AB, BC, CA);
	cout << "Площадь треугольника ровна  " << x<<endl<<endl;
	AB = -1; BC = -10;
	cout << "Введите параметры для вычисления площади треугольника с помощью функции square:" << endl;
	while ( (AB <= 0) || (BC <= 0) )
	{

		cout << "AB: ";
		cin >> AB;

		cout << "BC: ";
		cin >> BC;

		cout << "Угол между AB И BC: ";
		cin >> B;


		if ((AB > BC + CA || BC > AB + CA || CA > AB + BC) || (AB <= 0) || (BC <= 0) || (CA <= 0))
		{
			cout << "Ошибка! Одна сторона не может быть отрицательной или больше двух других" << endl;
		}
	}
	x = square(3, AB, B, BC);
	cout<< "Площадь треугольника ровна  " << x<<endl;
}


