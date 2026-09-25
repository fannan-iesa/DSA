#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        vector<int> arr;
        int ans=-1;

        while(high>=low){
            int mid=(high +low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }

        }
        arr.push_back(ans);

        ans=-1;
        low=0;
        high=n-1;

        while(high>=low){
            int mid=(high +low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }

        }
        arr.push_back(ans);

        return arr;
    }
};

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution solution;
    std::vector<int> result = solution.searchRange(nums, target);
    std::cout << "First and last position of target: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}