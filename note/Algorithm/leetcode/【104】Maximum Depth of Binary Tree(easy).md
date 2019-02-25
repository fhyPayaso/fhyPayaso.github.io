
### 【104】Maximum Depth of Binary Tree(easy)

> 题目大意 

求二叉树深度

> 解题思路

不多说，补水题

> AC代码

```
    public int maxDepth(TreeNode root) {
        return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
```