package algorithm.leetcode.string_array;

import java.util.ArrayList;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/zigzag-conversion/
 *
 */
class LC06 {

    public String convert(String s, int numRows) {


        List<StringBuffer> list = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            list.add(new StringBuffer());
        }

        int row = 0;
        boolean down = true;
        for (int i = 0; i < s.length(); i++) {

            list.get(row).append(s.charAt(i));
            if (down) {
                row++;
            } else {
                row--;
            }

            if (row == numRows - 1 || row == 0) {
                down = !down;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            sb.append(list.get(i));
        }

        return sb.toString();
    }
}