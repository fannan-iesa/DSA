#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int can1=0, can2=0;
        int c1=0, c2=0;
        int n=nums.size();
        std::vector<int> arr;

        for(int i:nums){
            if(i==can1){
                c1++;
            }else if(i==can2){
                c2++;
            }else if(c1==0){
                can1=i;
                c1=1;
            }else if(c2==0){
                can2=i;
                c2=1;
            }else{
                c1--;
                c2--;
            } 
        }

        c1=0;
        c2=0;
        for(int i:nums){
            if(i==can1){
                c1++;
            }else if(i==can2){
                c2++;
            }
        }

        
        if(c1>(n/3)){
            arr.push_back(can1);
        }
        if(c2>(n/3)){
            arr.push_back(can2);
        }

        return arr;
    }
};
int main() {
    Solution solver;

    std::vector<int> nums = {3, 2, 3};
    std::vector<int> result = solver.majorityElement(nums);

    std::cout << "Majority elements (appearing more than n/3 times): ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}