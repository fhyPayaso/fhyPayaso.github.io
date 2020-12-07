/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (53.59%)
 * Likes:    1031
 * Dislikes: 0
 * Total Accepted:    192.9K
 * Total Submissions: 359K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
#include <vector>
using namespace std;

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

    ListNode *divConter(vector<ListNode *> list, int left, int right)
    {
        if (left > right)
            return nullptr;

        if (left == right)
            return list[left];
        else if (left + 1 == right)
            return merge(list[left], list[right]);

        int mid = (left + right) / 2;
        ListNode *h1 = divConter(list, left, mid);
        ListNode *h2 = divConter(list, mid + 1, right);
        return merge(h1, h2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        return divConter(lists, 0, lists.size() - 1);
    }
};
// @lc code=end
