/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode-cn.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (60.61%)
 * Likes:    648
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 124.2K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 * 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * 
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
 * 
 * 示例 2:
 * 
 * 输入: [3,4,5,1,3,null,1]
 * 
 *     3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // 递归遍历时记录两个值，分别为带有根节点的最大值，和不带根节点的最大值

    void helper(TreeNode *node, int &pr, int &nr)
    {
        if (node == nullptr)
        {
            pr = 0;
            nr = 0;
            return;
        }

        int lpr, lnr;
        helper(node->left, lpr, lnr);
        int rpr, rnr;
        helper(node->right, rpr, rnr);

        pr = lnr + rnr + node->val;         // 带根节点, 直接将子树不带根节点值相加即可
        nr = max(lpr, lnr) + max(rpr, rnr); // 不带根节点，两个子树分别取最大值即可
    }

    int rob(TreeNode *root)
    {
        int pr, nr;
        helper(root, pr, nr);
        // 选择带根节点和不带根节点中最大值即可
        return max(pr, nr);
    }
};
// @lc code=end
