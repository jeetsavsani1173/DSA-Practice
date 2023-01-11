// problem link --> https://leetcode.com/problems/map-sum-pairs/description/

class MapSum
{
public:
    struct Node
    {
        Node *children[26];
        int val = 0;
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

        int getVal()
        {
            return val;
        }

        void setVal(int value)
        {
            val = value;
        }

        // void increaseSum(int val){
        //     prefixSum+=val;
        // }

        // int getSum(){
        //     return prefixSum;
        // }
    };

    Node *root;
    MapSum()
    {
        root = new Node();
    }

    int search(string word)
    {
        Node *curr = root;
        for (auto it : word)
        {
            if (curr->contains(it) == false)
            {
                return 0;
            }
            curr = curr->get(it);
        }
        return curr->getVal();
    }

    void insert(string key, int val)
    {
        int oldVal = search(key);
        cout << oldVal << " " << val << endl;

        Node *curr = root;

        for (auto it : key)
        {
            // curr->increaseSum(val-oldVal);
            curr->pref += (val - oldVal);
            if (curr->contains(it) == false)
            {
                curr->set(it);
            }
            curr = curr->get(it);
        }

        // curr->increaseSum(val-oldVal);
        curr->pref += (val - oldVal);
        curr->setVal(val);
    }

    int sum(string prefix)
    {
        Node *curr = root;
        for (auto it : prefix)
        {
            if (curr->contains(it) == false)
            {
                return 0;
            }
            curr = curr->get(it);
        }

        return curr->pref;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */