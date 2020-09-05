Day-4 Partition Labels.cpp



/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
 



 */



// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < S.length(); ++i) {
            lookup[S[i]] = i;
        }
        int first = 0, last = 0;
        vector<int> result;
        for (int i = 0; i < S.length(); ++i) {
            last = max(last, lookup[S[i]]);
            if (i == last) {
                result.emplace_back(i - first + 1);
                first = i + 1;
            }
        }
        return result;
    }
};
