#include <vector>

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//space complexity: O(1) constant, just a few variables

//time complexity: O(n) iterating once over prices vector, all operations in cycle O(1)

class Solution {
public:
  static int maxProfit(const std::vector<int>& prices)
  {
    int min = prices.front();
    int max = prices.front();
    int max_profit = max - min;

    for(int p : prices)
    {
      if(p < min)
      {
        //after finding new min reset max
        min = p;
        max = p;
      }
      else if(p > max)
      {
        //check profit after finding new max
        max = p;
        const int profit = max - min;
        if(profit > max_profit)
            max_profit = profit;
      }
    }

    return max_profit;
  }
};
