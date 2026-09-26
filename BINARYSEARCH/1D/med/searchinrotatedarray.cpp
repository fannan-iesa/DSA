#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1, low=0;
        int mid;

        while(high>=low){
            mid=high+low/2;
            if (nums[mid]==target){
                return mid;
            }
            //checking if left is sorted or right is 
            if(nums[low]>nums[mid]){
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
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums={4,5,6,7,0,1,2};
    cout<<s.search(nums, 0);
}