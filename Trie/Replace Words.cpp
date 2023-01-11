// problem link --> https://leetcode.com/problems/replace-words/description/

class Solution
{
public:
    vector<string> split(string &str)
    {
        vector<string> ans;

        string curr_str;
        for (auto it : str)
        {
            if (it == ' ')
            {
                ans.push_back(curr_str);
                curr_str = "";
            }
            else
            {
                curr_str.push_back(it);
            }
        }
        ans.push_back(curr_str);
        return ans;
    }
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

    int search(string word)
    {
        Node *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            char it = word[i];
            if (curr->contains(it) == false)
            {
                return word.size() - 1;
            }
            curr = curr->get(it);
            if (curr->getEnd() == true)
                return i;
        }

        return word.size() - 1;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (auto it : dictionary)
            insert(it);

        vector<string> vect = split(sentence);
        string ans = "";

        for (auto it : vect)
        {
            int idx = search(it);
            string str;
            for (int i = 0; i <= idx; i++)
                str.push_back(it[i]);

            // cout<<idx<<"->"<<str<<endl;
            ans += str;
            ans.push_back(' ');
        }
        return ans.substr(0, ans.size() - 1);
    }
};

// second Solution
class Solution
{
public:
    vector<string> split(string &str)
    {
        vector<string> ans;

        string curr_str;
        for (auto it : str)
        {
            if (it == ' ')
            {
                ans.push_back(curr_str);
                curr_str = "";
            }
            else
            {
                curr_str.push_back(it);
            }
        }
        ans.push_back(curr_str);
        return ans;
    }
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

    string search(string word)
    {
        Node *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            char it = word[i];
            if (curr->getEnd() == true)
                return word.substr(0, i);
            if (curr->contains(it) == false)
            {
                return word;
            }
            curr = curr->get(it);
        }

        return word;
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (auto it : dictionary)
            insert(it);

        vector<string> vect = split(sentence);
        string ans = "";

        for (auto it : vect)
        {
            if (ans.size() > 0)
                ans.push_back(' ');
            ans += search(it);
        }
        return ans;
    }
};