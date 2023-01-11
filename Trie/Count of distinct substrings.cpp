// problem link -->  https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1

struct Node
{
    Node *children[26];

    Node *get(char ch)
    {
        return children[ch - 'a'];
    }

    void set(char ch)
    {
        children[ch - 'a'] = new Node();
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Node *root = new Node();
    int count = 1;
    for (int i = 0; i < s.size(); i++)
    {
        Node *curr = root;
        for (int j = i; j < s.size(); j++)
        {
            if (curr->get(s[j]) == NULL)
            {
                curr->set(s[j]);
                count++;
            }
            curr = curr->get(s[j]);
        }
    }
    return count;
}