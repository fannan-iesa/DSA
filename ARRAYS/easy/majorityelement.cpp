#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> count_map;
        
        int majority_number = nums[0];
        int max_count = 0;

        for (int num : nums) {
            // 1. Increment frequency count for the current number
            count_map[num]++;

            // 2. If this number's count is the highest seen so far, update our answer
            if (count_map[num] > max_count) {
                max_count = count_map[num];
                majority_number = num; // Save the NUMBER itself, not the count
            }
        }

        return majority_number;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {3, 2, 3};
    int majority = solver.majorityElement(nums);

    std::cout << "The majority element is: " << majority << std::endl;

    return 0;
}