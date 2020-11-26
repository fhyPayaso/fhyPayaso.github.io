/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (67.28%)
 * Likes:    502
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 65.9K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 * 
 * 注意：
 * 总人数少于1100人。
 * 
 * 示例
 * 
 * 
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    // leetcode cmp需要为static
    static bool cmp(vector<int> v1, vector<int> v2)
    {
        // 先对原始数组记性排序

        // 身高h降序
        if (v1[0] == v2[0])
            return v1[1] < v2[1];
        // k升序
        else
            return v1[0] > v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        // 身高矮的插入不会影响高的排列顺序，所以先插入高的
        // 对于新插入的矮身高，因为高身高已经确定, 并且都大于等于它，所以其k值就是他的新位置

        int len = people.size();
        vector<vector<int>> resPeople;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < len; i++)
        {
            vector<int> cur = people[i];
            resPeople.insert(resPeople.begin() + cur[1], cur);
        }
        return resPeople;
    }
};
// @lc code=end
