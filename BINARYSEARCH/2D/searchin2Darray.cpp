#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int high=n-1, low=0;
        int high1, low1;
        int mid, mid1;

        while(high>=low){
            mid=(high+low)/2;
            high1=m-1, low1=0;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                while(high1>=low1){
                    mid1=(high1 + low1)/2;
                    if(matrix[mid][mid1]==target){
                        return true;
                    }else if(matrix[mid][mid1]>target){
                        high1=mid1-1;
                    }else{
                        low1=mid1+1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(matrix, 3);
}