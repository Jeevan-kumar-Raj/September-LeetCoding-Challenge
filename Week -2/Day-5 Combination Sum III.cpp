Day-5 Combination Sum III.cpp

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]


*/

// Time:  O(k * C(n, k))
// Space: O(k)

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum3(res, combination, 1, k, n);
        return res;
    }
private:
    void combinationSum3(vector<vector<int> > &res, vector<int> &combination, int start, int k, int n) {
        if (!k && !n) {
            res.push_back(combination);
            return;
        } else if (k < 0) {
            return;
        }

        for (int i = start; i < 10 && n >=  k * i + k * (k - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(res, combination, i + 1, k - 1, n - i);
            combination.pop_back();
        }
    }
};