#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int low, int high, int target) {
    int mid=(low+high)/2;
    if(low>high){
        return -1;
    }else if(arr[mid]==target){
        return mid;
    }else if(arr[mid]>target){
        high=mid-1;
        return binarySearch(arr, low, high, target);
    }else{
        low=mid+1;
        return binarySearch(arr, low, high, target);
    }
} 

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int result = binarySearch(arr, 0, arr.size() - 1, target);
    if(result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}

