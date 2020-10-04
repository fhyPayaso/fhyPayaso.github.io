/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (73.91%)
 * Likes:    570
 * Dislikes: 0
 * Total Accepted:    111.2K
 * Total Submissions: 150.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

#include <vector>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

/**
 * 
 *  二分建树 
 * 
*/
class Solution
{
public:
    TreeNode *div(vector<int> &nums, int start, int end)
    {
        if (end < start)
            return nullptr;
        if (start == end)
            return new TreeNode(nums[start]);

        int mid = (start + end) / 2;
        TreeNode *res = new TreeNode(nums[mid]);
        res->left = div(nums, start, mid - 1);
        res->right = div(nums, mid + 1, end);

        return res;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int len = nums.size();
        if (len == 0)
            return nullptr;

        int index = len / 2;
        TreeNode *res = new TreeNode(nums[index]);
        res->left = div(nums, 0, index - 1);
        res->right = div(nums, index + 1, len - 1);

        return res;
    }
};
// @lc code=end
