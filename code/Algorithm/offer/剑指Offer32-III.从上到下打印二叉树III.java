package algorithm.offer.mid;

import algorithm.config.TreeNode;

import java.util.*;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 11:55 下午
#   @Description   : 剑指 Offer 32 - III. 从上到下打印二叉树 III
#   https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
# ====================================================*/
public class Offer32III {


    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> res = new ArrayList<>();

        if (root == null) {
            return res;
        }

        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);

        boolean isRightToLeft = false;

        while (!queue.isEmpty()) {

            List<Integer> line = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.getFirst();
                line.add(node.val);
                queue.removeFirst();
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }

            if (isRightToLeft) {
                Collections.reverse(line);
            }
            isRightToLeft = !isRightToLeft;
            res.add(line);
        }
        return res;
    }
}
