#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min
#include <limits>    // For std::numeric_limits

double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    const std::vector<int>& A = nums1;
    const std::vector<int>& B = nums2;
    int m = A.size();
    int n = B.size();

    int imin = 0, imax = m, half_len = (m + n + 1) / 2;
    double max_of_left, min_of_right;

    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        if (i < m && B[j - 1] > A[i]) {
            // Increase i
            imin = i + 1;
        } else if (i > 0 && A[i - 1] > B[j]) {
            // Decrease i
            imax = i - 1;
        } else {
            // i is perfect
            int max_of_left_A = (i == 0) ? std::numeric_limits<int>::min() : A[i - 1];
            int min_of_right_A = (i == m) ? std::numeric_limits<int>::max() : A[i];
            int max_of_left_B = (j == 0) ? std::numeric_limits<int>::min() : B[j - 1];
            int min_of_right_B = (j == n) ? std::numeric_limits<int>::max() : B[j];

            max_of_left = std::max(max_of_left_A, max_of_left_B);
            min_of_right = std::min(min_of_right_A, min_of_right_B);

            if ((m + n) % 2 == 1) {
                return max_of_left;
            } else {
                return (max_of_left + min_of_right) / 2.0;
            }
        }
    }

    // If the code reaches this point, something went wrong. Instead of throwing, we return a default value.
    return -1; // Error indicator, can be handled differently based on your requirements
}

int main() {
    // Use constructor initialization
    std::vector<int> nums1(2);
    nums1[0] = 1;
    nums1[1] = 3;

    std::vector<int> nums2(1);
    nums2[0] = 2;

    double median = findMedianSortedArrays(nums1, nums2);

    if (median == -1) {
        std::cout << "Error: Input arrays are not sorted." << std::endl;
    } else {
        std::cout << "Median of the two sorted arrays: " << median << std::endl;
    }
		system("pause");
    return 0;
}
