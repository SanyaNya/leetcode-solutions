#include <vector>
#include <unordered_set>

//https://leetcode.com/problems/contains-duplicate/

//space complexity: O(n) allocating set of nums

//time complexity: O(n) iterating once over nums, get count of element in set is O(1)

class Solution {
public:
    static bool containsDuplicate(const std::vector<int>& nums)
    {
        std::unordered_set<int> numset(nums.size());

        for(int n : nums)
        {
            //check if set already have n
            if(numset.count(n) == 1) return true;

            //add n to set
            numset.insert(n);
        }

        //no duplicates
        return false;
    }
};
