#include <vector>

// https://leetcode.com/problems/climbing-stairs

// space complexity: O(1) no extra allocations

// time complexity: O(N) n iterations

// f(n) = f(n-1) + f(n-2)

class Solution
{
public:
  static unsigned climbStairs(unsigned n) noexcept
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    unsigned prev1 = 2; // f(2) (f(n-1))
    unsigned prev2 = 1; // f(1) (f(n-2))
    unsigned r;
    for (unsigned i = 3; i != n + 1; ++i)
    {
      // f(i) = f(i-2) + f(i-1)
      r = prev1 + prev2;

      // calculate f(i-2) and f(i-1) for the next step

      // f(i-2) = f(i-1)
      prev2 = prev1;

      // f(i-1) = f(i);
      prev1 = r;
    }

    return r;
  }
};
