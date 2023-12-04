#include <vector>

//https://leetcode.com/problems/container-with-most-water/

//space complexity: O(1) no extra allocations

//time complexity: O(n) two pointer method

class Solution {
public:
  static int maxArea(const std::vector<int>& height) noexcept
  {
    auto l = height.begin();
    auto r = std::prev(height.end());
    int max_area = 0;

    //iterate over all possible widths
    //and find max_area
    while(l != r)
    {
      const auto lh = *l;
      const auto rh = *r;
      const auto b = std::min(lh, rh);
      max_area = std::max(max_area, int(b * std::distance(l, r)));

      //decrease width
      //pick only highest borders
      if(lh < rh) ++l;
      else --r;
    }

    return max_area;
  }
};
