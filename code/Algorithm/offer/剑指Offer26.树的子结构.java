package algorithm.offer.mid;

import algorithm.config.TreeNode;

import java.awt.print.Pageable;

/* ====================================================
#
#   @Author        : fhyPayaso
#   @Email         : 401619823@qq.com
#   @Date          : 2021/3/14 4:14 下午
#   @Description   : 剑指 Offer 26. 树的子结构
#   https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
# ====================================================*/
public class Offer26 {

    public boolean isSubStructure(TreeNode A, TreeNode B) {

        if (B == null) {
            
               return false;
        }

        

          

        if (check(A, B)) {
            return true;
        }
        if (A != null) {
            return isSubStructure(A.left, B) || isSubStructure(A.right, B);
        }
        return false;
    }


    public boolean check(TreeNode n1, TreeNode n2) {
        if (n2 != null) {
            if (n1 == null || n1.val != n2.val) {
                return false;
            }
            return check(n1.left, n2.left) && check(n1.right, n2.right);
        }
        return true;
    }


}
