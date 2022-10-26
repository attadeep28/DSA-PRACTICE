#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *n = st.top();
            st.pop();
            if (n)
                ans.push_back(n->val);
            if (n->right)
                st.push(n->right);
            if (n->left)
                st.push(n->left);
        }

        return ans;
    }
};
int main()
{
    // preorder root - left - right

    return 0;
}