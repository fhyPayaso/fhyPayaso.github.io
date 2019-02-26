
### 【110】Balanced Binary Tree (Easy)

> 题目大意 

判断一棵树是否为平衡二叉树(任何一个节点的左右子树深度差不超过1)

> 解题思路

头条二面Y总出的原题，当时写的复杂度高，对每一个节点都再求深度判断了一遍，求深度的过程重复

其实这题是求二叉树深度的变种。。。只要求深度的过程中维护一个深度差就行了。。。

思维僵化，总想着参数传递，所以新建了一个类维护值，其实写个全局变量就好了。。。


> AC代码

```
    class Deep {
        public int val;

        public Deep(int val) {
            this.val = val;
        }
    }

    public boolean isBalanced(TreeNode root) {
        // 始终维护最大深度差，保证引用指向一个对象
        Deep deep = new Deep(0);
        getDeep(root, deep);
        return deep.val <= 1;
    }

    public int getDeep(TreeNode root, Deep deep) {
        if (root == null) {
            return 0;
        }
        int left = getDeep(root.left, deep);
        int right = getDeep(root.right, deep);
        // 更新深度差
        deep.val = Math.max(Math.abs(left - right), Math.abs(deep.val));
        return Math.max(left, right) + 1;
    }
```


> 改进

```

    public boolean res = true;

    public boolean isBalanced(TreeNode root) {
        getDeep(root);
        return res;
    }

    public int getDeep(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = getDeep(root.left);
        int right = getDeep(root.right);
        if (res) { // 结果只能改变一次
            res = Math.abs(left - right) <= 1;
        }
        return Math.max(left, right) + 1;
    }

```