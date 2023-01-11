// problem link --> https://leetcode.com/problems/stream-of-characters/description/

class StreamChecker
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

    Node *root = new Node();

    void insert(string word)
    {
        Node *curr = root;

        for (int i = word.size() - 1; i >= 0; i--)
        {
            char it = word[i];
            if (curr->contains(it) == false)
            {
                curr->set(it);
            }
            curr = curr->get(it);
        }

        curr->setEnd();
    }

    StreamChecker(vector<string> &words)
    {
        for (auto it : words)
            insert(it);
    }

    string str;
    bool query(char letter)
    {
        str.push_back(letter);

        Node *curr = root;
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (curr->getEnd())
                return true;

            if (curr->contains(str[i]) == false)
                return false;

            curr = curr->get(str[i]);
        }
        if (curr->getEnd())
            return true;
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */