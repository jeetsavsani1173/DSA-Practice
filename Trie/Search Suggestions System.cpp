// problem link --> https://leetcode.com/problems/search-suggestions-system/description/

class Solution
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

    void insert(string str)
    {
        Node *curr = root;

        for (auto it : str)
        {
            if (curr->contains(it) == false)
                curr->set(it);
            curr = curr->get(it);
        }
        curr->setEnd();
    }

    void dfs(Node *curr, string &stsf, vector<string> &ans)
    {
        if (ans.size() == 3)
            return;
        if (curr == NULL)
            return;
        if (curr->getEnd())
        {
            ans.push_back(stsf);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (curr->contains(ch))
            {
                stsf.push_back(ch);
                dfs(curr->get(ch), stsf, ans);
                stsf.pop_back();
            }
        }
    }
    vector<string> search(string str)
    {
        Node *curr = root;
        for (auto it : str)
        {
            if (curr->contains(it) == false)
            {
                return {};
            }
            curr = curr->get(it);
        }

        vector<string> temp_ans;
        dfs(curr, str, temp_ans);
        return temp_ans;
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        for (auto it : products)
            insert(it);

        vector<vector<string>> ans;
        string str;
        for (auto it : searchWord)
        {
            str.push_back(it);
            vector<string> temp = search(str);
            ans.push_back(temp);
        }
        return ans;
    }
};