#include <vector>
#include <numeric>

//https://leetcode.com/problems/missing-number/

//space complexity: O(1) no extra allocations

//time complexity: O(n) iterating once over nums

class Solution
{
public:
  static int missingNumber(const std::vector<int>& nums) noexcept
  {
    //example:
    //0^1^2^3^4 ^
    //0^1^ ^3^4 =
    //0^0^2^0^0 = 2
    unsigned r = nums.size(); //include last index here
    for(unsigned i = 0; i != nums.size(); ++i)
      r ^= i ^ nums[i];
    return r;
  }
};
