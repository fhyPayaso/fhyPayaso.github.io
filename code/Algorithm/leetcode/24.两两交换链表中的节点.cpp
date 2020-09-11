/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (66.48%)
 * Likes:    618
 * Dislikes: 0
 * Total Accepted:    147.9K
 * Total Submissions: 221.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr)
            return head;
        
        ListNode *p = head;
        ListNode *resHead = nullptr;
        ListNode *preNode = nullptr;
        while (p != nullptr)
        {

            ListNode *curNode = p;
            ListNode *nextNode = p->next;
            if (nextNode == nullptr)
            {
                if (resHead == nullptr)
                    resHead = curNode;
                break;
            }

            curNode->next = nextNode->next;
            nextNode->next = curNode;

            if (preNode == nullptr)
                resHead = nextNode;
            else
                preNode->next = nextNode;
            preNode = curNode;
            p = curNode->next;
        }
        return resHead;
    }
};
// @lc code=end
