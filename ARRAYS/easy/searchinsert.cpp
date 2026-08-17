#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int searchinsert(std::vector<int>& nums, int target){
        int n=nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==target){
                return i;
            }else if(nums[i]>target){
                return i;
            }else if(i==n-1){
                return n;
            }
        }
        return 0;
    }
};

int main(){
    Solution solver;
    std::vector<int> num={1,3,4,7};
    int target=6;

    std::cout<< solver.searchinsert(num,target);

    }