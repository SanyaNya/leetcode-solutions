#include <vector>
#include <cmath>

//https://leetcode.com/problems/counting-bits/

//space complexity: O(1) no extra allocations except result

//time complexity: O(n) n times push to vector 

//0000 result = 0<--
//0001             |
//0010 result =    |<-- + 1
//0011                |
//0100                |
//0101                |
//0110                |
//0111                |
//1000                |
//1001                |
//1010 result =       | + 1
//1011
//1100
//1101
//1110
//1111

class Solution
{
public:
  static std::vector<int> countBits(unsigned n) noexcept
  {
    ++n;

    std::vector<int> res;
    res.reserve(n);

    res.push_back(0);

    for(unsigned i = 1; i != n; ++i)
      res.push_back(res[i - (1 << unsigned(std::log2(i)))] + 1);

    return res;
  }
};
