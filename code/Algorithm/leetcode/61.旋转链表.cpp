/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (40.55%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    84.6K
 * Total Submissions: 208.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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

// 先计算链表长度, 与移动距离k进行求余运算, 得余数n
// 为0则无需移动之间返回head
// 将链表移动到第(len - n)个节点, 并截断,  将后半部分最后一个节点的next指向head即可

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;

        int len = 0;
        ListNode *p = head;
        while (p != nullptr)
        {
            len++;
            p = p->next;
        }

        int n = k % len;

        if (len == 1 || n == 0)
            return head;

        int t = len - n;

        ListNode *pp = head;
        ListNode *pre;

        while (t > 0)
        {
            if (t == 1)
                pre = pp;

            pp = pp->next;
            t--;
        }

        ListNode *res = pp;
        while (pp->next != nullptr)
            pp = pp->next;

        pp->next = head;
        pre->next = nullptr;

        return res;
    }
};
// @lc code=end
