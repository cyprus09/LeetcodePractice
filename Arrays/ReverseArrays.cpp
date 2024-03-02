#include <vector>

using namespace std;

//brute force approach
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((long long)nums[i] > 2 * (long long)nums[j]) {
                    count++;
                }
            }
        }
        
        return (int)count;
    }
};


//optimal approach
class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;     
        int right = mid + 1;   

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2 * (long long)arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += countPairs(arr, low, mid, high); //Modification
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

