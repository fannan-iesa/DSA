#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int high=n-1, low=0;
        int mid;

        if(n==1){
            return 0;
        }
        
        while(high>=low){
            mid=(high+low)/2;
            if(mid==0 || mid==n-1){
                if(nums[high]>nums[low]){
                    return high;
                }else{
                    return mid;
                }
            }
            if(nums[mid+1]>nums[mid] && nums[mid-1]<nums[mid]){
                low=mid+1;
            }else if(nums[mid+1]<nums[mid] && nums[mid-1]>nums[mid]){
                high=mid-1;
            }else if(nums[mid+1]<nums[mid] && nums[mid-1]<nums[mid]){
                return mid;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,2,3,1};
    cout<<s.findPeakElement(nums);
}