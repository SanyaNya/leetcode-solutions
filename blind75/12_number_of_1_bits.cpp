#include <cstdint>

//https://leetcode.com/problems/number-of-1-bits/

//space complexity: O(1) int has fixed number of bits

//time complexity: O(1) int has fix number of bits

class Solution
{
public:
  static int hammingWeight(std::uint32_t n) noexcept
  {
    unsigned count = 0;

    while(n)
    {
      count += n & 1; //increment count if LSB is 1
      n >>= 1; //move to next bit
    }

    return count;
  }
};
