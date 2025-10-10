#include <iostream>
#include <vector>


int main ()
{
    std::vector<int> array2 = {
        85, 12, 640, 0, 99, 3, 76, 21, 55, 1, 48, 90,
        15, 62, 7, 33, 1000, 88, 2, 40, 71, 10, 95,
        29, 5, 67, 18, 80, 25, 59, 14, 73, 4, -1, 85, 12, 640, 0, 99, 3, 76, 21, 55, 1, 48, 90,
        15, 62, 7, 33, 1000, 88, 2, 40, 71, 10, 95,
        29, 5, 67, 18, 80, 25, 59, 14, 73, 4, -1
    };

    int size = array2.size();

    for (int i = 1; i < size; i++)
    {        
        for (int j = size-1; j >= i; j--)
        {
            if (array2[j-1] > array2 [j])
            {   
                std::cout << "J = " << j << " ----- [ ";
                for (int k = 0; k < size; k++)
                {
                    std::cout << array2[k] << " ";
                }
                std::cout<< "]" <<std::endl;

                int temp = array2 [j-1];
                array2 [j-1] = array2 [j];
                array2 [j] = temp;
            }
        }
    }
}