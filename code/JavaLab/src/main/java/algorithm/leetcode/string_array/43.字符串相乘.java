package algorithm.leetcode.string_array;

/**
 * https://leetcode-cn.com/problems/multiply-strings/
 * <p>
 * 字符串乘法
 */
class LC43 {

    public static void main(String[] args) {

        LC43 main = new LC43();
//        System.out.println(main.multiply("123", "456"));

        System.out.println(main.multiply("999", "999"));



    }

    public String multiply(String num1, String num2) {

        if ("0".equals(num1) || "0".equals(num2)) {
            return "0";
        }

        // 保证num1在上面
        if (num2.length() > num1.length()) {
            String temp = num1;
            num1 = num2;
            num2 = temp;
        }

        char[] n1 = num1.toCharArray();
        char[] n2 = num2.toCharArray();

        int l3 = n1.length + n2.length;
        int[] n3 = new int[l3];
        int index = 0; // n3从0开始累加

        int addMore = 0; // 进位
        // 遍历下层每一位
        for (int i = n2.length - 1; i >= 0; i--) {

            int curId = index;
            int c2 = n2[i] - '0';

            int more = 0;
            for (int j = n1.length - 1; j >= 0; j--) {

                int c1 = n1[j] - '0';
                // 下层当前位和上层每一位相乘, 注意加上前一位的进位
                int r = c2 * c1 + more;
                more = r / 10;
                r %= 10;

                // 加法的结果进行累加
                n3[curId] += (r + addMore);
                addMore = n3[curId] / 10;
                n3[curId] %= 10;
                curId++;
            }
            // 乘法多出来的进位
            n3[curId] += (addMore + more);
            addMore = n3[curId] / 10;
            n3[curId] %= 10;

            index++;
        }


        StringBuilder builder = new StringBuilder();
        boolean isStart = false;
        for (int i = n3.length - 1; i >= 0; i--) {
            if (n3[i] == 0) {
                if (isStart) builder.append(0);
            } else {
                isStart = true;
                builder.append(n3[i]);
            }
        }

        return builder.toString();
    }
}