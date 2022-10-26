#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/binary-tree-inorder-traversal/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int>
    inorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        stack<TreeNode *> st;
        TreeNode *node = root;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}