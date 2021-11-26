package algorithm.offer.treeover;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 10:23 下午
#   @Description   : 剑指 Offer 34. 二叉树中和为某一值的路径
#   https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
# ====================================================*/
public class Offer34 {


    public List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int target) {

        if(root == null) {
            return res;
        }


        List<Integer> temp = new ArrayList<>();
        dfs(root, target, temp);
        return res;
    }

    void dfs(TreeNode node, int n, List<Integer> list) {

        // 叶子节点
        if (node.left == null && node.right == null) {
            if (n == node.val) {
                List<Integer> l = new ArrayList<>(list);
                l.add(node.val);
                res.add(new ArrayList<>(l));
            }
            return;
        }

        list.add(node.val);
        if (node.left != null) {
            dfs(node.left, n - node.val, list);
        }
        if (node.right != null) {
            dfs(node.right, n - node.val, list);
        }

        list.remove(list.size() - 1);
    }


}
