#include <vector>
#include <utility>
#include <unordered_map>

//https://leetcode.com/problems/two-sum/

class Solution {
public:
  //get map of nums with corresponding index
  static auto get_nummap(const std::vector<int>& nums)
  {
    std::unordered_map<int, int> nummap(nums.size());

    for(int i = 0; i != nums.size(); ++i)
      nummap.emplace(nums[i], i);

    return nummap;
  }

  static std::vector<int> twoSum(const std::vector<int>& nums, int target)
  {
    const auto nummap = get_nummap(nums);

    //search num in nummap that in sum with nums[i] gives target
    for(int i = 0; i != nums.size(); ++i)
      if(auto it = nummap.find(target - nums[i]); 
       it != nummap.end() && it->second != i)
        return std::vector<int>{i, it->second};

    //no solution
    return std::vector<int>{0,0};
  }
};
