#include <iostream>

class Calculator 
{
public: 

    float integral (float f_x, float f_x2, float x0, float xn, int itr)
    {
        float h = (xn - x0)/itr;
        float result = 0.5 * (f_x2 + f_x) * h;
        return result;

    }

    float func1_eval (float x) 
    {
        return x*x;
    }



};

int main ()
{
    Calculator calc;
    float x0 = 0;
    float xn = 10;
    float n = 0.0001;

    int itr = (xn-x0)/n;
    float area=0;
    float a = x0
    ;
    for (int i = 0; i < itr; i++)
    {
        area += calc.integral(calc.func1_eval(a), calc.func1_eval(a + n), x0, xn, itr);
        a = (n*i);
    }
    std::cout << "Area is: " << area << std::endl; 
}