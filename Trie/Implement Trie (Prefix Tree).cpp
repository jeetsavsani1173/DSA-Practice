// problem link --> https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie
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
    Trie()
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

    bool search(string word)
    {
        Node *curr = root;

        for (auto it : word)
        {
            if (curr->contains(it) == false)
            {
                return false;
            }
            curr = curr->get(it);
        }

        return curr->getEnd();
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;

        for (auto it : prefix)
        {
            if (curr->contains(it) == false)
            {
                return false;
            }
            curr = curr->get(it);
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