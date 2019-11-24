#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

unsigned int p31 = 01 << 31;

vector<vector<int> > res;

void dfs(vector<int> &nums,
         vector<int> temp,
         int flag[])
{
    if (nums.size() == temp.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<i<<endl;
        if (flag[i] == 0)
        {
            cout << i << endl;
            temp.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums, temp, flag);
            temp.pop_back();
            flag[i] = 0;
        }
    }
}

vector<vector<int> > permute(vector<int> &nums)
{
    int flag[1000] = {0};
    vector<int> temp;
    dfs(nums, temp, flag);
    return res;
}

int main()
{

    vector<int> par;
    par.push_back(1);
    par.push_back(2);
    par.push_back(3);

    vector<vector<int> > a = permute(par);

    cout<<"[";
    for (int i = 0; i < a.size(); i++)
    {
        cout << "[";
        vector<int> num = a[i];
        for(int j = 0;j<num.size();j++)
        {
            cout<<num[j]<<",";
        }
        cout << "],";
    }
    cout << "]"<<endl;
    return 0;
}