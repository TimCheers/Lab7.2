#include <iostream>
#include <math.h>
using namespace std;
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
	while ( (AB <= 0) || (BC <= 0) ||(B<=0) )
	{
		cout << "AB: ";
		cin >> AB;
		cout << "BC: ";
		cin >> BC;
		cout << "Угол между AB И BC: ";
		cin >> B;
		if ((AB <= 0) || (BC <= 0) || (B <= 0))
		{
			cout << "Ошибка! Невозможно построить фигуру по введённым параметрам" << endl;
		}
	}
	x = square(3, AB, B, BC);
	cout<< "Площадь треугольника ровна  " << x<<endl<<endl;
	x = -1;
	cout << "Введите параметры для вычисления площади пятиугольника с помощью функции square:" << endl;
	while (x <= 0 || B >= 180 || B <= 0 || D >= 180 || D <= 0)
	{
		cout << "AB: ";
		cin >> AB;
		cout << "BC: ";
		cin >> BC;
		cout << "Угол между AB И BC: ";
		cin >> B;
		cout << "CD: ";
		cin >> CD;
		cout << "DE: ";
		cin >> DE;
		cout << "Угол между CD И DE: ";
		cin >> D;
		cout << "EA: ";
		cin >> EA;
		x = square(5, AB, B, BC, CD, D, DE, EA);
		if (x<=0 || B >= 180 || B<=0 || D >= 180 || D <= 0)
		{
			cout << "Ошибка! Невозможно построить фигуру по введённым параметрам" << endl;
		}
	}
	cout << "Площадь пятиугольника ровна " << x<<endl<<endl;
	x = -1;
	cout << "Введите параметры для вычисления площади восьмиугольника с помощью функции square:" << endl;
	while (x <= 0 || B >= 180 || B <= 0 || D >= 180 || D <= 0 || D >= 180 || D <= 0)
	{
		cout << "AB: ";
		cin >> AB;
		cout << "BC: ";
		cin >> BC;
		cout << "Угол между AB И BC: ";
		cin >> B;
		cout << "CD: ";
		cin >> CD;
		cout << "DE: ";
		cin >> DE;
		cout << "Угол между CD И DE: ";
		cin >> D;
		cout << "EF: ";
		cin >> EF;
		cout << "FG: ";
		cin >> FG;
		cout << "Угол между EF И FG: ";
		cin >> F;
		cout << "GH: ";
		cin >> GH;
		cout << "HA: ";
		cin >> HA;
		cout << "Угол между GH И HA: ";
		cin >> H;
		x = square(5, AB, B, BC, CD, D, DE, EF,F,FG,GH,H,HA);
		if (x <= 0 || B >= 180 || B <= 0 || D >= 180 || D <= 0||  D >= 180 || D <= 0)
		{
			cout << "Ошибка! Невозможно построить фигуру по введённым параметрам" << endl;
		}
	}
	cout << "Площадь восьмиугольника ровна " << x << endl << endl;
}


