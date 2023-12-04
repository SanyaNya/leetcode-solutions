#include <cstdint>
#include <iostream>

//https://leetcode.com/problems/reverse-bits/

//space complexity: O(1) no extra allocations

//time complexity: O(1) fixed set of operations

class Solution
{
public:
  static std::uint32_t reverseBits(std::uint32_t n) noexcept
  {
    n = (n >> 16) | (n << 16);                             //swap 2 bytes
    n = ((n >> 8) & 0x00ff00ff) | ((n & 0x00ff00ff) << 8); //swap swap bytes
    n = ((n >> 4) & 0x0f0f0f0f) | ((n & 0x0f0f0f0f) << 4); //swap 1/2 bytes
    n = ((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2); //swap 1/4 bytes
    n = ((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1); //swap bits
    
    return n;
  }
};
