/*
Problem: 1. Two Sum
Difficulty: Easy
Topic: Array, Hash Table

Approach:
Check every possible pair of elements and return their indices
when their sum equals the target.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];

                if (sum == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};