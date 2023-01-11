// problem link --> https://leetcode.com/problems/implement-magic-dictionary/description/

class MagicDictionary
{
public:
    struct Node
    {
        Node *children[26];
        bool isEnd = false;

        bool contains(char ch)
        {
            return (children[ch - 'a'] != NULL);
        }

        Node *get(char ch)
        {
            return children[ch - 'a'];
        }

        void set(char ch)
        {
            children[ch - 'a'] = new Node();
        }

        bool getEnd()
        {
            return isEnd;
        }

        void setEnd()
        {
            isEnd = true;
        }
    };

    Node *root;
    MagicDictionary()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *curr = root;

        for (auto it : word)
        {
            if (curr->contains(it) == false)
            {
                curr->set(it);
            }
            curr = curr->get(it);
        }

        curr->setEnd();
    }

    void buildDict(vector<string> dictionary)
    {
        for (auto it : dictionary)
        {
            insert(it);
        }
    }

    bool dfs(int idx, string str, Node *curr, bool count)
    {
        if (idx == str.size())
        {
            if (count && curr->getEnd())
                return true;
            return false;
        }

        if (curr->contains(str[idx]) && dfs(idx + 1, str, curr->get(str[idx]), count))
            return true;
        if (count == true)
            return false;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (ch == str[idx])
                continue;

            if (curr->contains(ch) && dfs(idx + 1, str, curr->get(ch), true))
                return true;
        }
        return false;
    }

    bool search(string searchWord)
    {
        Node *curr = root;
        return dfs(0, searchWord, curr, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */