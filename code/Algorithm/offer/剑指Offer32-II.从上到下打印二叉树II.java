package algorithm.offer.easy;

import algorithm.config.TreeNode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/11 3:40 下午
#   @Description   : 剑指 Offer 32 - II. 从上到下打印二叉树 II
#   https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
# ====================================================*/
public class Offer32II {

    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> res = new ArrayList<>();

        LinkedList<TreeNode> queue = new LinkedList<>();

        if (root == null) {

            return res;
        }

        queue.add(root);

        while (!queue.isEmpty()) {

            int size = queue.size();
            List<Integer> line = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                
                TreeNode node = queue.getFirst();
                queue.removeFirst();
                line.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            res.add(line);
        }

        return res;
    }

}
