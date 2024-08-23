#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector< vector<int> > fourSum(vector<int>& nums, int target) {
    vector< vector<int> > result;  
    if (nums.size() < 4) return result;  

    sort(nums.begin(), nums.end());  

    for (size_t i = 0; i < nums.size() - 3; ++i) {
        
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (size_t j = i + 1; j < nums.size() - 2; ++j) {
            
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            size_t left = j + 1;
            size_t right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);
                    quad.push_back(nums[left]);
                    quad.push_back(nums[right]);
                    
                    result.push_back(quad);
                    

                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }

    return result;
}


int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(-1);
    nums1.push_back(0);
    nums1.push_back(-2);
    nums1.push_back(2);

    int target1 = 0;
    vector< vector<int> > result1 = fourSum(nums1, target1);

    cout << "Quadruplets for target " << target1 << ": ";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); ++j) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);

    int target2 = 8;
    vector< vector<int> > result2 = fourSum(nums2, target2);

    cout << "Quadruplets for target " << target2 << ": ";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result2[i].size(); ++j) {
            cout << result2[i][j];
            if (j < result2[i].size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;
	system("pause");
    return 0;
}
