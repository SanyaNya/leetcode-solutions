#include <vector>

//https://leetcode.com/problems/3sum/

//space complexity: O(1) no extra allocations except result vector

//time complexity: O(n^2) iterating over nums(O(n)) and finding with two pointer method(O(n)) sum which gives zero with current element

class Solution
{
public:
  static auto threeSum(std::vector<int>& nums) noexcept
  {
    std::vector<std::vector<int>> res;

    std::sort(nums.begin(), nums.end());

    //Iterating over nums
    for(int i = 0; i < nums.size() - 2;)
    {
      int l = i + 1;
      int r = nums.size() - 1;
      const int num = nums[i];
      const int target = -num;

      //Two pointer method
      //find ln + rn == -num
      while(l != r)
      {
        const int ln = nums[l];
        const int rn = nums[r];

        if(ln + rn < target) ++l;
        else if(ln + rn > target) --r;
        else
        {
          res.push_back({num, ln , rn});

          while(ln == nums[l] && l != r) ++l; //skip ln duplicates also increment l
          while(rn == nums[r] && l != r) --r; //skip rn duplicates also increment r
        }
      }

      while(nums[i] == num && i < nums.size() - 2) ++i; //skip num duplicates also increment i
    }

    return res;
  }
};
