/*
  Find Minimum in Rotated Sorted Array

  Suppose a sorted array is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

  Find the minimum element.

  You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();

        // To find the minimum by binary chop.
        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l + r) >> 1;
            // There must be a sorted sub-array.
            if (num[l] < num[r]) return num[l];

            // The minimum must be in num[l]..num[mid].
            if (num[mid] <= num[l] && num[mid] <= num[r]) {
                r = mid;
            }
            // The minimum must be in num[mid+1]..num[r].
            else {
                l =  mid + 1;
            }
        }
        return num[r];
    }
};
