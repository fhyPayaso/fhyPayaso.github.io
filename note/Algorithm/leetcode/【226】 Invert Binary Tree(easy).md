
### 【226】 Invert Binary Tree(easy)

> 题目大意 

二叉树翻转

> 解题思路

不多说，补水题

> AC代码

```
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        invertTree(root.left);
        invertTree(root.right);
        return root;
    }
```