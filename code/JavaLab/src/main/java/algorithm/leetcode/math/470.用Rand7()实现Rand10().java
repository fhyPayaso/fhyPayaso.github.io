package algorithm.leetcode.math;

/**
 * https://leetcode-cn.com/problems/implement-rand10-using-rand7/
 */
class LC470 {

    class SolBase {

        public int rand7() {
            return 0;
        }
    }

    class Solution extends SolBase {

        public int rand10() {

            while (true) {

                // rand7 - 1 转化为0到6的随机数
                // 先用rand7-1 生成两位数 ab 看成七进制 范围从00 ~ 66
                int a = rand7() - 1;
                int b = rand7() - 1;
                // 对应的10进制为a*7 + b 范围从0 ~ 48
                int res = a * 7 + b;
                // 最后只取0~39 总共40个数字
                if (res < 40) {
                    return res % 10 + 1;
                }
            }
        }
    }
}