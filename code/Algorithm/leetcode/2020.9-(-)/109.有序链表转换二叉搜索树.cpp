/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (76.05%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    59.8K
 * Total Submissions: 78.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int getMiddelVal(int index, ListNode *head)
    {
        ListNode *p = head;
        while (index--)
            p = p->next;
        return p->val;
    }

    TreeNode *div(ListNode *head, int start, int end)
    {
        if (end < start)
            return nullptr;
        if (start == end)
            return new TreeNode(getMiddelVal(start, head));

        int mid = (start + end) / 2;
        TreeNode *res = new TreeNode(getMiddelVal(mid, head));
        res->left = div(head, start, mid - 1);
        res->right = div(head, mid + 1, end);

        return res;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int len =0;
        ListNode *p = head;
        while (p != nullptr)
        {
            len++;
            p = p->next;
        }
        
        if (len == 0)
            return nullptr;

        int index = len / 2;
        TreeNode *res = new TreeNode(getMiddelVal(index, head));
        res->left = div(head, 0, index - 1);
        res->right = div(head, index + 1, len - 1);

        return res;
    }
};
// @lc code=end
