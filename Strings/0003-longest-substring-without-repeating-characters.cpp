/*
Problem: 3. Longest Substring Without Repeating Characters
Difficulty: Medium
Topic: String, Brute Force

Approach:
For every starting index, build the substring one character at a
time. Before adding a character, check whether it already exists
in the current substring. Stop when a duplicate is found and keep
track of the maximum substring length.

Time Complexity: O(n^3) worst case
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int length = 0 ;

        for (int i=0;i<n;i++){
            string current = "" ;

            for(int j=i; j<n; j++){
                if (current.find(s[j]) != string::npos){
                    break;
                }

                current+= s[j];
                length = max(length, (int) current.size());

            }
        }

        return length;

    }
};

// optimised solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {

            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};