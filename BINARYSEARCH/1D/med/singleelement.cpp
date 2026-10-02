#include <vector>;
#include <iostream>;
#include <algorithm>;
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases for boundary elements it would be better to check here istead of in the loop which i earlier did bcuz of less redundancy 
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        // Search in range [1, n-2] so mid-1 and mid+1 are always safe
        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Found the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Left side is normal pair pattern -> Single element is on the RIGHT
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || 
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } 
            // Otherwise -> Single element is on the LEFT
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << s.singleNonDuplicate(nums);
}