package algorithm.leetcode.search;

import java.util.ArrayList;
import java.util.List;

class LC207 {

    protected boolean canFinish(int numCourses, int[][] prerequisites) {

        // 构建二维图，搜索图中是否有环

        List<List<Integer>> map = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            map.add(new ArrayList<>());
        }

        for (int i = 0; i < prerequisites.length; i++) {
            int[] cur = prerequisites[i];
            map.get(cur[0]).add(cur[1]);
        }
        int[] flag = new int[numCourses];

        // 对于每一门课程进行搜索
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(flag, map, i)) {
                return false;
            }
        }

        return true;
    }

    public boolean dfs(int[] vist, List<List<Integer>> map, int cur) {
        // 当前状态已经标记为被依赖，有环不满足
        if (vist[cur] == 1) return false;
        // 当前状态已经保证无环出现，必满足( 需要记录两个状态， 否则会超时 )
        if (vist[cur] == 2) return true;
        vist[cur] = 1;
        for (int i = 0; i < map.get(cur).size(); i++) {
            if (!dfs(vist, map, map.get(cur).get(i))) {
                return false;
            }
        }
        vist[cur] = 2;

        return true;
    }
}