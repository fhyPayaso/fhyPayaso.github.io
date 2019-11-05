#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

unsigned int p31 = 01 << 31;

int majorityElement(vector<int> &nums)
{

    map<int, int> temp;
    int len = nums.size();
    int res, maxn;
    for (int i = 0; i < len; i++)
    {
        int key = nums[i];
        map<int, int>::iterator it;
        temp.find(key);
        if (it != temp.end())
        {
            int cur = it->second;
            if (cur + 1 > len / 2)
                return key;
            else
                (*it).second = cur + 1;
        }
        else
            temp.insert(pair<int, int>(key, 1));
    }
    return 0;
}

int main()
{

    vector<int> par;
    par.push_back(3);
    par.push_back(2);
    par.push_back(3);

    cout << majorityElement(par) << endl;

    return 0;
}