/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.36%)
 * Total Accepted:    2.5K
 * Total Submissions: 5.5K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
 * 
 * 
 */
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
    int MAX = 9999999;

    int firstMin = MAX;

    int secondMin = MAX;

    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == nullptr)
            return secondMin;

        // 如果小于最小值，分别更新即可
        if (root->val < firstMin)
        {
            if (firstMin != MAX)
                secondMin = firstMin;
            firstMin = root->val;
        }

        // 两值更新，只更新次小值
        if (root->val > firstMin && secondMin > root->val)
            secondMin = root->val;

        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);

        return secondMin == MAX ? -1 : secondMin;
    }
};
