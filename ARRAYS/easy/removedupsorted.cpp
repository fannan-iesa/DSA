#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int k=1;
        int n=nums.size();
        for(int i=1; i<n;i++){
            if(nums[i] != nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
        };
        return k;
            
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int newLength = solver.removeDuplicates(nums);

    std::cout << "New length after removing duplicates: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}