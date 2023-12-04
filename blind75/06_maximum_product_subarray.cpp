#include <vector>

//https://leetcode.com/problems/maximum-product-subarray/

//space complexity: O(1) no extra allocations

//time complexity: O(n) iterating once over nums

class Solution {
public:
    static int maxProduct(const std::vector<int>& nums) noexcept
    {
        int positive_product = 1; //positive product
        int negative_product = 1; //negative product
        int max_p = nums.front();

        for(int n : nums)
        {
            //if n is negative then positive_product*n -> negative_product and negative_product*n -> positive_product
            if(n < 0) std::swap(positive_product, negative_product);

            //calculate product for positive and negative subarray
            //or start new subarray
            positive_product = std::max(n, positive_product*n);
            negative_product = std::min(n, negative_product*n);

            //check new maximum
            max_p = std::max(max_p, positive_product);
        }

        return max_p;
    }
};
