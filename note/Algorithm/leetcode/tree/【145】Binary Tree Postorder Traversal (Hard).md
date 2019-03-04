### 【144】Binary Tree Postorder Traversal (Hard)

> 题目大意 

非递归后序遍历二叉树

> 解题思路

头条一面大G出的原题，竟然是hard，当时没做出来，实际上是非递归这类的题都没练到。。。。

借鉴先序遍历的思路，输出根节点后，入栈顺序若变成先左后右，出栈变成先右后左

这样遍历顺序为**中-右-左**，正好和后序遍历的顺序相反，把结果倒序输出即可

> AC代码

```
    public List<Integer> postorderTraversal(TreeNode root) {

        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.empty()) {
            // 永远都把最上层节点的子树遍先历完
            TreeNode node = stack.pop();
            if (node == null) {
                continue;
            }
            list.add(node.val); // 先输出根节点
            stack.push(node.left); // 左孩子先入后遍历
            stack.push(node.right); // 右孩子后入先遍历
        }
        // 此时输出顺序变成了 中-右-左
        // 而后续遍历顺序为 左-右-中 所以把结果倒转即可
        Collections.reverse(list);
        return list;
    }
```