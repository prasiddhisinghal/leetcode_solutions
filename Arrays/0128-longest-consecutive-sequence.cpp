/*
Problem: 128. Longest Consecutive Sequence
Difficulty: Medium
Topics: Array, Hash Table

Approach:
Store all numbers in an unordered_set for O(1) average lookup.
For each number, start counting only if its predecessor does not
exist in the set. This ensures that every consecutive sequence is
traversed only once.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int x : nums) {
            s.insert(x);
        }

        int answer = 0;

        for (int x : s) {
            if (s.count(x - 1) == 0) {
                int length = 1;

                while (s.count(x + length)) {
                    length++;
                }

                answer = max(answer, length);
            }
        }

        return answer;
    }
};