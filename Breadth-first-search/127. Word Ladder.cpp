// problem link --> https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        bool ispresent=false;
        
        for(auto word:wordList)
        {
            if(!word.compare(endWord))
                ispresent=true;
            st.insert(word);
        }
        if(!ispresent)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty())
        {
            depth++;
            int lsize=q.size();
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++)
                {
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(!curr.compare(temp))
                            continue;
                        if(!temp.compare(endWord))
                            return depth+1;
                        if(st.find(temp)!=st.end())
                        {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};