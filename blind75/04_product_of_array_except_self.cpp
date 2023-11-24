#include <vector>
#include <algorithm>
#include <numeric>

//https://leetcode.com/problems/product-of-array-except-self/

//a, b, c,    d,   e, f, g
//|     |     |    |     |
//-------          -------
// prefix  element  suffix

//product of element = prefix * suffix

//space complexity: O(1), no extra allocations(except result vector, but this doesnt count)

//time complexity: O(n), iterating over nums two times

class Solution {
public:
  static std::vector<int> productExceptSelf(const std::vector<int>& nums) noexcept
  {
    std::vector<int> res;
    res.reserve(nums.size());

    //calculate product prefixes
    int p = 1;
    for(int n : nums)
    {
      res.push_back(p);
      p *= n;
    }

    //calculate product suffixes
    p = 1;
    auto res_it = res.rbegin();
    for(auto nums_it = nums.rbegin(); nums_it != nums.rend(); ++nums_it, ++res_it)
    {
      *res_it *= p;
      p *= *nums_it;
    }

    return res;
  }
};
