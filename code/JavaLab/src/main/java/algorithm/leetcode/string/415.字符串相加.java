package algorithm.leetcode.string;

/**
 * https://leetcode-cn.com/problems/add-strings/
 * <p>
 * 字符串加法
 */
class LC415 {

    public String addStrings(String num1, String num2) {


        int w = 0;

        if (num1.length() < num2.length()) {
            String temp = num2;
            num2 = num1;
            num1 = temp;
        }

        int jin = 0;

        StringBuilder res = new StringBuilder();

        while (w < num1.length()) {

            int i1 = num1.length() - w - 1;
            int v1 = num1.charAt(i1) - '0';

            int v2 = 0;
            if (w < num2.length()) {
                int i2 = num2.length() - w - 1;
                v2 = num2.charAt(i2) - '0';
            }

            int v = v1 + v2 + jin;

            if (v > 9) {
                v -= 10;
                jin = 1;
            } else {
                jin = 0;
            }
            res.append((char) (v + '0'));
            w++;
        }

        if (jin == 1) {
            res.append("1");
        }

        return res.reverse().toString();
    }
}