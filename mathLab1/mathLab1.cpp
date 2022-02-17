#include <iostream>
#include <math.h>

using namespace std;


double function(double x);
double function1(double x);
double function2(double x);
bool check(double a, double b);

int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b, curX, nextX, e = 2e-4;;
	
	a = 0;
	b = 10;
	
	/*cout<< "������� ������ ���������:";
	cin >> a;
	cout << "������� ����� ���������:";
	cin >> b;*/

	if (check(a, b))
	{
		if (function(a) * function2(a) > 0)
		{
			curX = a;
			cout << "������� �� ���������� ��������� ��� a. ��������� ����� = " << a << endl<<endl;
		}
		else
		{
			if (function(b) * function2(b) > 0)
			{
				curX = b;
				cout << "������� �� ���������� ��������� ��� b. ��������� ����� = " << b << endl<<endl;
			}
			else
			{
				cout << "������� �� ���������� �� ���������." << endl<<endl;
				return 0;
			}
		}
		int iteration = 0;
		
		do
		{
			iteration = iteration + 1;
			double Fx = function(curX);
			double dFx = function1(curX);
			cout << "�������� = " << iteration << endl;
			cout << "X = " << curX << endl;
			cout << "F(x) = " << Fx << endl;
			cout << "dF(x) = " << dFx << endl<<endl;

			nextX = curX - (Fx / dFx);
			curX = nextX;
			
		} while (!(fabs(nextX - curX) <= e));
				

		cout << "������ ��������� = " << nextX << endl;
		cout << "���������� �������� = " << iteration << endl;

	}
	else
	cout << "������ ������� �� ��������� ["<<a<<","<<b<<"] �� ����� ������." << endl;


}

double function(double x)
{
	double arg = sin(2.12 * x);
	double f = pow((x - 3.21), 3) - 1.45 * arg;
	return f;
}

double function1(double x)
{
	double arg = cos((53 / 25) * x);
	double f = 3 * pow(x, 2) - ((963 / 50) * x) + ((3 * pow(321, 2)) / 10000) - ((1537 * arg) / 500);
	return f;
}

double function2(double x)
{

	double arg = sin((53 / 25) * x);
	double f = 6 * x - (963 / (double)50) + (81461 / 12500) * arg;
	return f;
}

bool check(double a, double b)
{
	
	if (function(a) * function(b) < 0) {
		
				return true;
		
	}	
	return false;
}
