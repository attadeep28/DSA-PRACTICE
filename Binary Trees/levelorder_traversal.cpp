#include <bits/stdc++.h>
using namespace std;

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
private:
    vector<vector<int>> bfs(TreeNode *root)
    {
        vector<int> dum;
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                dum.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            else if (!q.empty())
            {
                ans.push_back(dum);
                dum.clear();
                q.push(NULL);
            }
        }
        ans.push_back(dum);
        return ans;
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        ans = bfs(root);

        return ans;
    }
};
int main()
{

    return 0;
}