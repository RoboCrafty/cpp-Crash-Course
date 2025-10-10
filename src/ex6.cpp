#include <iostream>

class Calculator 
{
public: 

    double integral (double f_x, double f_x2, double x, double x2)
    {
        double result = 0.5 * (f_x2 + f_x) * (x2 - x);
        return result;

    }

    double func1_eval (double x) 
    {
        return x*x;
    }

};

int main ()
{
    
    Calculator calc;
    double a = 0;
    double b = 10;
    double n =0.01;
    std::cout << "size of float: " << sizeof(float) << std::endl;
    double itr = (b-a)/n;
    std::cout << "Itr: " << itr;
    double area;

    for (int i = 0; i < itr; i++)
    {
        a = (n*i);
        area += calc.integral(calc.func1_eval(a), calc.func1_eval(a + n), a, a + n);
        std::cout << "Area is: " << area << std::endl; 
    }
    
}