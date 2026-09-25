#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int high=n-1, low=0;
        int mid, ans;

        while(high>=low){
            mid=(high+low)/2;
            if(n==1){
                return nums[0];
            }

            if(nums[mid]>=nums[low] && nums[mid]<=nums[high]){
                ans=nums[mid];
                high=mid-1;
            }else if(nums[mid]>=nums[low] && nums[mid]>=nums[high]){
                ans=nums[mid];
                low=mid+1;
            }else if(nums[mid]<=nums[low] && nums[mid]<=nums[high]){
                if(nums[mid-1]>nums[mid]){
                    ans=nums[mid];
                    break;
                }
                ans=nums[mid];
                high=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,4,5,1,2};
    cout<<s.findMin(nums);
}