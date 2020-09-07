Day-6 Image Overlap.cpp


/*Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1





*/


// Time:  O(n^4)
// Space: O(n^2)

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> count(pow(2 * A.size() - 1, 2));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if  (!A[i][j]) {
                    continue;
                }
                for (int m = 0; m < B.size(); ++m) {
                   for (int n = 0; n < B[m].size(); ++n) {
                        if (!B[m][n]) {
                            continue;
                        }
                        ++count[(A.size() - 1 + i - m) * (2 * A.size() - 1) +
                                 A.size() - 1 + j - n];
                   }
                }
            }
        }
        return *max_element(count.cbegin(), count.cend());
    }
};
