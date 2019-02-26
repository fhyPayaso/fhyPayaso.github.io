### 【144】Binary Tree Preorder Traversal (Medium)

> 题目大意 

非递归先序遍历二叉树

> 解题思路

非递归遍历一定是用栈做，对于每一个弹出的节点，先打印自己(相当于接下来的操作都是以自己为根的子树)，然后根据栈的特性，入栈先➡右后左，出栈正好是先左后右

> AC代码

```
    public List<Integer> preorderTraversal(TreeNode root) {
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
            stack.push(node.right); // 右孩子先入后遍历
            stack.push(node.left); // 左孩子后入先遍历
        }
        return list;
    }
```