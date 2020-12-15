#include <iostream>

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





//int nok(int num,int nod, int a, ...)
//{
//	int* p = &a;
//	int Pr = 1;
//	while (num--)
//	{
//		Pr = Pr * *p;
//		++p;
//	}
//	cout << "НОД равен: " << nod<<endl;


//int arr[8] = { 0,0,0,0,0,0,0,0 };



//	cout << "НОК равен: "<<Pr/nod<<endl<<endl;         
//	return 0;                                        
//}

int treu(int num, int AB, ...)
{
	int* pr = &AB;
	int p = 0;
	int x,k=0;
	int S, Sall=0;
	while (num--)
	{
		int a, b,co;
		a = *pr;
		++pr;
		co = *pr;
		++pr;
		b = *pr;

		x = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(co));
		p = (a + b + x) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - x));
		Sall += S;
		++pr;
	}
	while (true)
	{

	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	

}


