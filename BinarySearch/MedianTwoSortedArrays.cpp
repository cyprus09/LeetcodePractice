#include <vector>

using namespace std;

//brute force approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> merged(n);
        
        int i = 0, j = 0, k = 0;
        // while (i < nums1.size() && j < nums2.size()) {
        //     if (nums1[i] <= nums2[j]) {
        //         merged[k++] = nums1[i++];
        //     } else {
        //         merged[k++] = nums2[j++];
        //     }
        // }
        
        while (i < nums1.size()) {
            merged[k++] = nums1[i++];
        }
        
        while (j < nums2.size()) {
            merged[k++] = nums2[j++];
        }

        //can replace commented code out to just sort at once
        sort(merged.begin(), merged.end());
        
        if (n % 2 != 0) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};

//optimal binary search approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int left = (n1 + n2 + 1) >> 1;

        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1) return max(l1, l2);
                else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return 0;
    }
};