/*
  Given an array S of n integers, are there elements a, b, c in S such
  that a + b + c = 0? Find all unique triplets in the array which gives
  the sum of zero.

  Note:
  Elements in a triplet (a,b,c) must be in non-descending order.(ie, a ¡Üb ¡Üc)
  The solution set must not contain duplicate triplets.
  For example, given array S = {-1 0 1 2 -1 -4},
  A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int n = num.size(), i, j, k;
        for (i=0; i<n-2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            j = i+1;
            k = n-1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[j];
                    tmp[2] = num[k];
                    result.push_back(tmp);
                    j++;
                    k--;
                    while (j<k && num[j]==num[j-1]) j++;
                    while (j<k && num[k]==num[k+1]) k--;
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
            }
        }
        return result;
    }
};
