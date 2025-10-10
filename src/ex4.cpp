#include <iostream>

float compute_ui(float f_a, float f_b, float a, float b)
{
    float result = a - ((f_a * (b-a)) / (f_b - f_a));
    std::cout << "Result is: " << result << std::endl;
    return result;
}


float function(float x)
{
    // float result = (x+1)*(x-1);
    float result = ((x*x*x) - 8); //Use any one equation

    std::cout << "Func eval at " << x << ": " << result << std::endl;
    return result;
}




int main ()
{
    float a = -0.9;
    float b = 5;
    float eps = 0.001;
    float f_ui; 
    int itmax = 100;
    int it = 0;
    do 
    {
        std::cout << " ----------------------------- " << std::endl;
        float f_a = function (a);
        float f_b = function (b);

        float output = compute_ui(f_a, f_b, a, b);
        f_ui = function(output);
        if ((f_ui * f_a) < 0)
        {
            std::cout << "fu*fa < 0" << std::endl;
            b  = output;
        }
        else if ((f_ui * f_a) > 0)
        {
            std::cout << "fu*fa > 0" << std::endl;
            a  = output;
        }

        it++;
    }
    while (it < itmax);
}