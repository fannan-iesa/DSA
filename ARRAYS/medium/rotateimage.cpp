#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n=matrix[0].size();
        int c;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                matrix[j].push_back(matrix[i][j]);
            }
            
        }
         for(int x=0;x<n;x++){
            matrix[x].erase(matrix[x].begin(), matrix[x].begin() + n);
         }
    }
};

int main() {
    Solution solver;

    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    solver.rotate(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}