/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (67.03%)
 * Likes:    920
 * Dislikes: 0
 * Total Accepted:    126.5K
 * Total Submissions: 186.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 进阶：
 * 
 * 
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *head = new ListNode(0);
        ListNode *h = head;

        while (h1 != nullptr || h2 != nullptr)
        {
            if (h1 != nullptr && h2 != nullptr)
            {
                if (h1->val <= h2->val)
                {
                    h->next = h1;
                    h1 = h1->next;
                }
                else
                {
                    h->next = h2;
                    h2 = h2->next;
                }
                h = h->next;
            }
            else if (h1 == nullptr && h2 != nullptr)
            {
                h->next = h2;
                h2 = h2->next;
                h = h->next;
            }
            else if (h1 != nullptr && h2 == nullptr)
            {
                h->next = h1;
                h1 = h1->next;
                h = h->next;
            }
        }
        return head->next;
    }

    ListNode *mergeSort(ListNode *h)
    {
        if (h == nullptr || h->next == nullptr)
            return h;

        ListNode *p1 = h;
        ListNode *p2 = h;

        // 寻找中心点
        ListNode *pre;
        while (p2->next != nullptr)
        {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
            if (p2 == nullptr)
                break;
        }

    
        pre->next = nullptr;

        ListNode *left = mergeSort(h);
        ListNode *right = mergeSort(p1);

        return merge(left, right);
    }

    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};
// @lc code=end
