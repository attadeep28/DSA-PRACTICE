
#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root,*temp;
        vector<int> post;
        while(!st.empty() or cur != NULL){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top(), st.pop();
                        post.push_back(temp->val);
                    }
                }
                else 
                    cur = temp;
            }
        }

        return post;
    }
};