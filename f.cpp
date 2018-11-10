#include<iostream>
#include <iomanip>

#define e 2.71828
#define pi 3.14159

double f(double x) {
return (x + e)*(x - pi)*(x - (2 * pi));
}

double df(double x)
{
	return ((3*x*x) - 6*pi*x + 2*e*x + (pi)*(pi) - 3*e*pi);
}

double ddf(double x){
	return  6*x+2*e-6*pi;
}

double g(double x)
{
	return x - (f(x) / df(x));
}

double d(double x, double P) 
{
		return x - P*f(x);
}

double print(double k, double x_n, double x_m, double f_x_n, double f_x_m) {
	std::cout << "| " << std::setw(3) << std::right << k << " | " << std::setw(15) << std::right << x_n << " | " << std::setw(15) << std::right << x_m << " | " << std::setw(15) << std::right <<abs(x_n-x_m)<< " | " << std::setw(15) << std::right << f_x_n << " | " << std::setw(15) << std::right << f_x_m << " | " << std::setw(15) << std::right <<abs(f_x_n-f_x_m)<< std::endl;
	return 0;

};
