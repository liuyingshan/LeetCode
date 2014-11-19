/*
  Find Minimum in Rotated Sorted Array II

  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  Find the minimum element.The array may contain duplicates.
*/

class Solution {
public:
    int findSubMin(vector<int> &num, int l, int r) {
        if (l > r) return LONG_MAX;
        if (l == r) return num[l];

        // Enumerate all relations of num[l] and num[mid], num[mid] and num[r].
        // {num[l]=num[mid], num[l]<num[mid], num[l]>num[mid]} x {num[mid]=num[r], num[mid]<num[r], num[mid]>num[r]}
        // It has 9 conditions, which are redundant.
        // Not to merge synonymic statements in order to improve readability.
        int mid = (l + r) / 2;
        if (num[l] == num[mid] && num[mid] == num[r])
            return std::min(num[l], std::min(findSubMin(num, l+1, mid-1), findSubMin(num, mid+1, r-1)));
        if (num[l] == num[mid] && num[mid] < num[r]) return num[l];
        if (num[l] == num[mid] && num[mid] > num[r]) return findSubMin(num, mid+1, r);
        if (num[l] < num[mid] && num[mid] == num[r]) return num[l];
        if (num[l] < num[mid] && num[mid] < num[r]) return num[l];
        if (num[l] < num[mid] && num[mid] > num[r]) return findSubMin(num, mid+1, r);
        if (num[l] > num[mid] && num[mid] == num[r]) return findSubMin(num, l+1, mid);
        if (num[l] > num[mid] && num[mid] < num[r]) return findSubMin(num, l+1, mid);
        if (num[l] > num[mid] && num[mid] > num[r]) return findSubMin(num, mid+1, r);
    }

    int findMin(vector<int> &num) {
        return findSubMin(num, 0, num.size()-1);
    }
};
