#include <iostream>

using namespace std;

class Matrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> tmp;
        std::vector<std::string> direction = {"right", "down", "left", "up"}; //for moving in spiral
        vector<vector<bool>> trackExp(matrix.size(), vector<bool> (matrix[0].size(), 0));
        cout << "Input Matrix: " << endl;
        printMatrix(matrix);
        int rowTracker, columnTracker;
        rowTracker = 0;
        columnTracker = 0;


        for(int i=0; i < (matrix.size()*matrix.size())/matrix.size(); i++)
        {
            for (int j=0; j<4; j++)
            {
                updateMatrix(matrix, tmp, direction[j], columnTracker, rowTracker, trackExp);
            }
        }
        return tmp;
    }

    void updateMatrix(vector<vector<int>>& matrix, vector<int>& tmp, string& direction, int& columnTracker, int&  rowTracker, vector<vector<bool>>& trackExp)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int t1 = 0;
        int t2, t3, t4;


        if (direction == "right")
        {
            
            for (int a=columnTracker; a<col; a++)
            {
                if (trackExp[rowTracker][a] == 0)
                {
                    tmp.push_back(matrix[rowTracker][a]);
                    columnTracker = a;
                    trackExp[rowTracker][a] = 1;
                }
            }
        }
        else if (direction == "down")
        {
            rowTracker++;
            for (int a=rowTracker; a<row; a++)
            {
                if (trackExp[a][columnTracker] == 0)
                {
                    tmp.push_back(matrix[a][columnTracker]);
                    rowTracker = a;
                    trackExp[a][columnTracker] = 1;
                }
            }
        }
        else if (direction == "left")
        {
            columnTracker--;
            for (int a=columnTracker; a>=0; a--)
            {
                if (trackExp[rowTracker][a] == 0)
                {
                    tmp.push_back(matrix[rowTracker][a]);
                    columnTracker = a;
                    trackExp[rowTracker][a] = 1;
                }
            }
        }
        else if (direction == "up")
        {
            rowTracker--;
            for (int a=rowTracker; a>0; a--)
            {
                if (trackExp[a][columnTracker] == 0)
                {
                    tmp.push_back(matrix[a][columnTracker]);
                    rowTracker = a;
                    trackExp[a][columnTracker] = 1;
                }
            }
        }
        else
        {
            cerr << "Invalid direction";
        }
    }

    template <typename T>
    void printVector(std::vector<T>& v)
    {
        std::cout << "Vector is: \n" <<  "{ ";
        for(int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

    template <typename T>
    void printMatrix(std::vector<std::vector<T>>& m)
    {
        int row = m.size();
        int col = m[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << m[i][j] << "   ";
            }
            std::cout << std::endl;
        }
    }

};

int main()
{
    Matrix m1;
    vector<vector<int>> ma1 = {
                {1,2,3}, 
                {4,5,6},
                {7,8,9}
            };
    vector<vector<int>> m2 = {
                {1,2,3,4}, 
                {5,6,7,8},
                {9,10,11,12}
            };
    vector<vector<int>> m3 = {
                {1,2,3,4}, 
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}
            };

        vector<vector<int>> m5 = {
            {  1,  2,  3,  4,  5 },
            {  6,  7,  8,  9, 10 },
            { 11, 12, 13, 14, 15 },
            { 16, 17, 18, 19, 20 },
            { 21, 22, 23, 24, 25 }
        };
        vector<vector<int>> m6 = {
            {  1,  2,  3,  4,  5,  6 },
            {  7,  8,  9, 10, 11, 12 },
            { 13, 14, 15, 16, 17, 18 },
            { 19, 20, 21, 22, 23, 24 },
            { 25, 26, 27, 28, 29, 30 },
            { 31, 32, 33, 34, 35, 36 }
        };
        vector<vector<int>> m7 = {
            {  1,  2,  3,  4,  5,  6,  7 },
            {  8,  9, 10, 11, 12, 13, 14 },
            { 15, 16, 17, 18, 19, 20, 21 },
            { 22, 23, 24, 25, 26, 27, 28 },
            { 29, 30, 31, 32, 33, 34, 35 },
            { 36, 37, 38, 39, 40, 41, 42 },
            { 43, 44, 45, 46, 47, 48, 49 }
        };
    auto result = m1.spiralOrder(m2);
    m1.printVector(result);
}

// [0][0]
// [0][1]
// [0][2]
// [1][2]
// [2][2]
// [2][1]
// [2][0]
// [1][0]
// [1][1]

// 0 0 
// 0 1
// 0 2 
// 0 3
// 1 3 
// 2 3
// 2 2
// 2 1
// 2 0
// 1 0
// 1 1
// 1 2
