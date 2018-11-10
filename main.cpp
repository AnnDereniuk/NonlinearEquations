#include <iostream>
#include <iomanip>
#include "f.h"
#define pi 3.14159
#define eps 0.0001
#define sigma 1000

using namespace std;
int main() {
	
	
	double a = -3.5, b = 2.;
	int k = 1;
	double x_n=(a+b)/2., x_n1 = 0.;
	cout << "a=" << a << ", b=" << b << endl;
		cout << "1. Dichotomy method: " << endl;
		double f_a = f(a), f_b = f(b);
		double x = pi;
		std::cout << "| " << std::setw(3) << std::right << "n" << " | " << std::setw(15) << std::right << "x_n" << " | " << std::setw(15) << std::right << "x_(n+1)" << " | " << std::setw(15) << std::right << "|x_n - x_m|" << " | " << std::setw(15) << std::right << "f_x_n" << " | " << std::setw(15) << std::right << "f_x_(n+1)" << " | " << std::setw(15) << std::right << "|f_x_n - f_x_(n+1)|" << std::endl;
		print(k, x_n, x_n1, f_a, f_b);
		while ((abs(x_n - x_n1) >= eps) && (k <= sigma))
		{
			k++;
			if (f(a)*f(x_n) <= 0) 
				{
					b = x_n;
					f_b = f(x_n);
									}
			else 
				{
					a = x_n;
					f_a = f(x_n);
									}
			x_n1 = x_n;
			x_n = (a + b) / 2.;
			print(k, x_n, x_n1, f_a, f_b);
											}
		cout << "Iteration number n=" << k << endl;
		
		
		
		x_n = 0., x_n1 = 0.;
		double a1 = -3.5, b1 = -1;
		int k1 = 1;		
		cout << "2. Newton's method: " << endl;
		//cout<<f(a1)<<","<<f(b1);
		if (f(a1)*f(b1) > 0) { cout << "no"; }
		else { if (f(a1)*ddf(a1) > 0) x_n = a1; 
		else x_n = b1;
		x_n1 = x_n;
		x_n = g(x_n1);
		}
		print(k1, x_n, x_n1, f(x_n), f(x_n1));
		while (fabs(x_n - x_n1) > eps) {
			x_n1 = x_n;
			x_n = g(x_n1);
			k1++;
			print(k1, x_n, x_n1, f(x_n), f(x_n1));

		}
		
		
		/*if (f(a1)*f(b1) < 0) {
			if (f(a1)*ddf(a1) > 0) { x_n = a1; }
			else x_n = b1;
			print(k1, x_n, x_n1, f(x_n), f(x_n1));
			while (fabs(x_n1 - x_n) >= eps) {
				x_n1 = x_n;
				x_n = g(x_n);
				k1++;
				print(k1, x_n, x_n1, f(x_n), f(x_n1));
			};
		};*/
		cout << "Iteration number n=" << k1 << endl;



		x_n = 3.1, x_n1 = 0;
		double P = 0.0315; int k2 = 1;
		cout << "3. Fixed-point Iteration Method:" << endl;
		print(k2, x_n, x_n1, f(x_n), f(x_n1));
		while(fabs(x_n1-x_n)>eps){
			k2++;
			x_n1 = x_n;
			x_n = d(x_n,P);
			print(k2, x_n, x_n1, f(x_n), f(x_n1));
		} 
		cout << "Iteration number n=" << k2 << endl;
		system("pause");
		return 0;
}