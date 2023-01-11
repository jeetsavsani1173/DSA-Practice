// problem link --> https://www.interviewbit.com/problems/shortest-unique-prefix/

struct Node
{
    Node *children[26];
    bool isEnd = false;
    int pref = 0;

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

    void increase(int val)
    {
        pref += val;
    }

    int getPref()
    {
        return pref;
    }
};

Node *root = new Node();

void insert(string word)
{
    Node *curr = root;

    for (auto it : word)
    {
        curr->pref += 1;
        if (curr->contains(it) == false)
        {
            curr->set(it);
        }
        curr = curr->get(it);
    }

    curr->setEnd();
}

string search(string &str)
{
    Node *curr = root;

    for (int i = 0; i < str.size(); i++)
    {
        auto it = str[i];
        if (curr->pref == 1)
        {
            return str.substr(0, i);
        }
        curr = curr->get(it);
    }
    return str;
}

vector<string> Solution::prefix(vector<string> &A)
{
    for (auto it : A)
        insert(it);

    vector<string> ans;
    for (auto it : A)
    {
        ans.push_back(search(it));
    }
    return ans;
}
