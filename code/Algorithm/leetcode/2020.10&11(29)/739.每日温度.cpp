/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (64.77%)
 * Likes:    540
 * Dislikes: 0
 * Total Accepted:    108.7K
 * Total Submissions: 167.3K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        stack<int> S;
        vector<int> R(T.size());
        for (int i = 0; i < T.size(); i++)
        {

            // 递减栈 栈中记录递减值的位置
            // 如果出现递增值, 则将栈中所有小于该值的数弹出, 并计算距离
            while (!S.empty() && T[i] > T[S.top()])
            {
                int temp = S.top();
                S.pop();
                R[temp] = i - temp;
            }
            S.push(i);
        }
        return R;
    }
};
// @lc code=end

//
// TLE
//
// vector<int> dailyTemperatures(vector<int> &T)
//     {
//         vector<int> res;
//         for (int i = 0; i < T.size(); i++)
//         {
//             int cur = T[i];
//             int num = 0;
//             int flag = false;
//             for (int j = i; j < T.size(); j++)
//             {
//                 if (T[j] > cur)
//                 {
//                     flag = true;
//                     break;
//                 }
//                 else
//                     num++;
//             }
//             if (flag)
//                 res.push_back(num);
//             else
//                 res.push_back(0);
//         }
//         return res;
//     }
