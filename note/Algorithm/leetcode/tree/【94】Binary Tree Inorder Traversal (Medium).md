### 【94】Binary Tree Inorder Traversal (Medium)

> 题目大意 

非递归中序遍历二叉树

> 解题思路

中序思路和前序后序不同，不断把左孩子入栈，弹出的节点一定为中间节点(左孩子为空)，之后再中序遍历右孩子，对之前栈里的节点都不产生影响

> AC代码

```
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        // 如果回到根节点，栈一定是空的，但右子树还没有遍历，所以需要特判
        while (!stack.empty() || cur != null) {
            // 不断把左侧节点压入栈
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 此时为中间节点
            TreeNode node = stack.pop();
            list.add(node.val);
            // 中间节点此后就没用了，再将右子树进行中序遍历
            cur = node.right;
        }
        return list;
    }
```