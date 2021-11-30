/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (69.19%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    62.5K
 * Total Submissions: 90.4K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start
class Trie
{
public:
    Trie *children[26];
    bool isWord;

    /** Initialize your data structure here. */
    Trie()
    {

        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        isWord = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *t = this;
        for (auto c : word)
        {
            int i = int(c - 'a');
            if (t->children[i] == nullptr)
                t->children[i] = new Trie();
            t = t->children[i];
        }
        t->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *t = this;
        for (auto c : word)
        {
            int i = int(c - 'a');
            if (t->children[i] == nullptr)
                return false;
            t = t->children[i];
        }
        return t->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *t = this;
        for (auto c : prefix)
        {
            int i = int(c - 'a');
            if (t->children[i] == nullptr)
                return false;
            t = t->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
