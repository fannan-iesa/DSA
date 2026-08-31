#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target) {
    int n=arr.size();
    int low=0;
    int high=n-1;

    while(high>=low){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }else if(target<arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int result = binarySearch(arr, target);
    if(result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}
