/*
 * @lc app=leetcode.cn id=680 lang=kotlin
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (29.38%)
 * Total Accepted:    3.2K
 * Total Submissions: 11K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */
class Solution {

    fun isPalind(s: String, a: Int, b: Int): Boolean {
        var i = a
        var j = b
        while (i < j) {
            if (s[i++] != s[j--]) return false
        }
        return true
    }

    fun validPalindrome(s: String): Boolean {
        var i = -1;
        var j = s.length
        while (++i < --j) {
            if (s[i] != s[j]) {
                // 如果出现第一个不一样的字符
                // 分别尝试删除左边字符和右边字符
                // 观察删除后的串是否为回文串
                return isPalind(s, i + 1, j) || isPalind(s, i, j - 1)
            }
        }
        return true
    }
}

