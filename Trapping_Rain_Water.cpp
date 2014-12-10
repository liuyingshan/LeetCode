/*
  Trapping Rain Water

  Given n non-negative integers representing an elevation map where the width
  of each bar is 1, compute how much water it is able to trap after raining.

  For example, 
  Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(int A[], int n) {
        stack<int> dec_stack;
        int result = 0;
        for (int i=0; i<n; i++) {
            while (!dec_stack.empty() && A[dec_stack.top()] < A[i]) {
                int horizon = A[dec_stack.top()];
                dec_stack.pop();
                if (!dec_stack.empty()) {
                    int width = i - dec_stack.top() - 1;
                    int height = min(A[dec_stack.top()], A[i]) - horizon;
                    result += width * height;
                }
            }
            dec_stack.push(i);
        }
        return result;
    }
};
