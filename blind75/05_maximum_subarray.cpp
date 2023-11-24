#include <vector>
#include <algorithm>

//https://leetcode.com/problems/maximum-subarray/

//space complexity: O(1) no extra allocations

//time complexity: O(n) iterating once over nums

class Solution {
public:
  static int maxSubArray(const std::vector<int>& nums) noexcept
  {
    int s = 0;
    int max_s = nums.front();

    for(int n : nums)
    {
      //calculate sum of range
      s += n;

      if(s > max_s) max_s = s;

      //if sum less than 0 exclude subrange
      if(s < 0) s = 0;
    }

    return max_s;
  }
};
