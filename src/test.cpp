#include <iostream>


float computeVolume(float sideLength) {

    float vol = sideLength * sideLength * sideLength;   
    return vol;

}


int main( )
{
float width, height;
std::cout << "Enter width of cube: ";
std::cin >> width;

std::cout << "Volume is: " << computeVolume(width) << std::endl;

} 