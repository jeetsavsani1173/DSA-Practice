// problem link --> https://leetcode.com/problems/longest-word-in-dictionary/description/

class Solution {
public:
    struct Node{
        Node* children[26];
        bool isEnd=false;

        bool contains(char ch){
            return (children[ch-'a']!=NULL);
        }

        Node* get(char ch){
            return children[ch-'a'];
        }

        void set(char ch){
            children[ch-'a']=new Node();
        }

        bool getEnd(){
            return isEnd;
        }

        void setEnd(){
            isEnd=true;
        }
    };

    Node* root;

    void insert(string word) {
        Node* curr=root;

        for(auto it:word)
        {
            if(curr->contains(it)==false){
                curr->set(it);
            }
            curr=curr->get(it);
        }

        curr->setEnd();
    }

    string ans;

    void dfs(Node* curr,string &curr_ans)
    {
        if(curr_ans.size()>ans.size())
            ans=curr_ans;
        for(char ch='a';ch<='z';++ch)
        {
            Node* it=curr->children[ch-'a'];
            if(it!=NULL && it->isEnd==true)
            {
                curr_ans.push_back(ch);
                dfs(it,curr_ans);
                curr_ans.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {
        root=new Node();
        for(auto it:words)
            insert(it);
        
        Node* curr=root;
        string curr_ans;
        ans="";
        dfs(curr,curr_ans);
        return ans;
    }
};