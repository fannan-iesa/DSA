#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;

        while(high>=low){
        mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }else if(target<nums[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
        if(nums[mid]<target){
            return mid+1;
        }else{
            return mid;
        }
    }
};

//BUT!! theres A better way to do this, we can just keep track of the answer and return it at the end, this way we dont have to check if the mid is less than or greater than the target at the end of the loop, we can just return the answer we have been keeping track of.

class Solution1 {
public:
    int BETTER_searchInsert(std::vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=n;

        while(high>=low){
            int mid=(high +low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution1 solution;
    int result = solution.BETTER_searchInsert(nums, target);
    std::cout << "Insert position: " << result << std::endl;

    target = 2;
    result = solution.BETTER_searchInsert(nums, target);
    std::cout << "Insert position: " << result << std::endl;

    target = 7;
    result = solution.BETTER_searchInsert(nums, target);
    std::cout << "Insert position: " << result << std::endl;

    target = 0;
    result = solution.BETTER_searchInsert(nums, target);
    std::cout << "Insert position: " << result << std::endl;

    return 0;
}