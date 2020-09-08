Day-1 Sum of Root To Leaf Binary Numbers.cpp



/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.




*/


  
// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafHelper(root, 0);
    }

private:
    int sumRootToLeafHelper(TreeNode* root, int val) {
        static const int M = 1e9 + 7;
        if (!root) {
            return 0;
        }
        val = (val * 2 + root->val) % M;
        if (!root->left && !root->right) {
            return val;
        }
        return (sumRootToLeafHelper(root->left, val) +
                sumRootToLeafHelper(root->right, val)) % M;
    }
};