#include <iostream>



float computeVolume(float sideLength) {

    float vol = sideLength * sideLength * sideLength;   
    return vol;

}


int main( )
{

    unsigned long long int variable;

    std::cout << "Enter variable to store:";
    std::cin >> variable;
    std::cout << "Store value is:" << variable <<  std::endl;

    std::cout << "Size of var is:" << sizeof(variable) << std::endl;

} 