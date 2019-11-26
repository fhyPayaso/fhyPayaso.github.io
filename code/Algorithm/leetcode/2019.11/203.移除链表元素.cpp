/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.75%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 110.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *p = head;
        ListNode *pre = head;

        while (head != nullptr)
        {
            int flag = false;
            int cur = head->val;
            while (cur == val)
            {
                if (head->next != nullptr)
                {
                    head->val = head->next->val;
                    head->next = head->next->next;

                    cur = head->val;
                }
                else
                {

                    pre->next = nullptr;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;

            pre = head;
            head = head->next;
        }

        if (p != nullptr && p->next == nullptr && p->val == val)
        {
            return nullptr;
        }
        return p;
    }
};
// @lc code=end
