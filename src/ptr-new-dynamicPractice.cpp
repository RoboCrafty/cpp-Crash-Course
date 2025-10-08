#include <iostream>


class Solution{
public:
    
    auto mergeAlternately(std::string word1, std::string word2){

        std::string output;
        
        int size1 = word1.size();
        int size2 = word2.size();
        if (size2>size1){
            size1 = size2;
        }
        
        for (int i = 0; i < size1; i++){
            
            if (i<word1.size()){
                std::cout << word1[i];
                output += word1[i];
            }
            if (i<word2.size()){
                std::cout << word2[i];
                output  += word2[i];
            }
        }
        return output;
    }

};



int main (){

    Solution sol;
    Solution* solptr = &sol;
    double am =6;
    double* amptr = &am;
    double & amref = am;

    auto amptr1 = new long double (5.0);
    double amptr2 = 5.0;
    while (am == 6){
        // (*amptr1) ++;
        // (*amptr1) ++;
        auto amptr1 = new long double (5.0);
        delete amptr1;
        // double amptr2 = 5.0;
        // amptr2++;
        // std::cout << amptr2 << std::endl;

    }   


    std::cout << amptr1 << "am is: " << am << std::endl;

    // std::cout << solptr -> mergeAlternately("ab","pqrs") <<std::endl; 
    // std::cout << sol.mergeAlternately("ab","pqrs") << std::endl;


    return 0;
}