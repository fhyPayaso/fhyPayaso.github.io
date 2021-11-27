#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <vector>

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
    int search(int &order, int k, TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        int res;
        if (root->right != nullptr)
            res = search(order, k, root->right);

        if (res == -1)
        {
            order++;
            if (order == k)
                return root->val;
        }
        else
            return res;

        if (root->left != nullptr)
            res = search(order, k, root->left);

        return res;
    }

    int kthLargest(TreeNode *root, int k)
    {
        int order = 0;
        return search(order, k, root);
    }
};