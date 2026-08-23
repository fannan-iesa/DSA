#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> 

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0; i<n ; i++){
            if(nums[i] != 0){
                std::swap(nums[k], nums[i]);
                k++;
            }
            
        }
        
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {0, 1, 0, 3, 12};

    solver.moveZeroes(nums);

    std::cout << "Array after moving zeroes: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}