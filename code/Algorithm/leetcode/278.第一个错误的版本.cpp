/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        while (left < right)
        {
            // 防止溢出
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
                // 这里不能写mid-1，要始终保持最后一个数为false
                right = mid;
            else
                left = mid + 1;   
        }
        return left;
    }
};
