/*
  Permutation Sequence

  The set [1,2,3,бн,n] contains a total of n! unique permutations.

  By listing and labeling all of the permutations in order,
  We get the following sequence (ie, for n = 3):

  "123"
  "132"
  "213"
  "231"
  "312"
  "321"
  Given n and k, return the kth permutation sequence.

  Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        int p[n]; // p[i] represents the number of permutation(i).
        p[0] = 0; p[1] = 1;
        for (int i=2; i<n; i++) p[i] = p[i-1] * i;

        bool isUsed[n]; // isUsed[i] represents whether i+1 appears before.
        for (int i=0; i<n; i++) isUsed[i] = false;

        k--;
        string permutation = "";
        int rank;
        for (int i=n-1; i>=0; i--) {
            // Find the rank of ith element from the left.
            if (i>0) rank = k / p[i];
            else rank = k;

            // Find the rank-th element in no-show ascending elements.
            int element = -1, cnt = 0;
            while (cnt <= rank) {
                element++;
                if (!isUsed[element]) cnt++;
            }
            isUsed[element] = true;
            permutation += (char)(element+1+'0');
            k -= rank * p[i];
        }

        return permutation;
    }
};