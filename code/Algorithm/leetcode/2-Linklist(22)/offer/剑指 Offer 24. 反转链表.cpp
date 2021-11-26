#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *p = head;
        ListNode *nex;
        ListNode *pre = nullptr;
        while (p != nullptr)
        {
            nex = p->next;
            p->next = pre;
            pre = p;
            p = nex;
        }
        return pre;
    }
};