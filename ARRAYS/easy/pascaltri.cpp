#include <iostream>
#include <vector>
#include <algorithm> 
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> arr1(numRows);

        for(int i=0; i<numRows; i++){
            arr1[i].resize(i+1);
            arr1[i][0]=1;
            arr1[i][i]=1;
            for(int j=1; j<i; j++){
                arr1[i][j]=(arr1[i-1][j-1] + arr1[i-1][j]);
            }
        }
        return arr1;
    }
};

int main() {
    Solution solver;

    int numRows = 5;
    std::vector<std::vector<int>> triangle = solver.generate(numRows);

    std::cout << "Pascal's Triangle with " << numRows << " rows:" << std::endl;
    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}