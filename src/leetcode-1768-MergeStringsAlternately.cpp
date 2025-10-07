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
    std::cout << sol.mergeAlternately("ab","pqrs") << std::endl;


    return 0;
}