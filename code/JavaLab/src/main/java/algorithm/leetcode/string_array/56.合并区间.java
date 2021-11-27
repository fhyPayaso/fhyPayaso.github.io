package algorithm.leetcode.string_array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * https://leetcode-cn.com/problems/merge-intervals/
 */
class LC56 {
    public int[][] merge(int[][] intervals) {

        List<int[]> res = new ArrayList<>();

        Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));

        for (int i = 0; i < intervals.length; i++) {

            int l = intervals[i][0];
            int r = intervals[i][1];

            while (i < intervals.length - 1) {

                int nl = intervals[i + 1][0];
                int nr = intervals[i + 1][1];
                if (nl >= l && nl <= r) {
                    r = Math.max(r, nr);
                    i++;
                    continue;
                }
                break;
            }
            res.add(new int[]{l,r});
        }


        int[][] r = new int[res.size()][];
        for (int i = 0; i < res.size(); i++) {
            r[i] = res.get(i);
        }

        return r;
    }
}