//https://leetcode.com/problems/sum-of-two-integers/

//space complexity: O(1) int has fixed number of bits

//time complexity: O(1) int has fix number of bits

class Solution
{
public:
  static int getSum(int a, int b) noexcept
  {
    //if b(carry) is zero just return a
    if(!b) return a;

    //return sum of sum=a^b carry=(a&b)<<1
    return getSum(a ^ b, (a & b) << 1);
  }
};
