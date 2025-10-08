#include <iostream>

class Solution{
public: 
        int largestAltitude(std::vector<int>& gain)
        {
                int size1 = gain.size();
                int maxAlt = 0;
                int currentAlt = 0;

                for(int i = 0; i < size1; i++)
                {
                        currentAlt += gain[i];
                        
                        if (currentAlt > maxAlt)
                        {
                                maxAlt = currentAlt;
                        }
                }
                return maxAlt;
        }
};

int main()
{
        Solution sol;
        std::vector<int> gain = {28,0,-8,-99,11,62,-35,68,2,12,-71,13,66,-28};
        std::cout << "Max Altitute is: " << sol.largestAltitude(gain) << std::endl;
}