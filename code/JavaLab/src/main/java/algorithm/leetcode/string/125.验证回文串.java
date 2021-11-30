package algorithm.leetcode.string;

/**
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 */
class LC125 {

    public static void main(String[] args) {

        LC125 main = new LC125();
        main.isPalindrome("A man, a plan, a canal: Panama");
    }


    public boolean isChar(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    public boolean isSame(char a, char b) {
        if (a >= 'A' && a <= 'Z') a = (char) (a + 32);
        if (b >= 'A' && b <= 'Z') b = (char) (b + 32);
        return a == b;
    }


    public boolean isPalindrome(String s) {

        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (l < r && !isChar(s.charAt(l))) l++;
            while (l < r && !isChar(s.charAt(r))) r--;
            System.out.println(l + " " + r);
            if (!isSame(s.charAt(l++), s.charAt(r--))) {
                return false;
            }
        }
        return true;
    }
}