// problem link --> https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary
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
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *curr = root;

        for (auto it : word)
        {
            if (curr->contains(it) == false)
                curr->set(it);

            curr = curr->get(it);
        }
        curr->setEnd();
    }

    bool helperSearch(string word, int idx, Node *curr)
    {
        if (idx == word.size())
            return curr->getEnd();

        if (word[idx] != '.')
        {
            if (curr->contains(word[idx]) == false)
            {
                return false;
            }
            curr = curr->get(word[idx]);
            return helperSearch(word, idx + 1, curr);
        }
        else
        {
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (curr->contains(ch) == false)
                    continue;

                if (helperSearch(word, idx + 1, curr->get(ch)))
                    return true;
            }
            return false;
        }
    }

    bool search(string word)
    {
        return helperSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */