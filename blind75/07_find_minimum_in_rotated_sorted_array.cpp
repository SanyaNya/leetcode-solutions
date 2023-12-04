#include <vector>
#include <iostream>

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

//space complexity: O(1) no extra allocations

//time complexity: O(log(n)) binary search

//before
// rotation
//|   |  /
//|   | /
//|   |/
//|   /
//|  /|
//| / |
//|/  |
//---------

//after
// rotation
//|  /
//| /|
//|/ |
//|  |   /
//|  |  /
//|  | /
//|  |/
//---------

//rotation point is the minimum

class Solution {
public:
    static int findMin(const std::vector<int>& nums) noexcept
    {
      //algo is similiar to binary search
      //calculate middle if middle less than right then assign right to middle
      //otherwise assign left to middle
      //until left == right

      auto l = nums.begin();
      auto r = std::prev(nums.end());

      while(l != r)
      {
        auto m = std::next(l, std::distance(l, r) / 2);

        if(*m < *r) r = m;
        else l = std::next(m);
      }

      return *l;
    }
};
