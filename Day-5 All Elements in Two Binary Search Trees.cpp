Day-5 All Elements in Two Binary Search Trees.cpp




/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].




*/


class Solution {
public:
   void pushLeft(stack <TreeNode*>& st, TreeNode* root){
      TreeNode* curr = root;
      while(curr){
         st.push(curr);
         curr = curr->left;
      }
   }
   vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector <int> ans;
      stack <TreeNode*> st1, st2;
      TreeNode* curr1 = root1;
      TreeNode* curr2 = root2;
      pushLeft(st1, curr1);
      pushLeft(st2, curr2);
      while(!st1.empty() || !st2.empty()){
         TreeNode* temp;
         if(!st1.empty() && (st2.empty() || st1.top()->val <= st2.top()->val)){
            temp = st1.top();
            st1.pop();
            ans.push_back(temp->val);
            pushLeft(st1, temp->right);
         }
         else{
            temp = st2.top();
            st2.pop();
            ans.push_back(temp->val);
            pushLeft(st2, temp->right);
         }
      }
      return ans;
   }
};