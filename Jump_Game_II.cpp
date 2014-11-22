/*
  Given an array of non-negative integers, you are initially positioned at the
  first index of the array.
  Each element in the array represents your maximum jump length at that
  position.
  Your goal is to reach the last index in the minimum number of jumps.

  For example:
  Given array A = [2,3,1,1,4]
  The minimum number of jumps to reach the last index is 2.
  (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;

        queue<int> q;  // for BFS
        vector<int> cnt(n, 0); // c[i] represents the minimal jumps from 0 to i
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            if (start + A[start] >= n - 1) return cnt[start] + 1;
            for (int i=A[start]; i>0; i--) {
                if (cnt[start+i] == 0) {
                    cnt[start+i] = cnt[start] + 1;
                    q.push(start+i);
                } else {
                // if i has been reached, then i-1 must has been reached too.
                // So just skim others.
                // This makes sure that every position will be pushed once, be
                // popped once and visit at most one unchanged position.
                    break;
                }
            }
            q.pop();
        }

        return -1;
    }
};
