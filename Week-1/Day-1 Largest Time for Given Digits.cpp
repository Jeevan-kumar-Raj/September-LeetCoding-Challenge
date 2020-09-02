Day-1 Largest Time for Given Digits.cpp



/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9




*/


// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string result;
        sort(A.begin(), A.end(), greater<int>());
        do {
            if (A[0] * 10 + A[1] < 24 && A[2] < 6) {
                for (const auto& i : A) {
                    if (result.length() == 2) {
                        result += ":";
                    }
                    result += to_string(i);
                }
                break;
            }
        } while (next_permutation(A.begin(), A.end(), greater<int>()));
        return result;
    }
};