#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n=nums.size();
        int psum=0;
        int c=0;
        std::unordered_map<int, int> mpp;

        mpp[0]=1;
        for(int i=0; i<n; i++){
            psum+=nums[i];
            
            if(mpp.find((psum-k))!=mpp.end()){
                c=c+mpp[psum-k];
            }
            mpp[psum]++;
        }
        return c;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {1, 2, 3};
    int k = 3;

    int count = solver.subarraySum(nums, k);

    std::cout << "Number of subarrays with sum " << k << ": " << count << std::endl;

    return 0;
}