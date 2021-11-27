/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.96%)
 * Likes:    4611
 * Dislikes: 0
 * Total Accepted:    482.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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

typedef unsigned long long ull;
#include <vector>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> vec1, vec2;
        while (l1 != nullptr)
        {
            vec1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            vec2.push_back(l2->val);
            l2 = l2->next;
        }
        int len1 = vec1.size();
        int len2 = vec2.size();
        vector<int> vecRes = len1 > len2 ? vec1 : vec2;
        bool up = false;
        for (size_t i = 0; i < vecRes.size(); i++)
        {
            if (i < vec1.size() && i < vec2.size())
                vecRes[i] = vec1[i] + vec2[i];
            if (up)
                vecRes[i]++;
            up = false;
            if (vecRes[i] >= 10)
            {
                vecRes[i] -= 10;
                if (i + 1 < vecRes.size())
                    up = true;
                else
                {
                    vecRes.push_back(1);
                    break;
                }
            }
        }
        int i = 0;
        ListNode *res = new ListNode(vecRes[i++]);
        ListNode *head = res;
        while (i < vecRes.size())
        {
            ListNode *cur = new ListNode(vecRes[i++]);
            res->next = cur;
            res = res->next;
        }
        return head;
    }
};
// @lc code=end
