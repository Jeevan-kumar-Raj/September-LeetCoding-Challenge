Day-1 Length of Last Word.cpp


/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5


*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        const auto is_space = [](const char c) { return isspace(c); };
        const auto it = find_if_not(s.rbegin(), s.rend(), is_space);
        const auto jt = find_if(it, s.rend(), is_space);
        return distance(it, jt);
    }
};