/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.93%)
 * Likes:    527
 * Dislikes: 0
 * Total Accepted:    121.8K
 * Total Submissions: 190.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;

        for (auto it = m.begin(); it != m.end(); it++)
            res.push_back(it->second);

        return res;
    }
};
// @lc code=end
