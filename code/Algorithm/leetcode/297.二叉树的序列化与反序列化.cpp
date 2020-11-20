/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (52.49%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 106.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <string>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 层序遍历 + 字符串模拟 

class Codec
{
public:
    string int2str(int val)
    {
        if (val == 0)
            return "0";

        string str = "";
        bool flag = false;
        if (val < 0)
        {
            val = -val;
            flag = true;
        }
        while (val != 0)
        {
            int t = val % 10;
            str += char(t + '0');
            val /= 10;
        }
        if (flag)
        str += '-';

        reverse(str.begin(), str.end());

        return str;
    }

    vector<int> split(string str)
    {
        vector<int> res;
        int index = 0;
        while (index < str.size())
        {
            if (str[index] == ',')
            {
                index++;
                continue;
            }

            if (str[index] == 'n')
            {
                index++;
                res.push_back(-99999);
                continue;
            }

            int i = index;
            int flag = 1;
            if (str[i] == '-')
            {
                flag = -1;
                i++;
            }
            int temp = 0;
            while (str[i] != ',')
            {
                temp *= 10;
                temp += int(str[i] - '0');
                i++;
            }
            res.push_back(temp * flag);
            index = i;
        }
        return res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        if (root == nullptr)
            return res;

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode *curNode = que.front();
            que.pop();
            if (curNode != nullptr)
            {
                // res += char(curNode->val + '0');
                res += int2str(curNode->val);
                res += ',';
                que.push(curNode->left);
                que.push(curNode->right);
            }
            else
            {
                res += 'n';
                res += ',';
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;

        vector<int> dataVec = split(data);

        int index = 0;
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(dataVec[index++]);
        que.push(root);

        while (!que.empty())
        {
            TreeNode *curNode = que.front();
            que.pop();

            if (dataVec[index] != -99999)
            {
                curNode->left = new TreeNode(dataVec[index]);
                que.push(curNode->left);
            }
            index++;
            if (index >= data.size())
                break;

            if (dataVec[index] != -99999)
            {
                curNode->right = new TreeNode(dataVec[index]);
                que.push(curNode->right);
            }

            index++;
            if (index >= data.size())
                break;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
