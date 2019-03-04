#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#
# https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
#
# algorithms
# Easy (46.11%)
# Total Accepted:    6.7K
# Total Submissions: 14.5K
# Testcase Example:  '"hello"'
#
# 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
#
# 示例 1:
#
# 输入: "hello"
# 输出: "holle"
#
#
# 示例 2:
#
# 输入: "leetcode"
# 输出: "leotcede"
#
# 说明:
# 元音字母不包含字母"y"。
#
#


class Solution:
    def reverseVowels(self, s: str) -> str:
        i = 0
        j = len(s) - 1
        yuan = 'aeiouAEIOU'
        s = [x for x in s]
        while i < j:
            while i < j and s[i] not in yuan:
                i += 1
            while i < j and s[j] not in yuan:
                j -= 1
            if i < j:
                t = s[i]
                s[i] = s[j]
                s[j] = t
                i += 1
                j -= 1
        return "".join(s)
