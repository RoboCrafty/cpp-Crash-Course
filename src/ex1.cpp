#include <iostream>
using namespace std;


class Calculate {

    public:
        static float vol(float a1, float a2, float a3, float a4){
            return a1*a2*(a3+a4/3);
        }



};



int main() {

    Calculate calc;
    float a1, a2, a3, a4, v;
    a1 = a2 = a3 = a4 = v = 0.0;

    std::cout << "Volume Calculator!" << std::endl;
    std::cout << "Enter a1: " << std::endl;
    std::cin >> a1;

    std::cout << "Enter a2: " << std::endl;
    std::cin >> a2;

    std::cout << "Enter a3: " << std::endl;
    std::cin >> a3;

    std::cout << "Enter a4: " << std::endl;
    std::cin >> a4;

    v = Calculate::vol(a1, a2, a3, a4);

    std::cout << "Volume is: " << v << std::endl;
    
    return 0;

}