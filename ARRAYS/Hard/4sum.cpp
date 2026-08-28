#include <iostream>
#include <vector>
#include <algorithm> 
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> arr;
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int k=0; k<n-3; k++){
            if (k > 0 && nums[k] == nums[k - 1]) {continue;};
            for(int i=k+1; i<n; i++){
                if (i>k+1 && nums[i] == nums[i - 1]) {continue;};
                int j=i+1;
                int l=n-1;
                while(l>j){
                    long long sum = (long long)nums[k] + nums[i] + nums[j] + nums[l];
                    if(sum==target){
                        arr.push_back({nums[k],nums[i],nums[j],nums[l]});
                        while (j < l && nums[j] == nums[j + 1]){ j++;}
                        while (j < l && nums[l] == nums[l - 1]){ l--;}
                        j++;
                        l--;
                    }else if(sum>target){
                        l--;
                    }else{
                        j++;
                    }
                }
            }
        }
        return arr;
    }
};
int main() {
    Solution solver;

    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int>> result = solver.fourSum(nums, target);

    std::cout << "Quadruplets that sum to " << target << ":" << std::endl;
    for (const auto& quad : result) {
        std::cout << "[";
        for (size_t i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}