#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    int table[26];
    for (int i = 0; i < 26; i++)
        table[i] = 0;

    for (int i = 0; i < tasks.size(); i++)
        table[int(tasks[i] - 'A')]++;

    int maxCount = 0;
    int maxVal = 0;
    for (int i = 0; i < 25; i++)
    {
        // cout<< table[i]<<endl;
        
        if (table[i] > maxVal)
        {
            maxVal = table[i];
            maxCount = 1;
        }
        else if (table[i] == maxVal)
            maxCount++;
    }

    cout<< "maxVal: "<< maxVal << endl;
    cout<< "maxCount: "<< maxCount << endl;

    // 如果桶每行不能填满,或刚好填满
    int res1 = (n + 1) * (maxVal - 1) + maxCount;
    // 若桶每行都能溢出, 时间直接为长度
    int res2 = tasks.size();

    // 两种情况, 取最大值即可
    return res1 > res2 ? res1 : res2;
}

int main()
{
    
    vector<char> vec;
    vec.push_back('A');
    vec.push_back('A');
    vec.push_back('A');
    vec.push_back('B');
    vec.push_back('B');
    vec.push_back('B');

    leastInterval(vec, 2);

    return 0;
}
