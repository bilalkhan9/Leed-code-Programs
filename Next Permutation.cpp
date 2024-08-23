#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return;

    
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    
    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    
    int j = n - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }

    
    swap(nums[i], nums[j]);

    
    reverse(nums.begin() + i + 1, nums.end());
}

void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(1);

    vector<int> nums3;
    nums3.push_back(1);
    nums3.push_back(1);
    nums3.push_back(5);

    cout << "Input: ";
    printVector(nums1);
    nextPermutation(nums1);
    cout << "Output: ";
    printVector(nums1); 

    cout << "Input: ";
    printVector(nums2);
    nextPermutation(nums2);
    cout << "Output: ";
    printVector(nums2); 

    cout << "Input: ";
    printVector(nums3);
    nextPermutation(nums3);
    cout << "Output: ";
    printVector(nums3); 
	system("pause");
    return 0;
}
