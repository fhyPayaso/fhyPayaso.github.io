/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.01%)
 * Likes:    690
 * Dislikes: 0
 * Total Accepted:    133.1K
 * Total Submissions: 229.5K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *res = nullptr;
        ListNode *pc = nullptr;

        while (p1 != nullptr && p2 != nullptr)
        {

            int v1 = p1->val;
            int v2 = p2->val;

            ListNode *cur = new ListNode(v1 < v2 ? v1 : v2);
            if (v1 <= v2)
                p1 = p1->next;
            else
                p2 = p2->next;

            if (res == nullptr)
            {
                res = cur;
                pc = cur;
            }
            else
            {
                pc->next = cur;
                pc = pc->next;
            }
        }

        if (p1 == nullptr)
            pc->next = p2;
        else if (p2 == nullptr)
            pc->next = p1;

        return res;
    }
};
// @lc code=end
