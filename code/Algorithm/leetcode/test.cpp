#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

unsigned int p31 = 01 << 31;

int minDistance(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    int res[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
            {
                res[i][j] = j;
                continue;
            }
            else if (j == 0)
            {
                res[i][j] = i;
                continue;
            }
            int diff = word1[i - 1] == word2[j - 1] ? 0 : 1;

            int n1 = min(res[i - 1][j] + 1, res[i][j - 1] + 1);
            int n2 = res[i - 1][j - 1] + diff;
            res[i][j] = min(n1, n2);
        }
    }

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }

    return res[len1][len2];
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *p = head;
    ListNode *pre = head;

    while (head != nullptr)
    {
        int cur = head->val;
        while (cur == val)
        {
            
            if (head->next != nullptr)
            {
                head->val = head->next->val;
                head->next = head->next->next;

                val = head->val;
            }
            else
            {
                delete (head);
                pre->next = nullptr;
                return p;
            }
        }

        pre = head;
        head = head->next;
    }

    // if (p != nullptr && p->next == nullptr && p->val == val)
    // {
    //     return nullptr;
    // }
    return p;
}

int main()
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;

    removeElements(p, 6);

    return 0;
}
