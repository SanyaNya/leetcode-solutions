#include <vector>

//https://leetcode.com/problems/search-in-rotated-sorted-array/

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

class Solution
{
public:
  static auto rotation_point(const std::vector<int>& nums) noexcept
  {
    //algo is similiar to binary search
    //if middle less than right then assign right to middle
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

    return l;
  }

  static int search(const std::vector<int>& nums, const int target) noexcept
  {
    const auto rp = rotation_point(nums);

    //find target in left or right side
    const auto it = target >= *rp && target <= nums.back() ? 
      std::lower_bound(rp, nums.end(), target) :
      std::lower_bound(nums.begin(), rp, target);
        
    //return index of target otherwise -1
    return (it != nums.end() && *it == target) ? 
      std::distance(nums.begin(), it) : 
      -1;
  }
};
