/*
  Find Peak Element

  A peak element is an element that is greater than its neighbors.

  Given an input array where num[i] ¡Ù num[i+1], find a peak element and return
  its index.

  The array may contain multiple peaks, in that case return the index to any
  one of the peaks is fine.

  You may imagine that num[-1] = num[n] = -¡Þ.

  For example, in array [1, 2, 3, 1], 3 is a peak element and your function
  should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();

        // To find one of the peek elements by binary chop.
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            // There must be at least one peak element in num[l]..num[mid-1].
            if (mid > 0 && num[mid] < num[mid-1]) {
                r = mid - 1;
            }
            // There must be at least one peak element in num[mid+1]..num[r].
            else if (mid < n - 1 && num[mid] < num[mid+1]) {
                l = mid + 1;
            }
            // num[mid] is one of the peek elements.
            else {
                return mid;
            }
        }
        return l;
    }
};
