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
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> res;
        while (head != nullptr)
        {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};