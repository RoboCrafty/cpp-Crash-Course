#include <iostream>


class Solution {
public:
    void moveZeroes(std::vector<int> nums) {
        
        int size1 = nums.size();
        std::vector<int> output;
        
        for (int i = 0; i < size1; i++){
            if (nums[i] != 0)
            {
                // std::cout << nums[i];
                output.push_back(nums[i]);
            }
        }
        
        for (int i=0;i<5;i++){

            std::cout << output[i] << std::endl;

        }
        
    

        
        
    }
};



int main (){

    Solution sol;

    std::vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    // std::cout << nums << std::endl;

    return 0;
}