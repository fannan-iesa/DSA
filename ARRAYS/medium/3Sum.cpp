#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> arr;
        int n = nums.size();

        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {continue;};
            int j=i+1;
            int k=n-1;
            while(k>j){
                if((nums[i]+nums[j]+nums[k])==0){
                    arr.push_back({nums[i],nums[j],nums[k]});
                    while (j < k && nums[j] == nums[j + 1]){ j++;}
                    while (j < k && nums[k] == nums[k - 1]){ k--;}
                    j++;
                    k--;
                }else if((nums[i]+nums[j]+nums[k])>0){
                    k--;
                }else if((nums[i]+nums[j]+nums[k])<0){
                    j++;
                }
            }
        }

        return arr;
    }
};
int main(){
    Solution solver;

    std::vector<int> x={-1,0,1,2,-1,-4};

    auto result = solver.threeSum(x);
    for (const auto& triplet : result) {
        for (int val : triplet) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}