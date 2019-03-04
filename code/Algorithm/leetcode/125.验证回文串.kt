import kotlin.math.abs
/*
 * @lc app=leetcode.cn id=125 lang=kotlin
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.08%)
 * Total Accepted:    24.1K
 * Total Submissions: 63.3K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
class Solution {

    fun isChar(c: Char, withNum: Boolean): Boolean {
        return (c in 'a'..'z') || (c in 'A'..'Z') || ((c in '0'..'9') && withNum)
    }

    fun isSame(c1: Char, c2: Char): Boolean {
        if (c1 == c2) return true
        if (isChar(c1, false) && isChar(c2, false)) {
            return abs(c1 - c2) == 32
        }
        return false
    }

    fun isPalindrome(s: String): Boolean {
        if (s == "") return true
        var i = 0
        var j = s.length - 1
        while (i < j) {
            while (i < j && !isChar(s[i], true)) i++
            while (i < j && !isChar(s[j], true)) j--
            if (!isSame(s[i++], s[j--])) return false
        }
        return true
    }
}

