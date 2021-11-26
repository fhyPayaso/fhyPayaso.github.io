package algorithm.offer.mid;

import algorithm.config.TreeNode;

import java.util.*;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/13 8:17 下午
#   @Description   : 剑指 Offer 32 - I. 从上到下打印二叉树
#   https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
# ====================================================*/
public class Offer32I {

    public int[] levelOrder(TreeNode root) {

        if(root == null) {
            return new int[0];
        }

        LinkedList<TreeNode> queue = new LinkedList<>();
        List<Integer> list = new ArrayList<>();
        queue.add(root);
        while (!queue.isEmpty()) {

            TreeNode node = queue.getFirst();
            queue.removeFirst();
            list.add(node.val);
            if (node.left != null) {
                queue.add(node.left);
            }

            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return list.stream().mapToInt(Integer::intValue).toArray();

    }

}
