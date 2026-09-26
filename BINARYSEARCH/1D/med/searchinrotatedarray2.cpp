#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1, low=0;
        int mid;
        int c=1;

        while(high>=low){
            mid=(high+low)/2;
            if(nums[mid]==target || nums[low]==target || nums[high]==target){
                return true;
            }
             
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low++;
                high--;
                continue;
            }else if(nums[low]>nums[mid]){
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                if(target<=nums[mid] && target>=nums[low]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums={2,5,6,0,0,1,2};
    cout<<s.search(nums, 0);
}