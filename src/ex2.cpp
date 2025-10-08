#include <iostream>
#include <complex>
#include <array>

class Quadratic
{
public:
    Quadratic(double a, double b, double c)
        : a_(a), b_(b), c_(c) {}

    std::array<std::complex<double>, 2> compute_solution()
    {
        std::cout << "Calculating solutions: \n" << std::endl;
        
        float d;
        

        if (a_ == 0)
        {
            if  (b_ == 0)
            {
                if (c_ == 0)
                {
                    std::cout << "Every number is a soultion" << std::endl;
                    std::complex<double> sol1(0.0, 0.0);
                    std::complex<double> sol2(0.0, 0.0);
                    std::array<std::complex<double>, 2> solution = {sol1, sol2};
                return solution; 
                }
                else
                {
                    std::cout << "Error: No soultion" << std::endl; 
                    std::complex<double> sol1(0.0, 0.0);
                    std::complex<double> sol2(0.0, 0.0);
                    std::array<std::complex<double>, 2> solution = {sol1, sol2};
                    return solution; 
                }

            }
            else
            {
                std::cout << "One real solution" << std::endl;
                std::complex<double> sol1(-c_/b_, 0.0);
                std::complex<double> sol2(-c_/b_, 0.0);
                std::array<std::complex<double>, 2> solution = {sol1, sol2};
                return solution; 
            }
            
        }
        else
        {
            d = ((b_*b_) - (4*a_*c_)) / (4 * a_ * a_);
            if (d == 0)
            {
                std::cout << "One real solution" << std::endl;
                std::complex<double> sol1(-b_ / (2*a_), 0.0);
                std::complex<double> sol2(-b_ / (2*a_), 0.0);
                std::array<std::complex<double>, 2> solution = {sol1, sol2};
                return solution; 
            }
            else if (d > 0)
            {
                std::cout << "Two real solutions" << std::endl;
                std::complex<double> sol1(-b_ / (2*a_) + std::sqrt(d), 0.0);
                std::complex<double> sol2(-b_ / (2*a_) - std::sqrt(d), 0.0);
                std::array<std::complex<double>, 2> solution = {sol1, sol2};
                return solution; 
            }
            else if (d < 0)
            {
                std::cout << "Two complex solutions" << std::endl;
                std::complex<double> sol1(-b_ / (2*a_), std::sqrt(-d));
                std::complex<double> sol2(-b_ / (2*a_), -std::sqrt(-d));
                std::array<std::complex<double>, 2> solution = {sol1, sol2};
                return solution; 
            }

        }

        
    }

private:
    double a_;
    double b_;
    double c_;
};


class Compute {
public:

    // This methond doesnt work with  properly complex solutions
    std::vector<float> Quadratic (float a, float b, float c)
    {

        std::cout << "Calculating solutions: \n" << std::endl;
        std::vector<float> result;
        float d;

        if (a == 0)
        {
            if  (b == 0)
            {
                if (c == 0)
                {
                    std::cout << "Every number is a soultion" << std::endl;
                    result.push_back(0); 
                    result.push_back(0);  
                }
                else
                {
                    std::cout << "Error: No soultion" << std::endl; 
                    result.push_back(0); 
                    result.push_back(0); 
                }

            }
            else
            {
                std::cout << "One real solution" << std::endl;
                result.push_back(-c/b);
                result.push_back(-c/b);
            }
            
        }
        else
        {
            d = ((b*b) - (4*a*c)) / (4*a*a);
            if (d == 0)
            {
                std::cout << "One real solution" << std::endl;
                result.push_back(-b / (2*a));
                result.push_back(-b / (2*a));
            }
            else if (d > 0)
            {
                std::cout << "Two real solutions" << std::endl;
                result.push_back( (-b / (2*a)) + std::sqrt(d) );
                result.push_back( (-b / (2*a)) - std::sqrt(d) );
            }
            else if (d < 0)
            {
                std::cout << "Two complex solutions" << std::endl;
                result.push_back( (-b / (2*a)) + std::sqrt(-d) );
                result.push_back( (-b / (2*a)) - std::sqrt(-d) );
            }

        }
        
        return result;

    }

};


int main ()
{
    Compute sol;
    Compute* solptr = &sol;

    float a, b, c;
    // std::vector<float> result;
    a = b = c = 0.0;

    std::cout << "Enter a: " << std::endl;
    std::cin >> a;

    std::cout << "Enter b: " << std::endl;
    std::cin >> b;

    std::cout << "Enter c: " << std::endl;
    std::cin >> c;

    Quadratic my_quadratic_eq(a, b, c);
    auto result = my_quadratic_eq.compute_solution();
    std::cout << "Sol1: " << result[0] << std::endl;
    std::cout << "Sol2: " << result[1] << std::endl;
    //  result = solptr -> Quadratic(a, b, c);
    // std::cout << "x1 is: " << result[0] << " and x2 is: " << result[1] << std::endl;
   


}