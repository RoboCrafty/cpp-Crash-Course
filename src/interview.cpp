#include <iostream>

std::string str1 = "(a+b)";

std::vector<std::vector<float>> lidarData = {
    {1,2,3,0.1,0.2,0.3,0.5}, 
    {4,5,6}, 
    {7,8,9}};


bool checkString (std::string a)
{
    int len = a.length();
    int ctr1 = 0;
    int ctr2 = 0;

    for(int i =0; i <= len; i++)
    {
        if(a[i] == '(')
        {
            ctr1++;
        }
        if(a[i] == ')')
        {
            ctr2++;
        }
        if (ctr2 > ctr1)
        {
            return false;
        }
        
    }

    if (ctr1 == ctr2)
    {
        return true;
    }


}

int main()
{
    // for (int i = 0; i < lidarData)
    // {

    // }
    std::cout << "Valuei is: " << lidarData[1][3] << std::endl;
}