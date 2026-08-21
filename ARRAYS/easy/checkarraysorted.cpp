#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    bool check(std::vector<int>& nums) {
        int n=nums.size();
        int minn=0;
        int c;
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                minn=i+1;
                break;
            }
        };

        for(int j=0; j<n-1; j++){
            c= (minn+j) % n;
            if( nums[c] > nums[(c+1)%n] ){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {3, 4, 5, 1, 2};

    bool isSorted = solver.check(nums);

    if (isSorted) {
        std::cout << "The array is sorted and rotated." << std::endl;
    } else {
        std::cout << "The array is not sorted and rotated." << std::endl;
    }

    return 0;
}