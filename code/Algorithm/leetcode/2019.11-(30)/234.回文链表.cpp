/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (39.01%)
 * Likes:    315
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 123.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        // 通过快慢节点找到中点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr)
        {
            if (fast->next->next == nullptr)
            {
                fast = fast->next;
                break;
            }
            else
            {
                fast = fast->next->next;
            }
            slow = slow->next;
        }
        // 将后半部分链表倒序
        ListNode *p = slow->next;
        ListNode *nex;
        ListNode *pre = nullptr;
        while (p->next != nullptr)
        {
            nex = p->next;

            p->next = pre;
            pre = p;

            p = nex;
        }
        p->next = pre;
        // 开始判断回文
        ListNode *left = head;
        ListNode *right = p;
        while (left != nullptr && right != nullptr)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end
