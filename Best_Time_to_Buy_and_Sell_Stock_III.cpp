/*
  Best Time to Buy and Sell Stock III

  Say you have an array for which the ith element is the price of a given stock
  on day i.

  Design an algorithm to find the maximum profit. You may complete at most two
  transactions.

  Note:
  You may not engage in multiple transactions at the same time (ie, you must
  sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> forward(n, 0), backward(n, 0);
        
        int min = prices[0];
        for (int i=1; i<n; i++) {
            if (prices[i] < min) min = prices[i];
            forward[i] = (forward[i-1] > prices[i] - min) ?  forward[i-1] : prices[i] - min;
        }
        
        int max = prices[n-1];
        for (int i=n-2; i>=0; i--) {
            if (prices[i] > max) max = prices[i];
            backward[i] = (backward[i+1] > max - prices[i]) ? backward[i+1] : max - prices[i];
        }
        
        int result = 0;
        for (int i=0; i<n; i++) {
            if (forward[i] + backward[i] > result) 
                result = forward[i] + backward[i];
        }
        return result;
   }
};
