// problem link --> https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s=="" || t=="" || s.size()<t.size()) return "";
        
        map<char,int> req;
        // cout<<req.size()<<endl;
        for(int i=0;i<t.size();i++) req[t[i]]++;
        int temp=req.size();
        int matchCnt=0;
        // for(auto it:req)
        //     cout<<it.first<<"->"<<it.second<<" ";
        // cout<<endl;
        int left=0,len=INT_MAX,start_idx=0;
        map<char,int> curr_mp;
        // cout<<req.size()<<endl;
        for(int right=0;right<s.size();right++)
        {
            char ch=s[right];
            curr_mp[ch]++;
            if(curr_mp[ch]==req[ch]) matchCnt++;
            if(req[ch]==0) req.erase(ch);
            // cout<<matchCnt<<" ---- ";
            // for(auto it:curr_mp)
            //     cout<<it.first<<"->"<<it.second<<" ";
            // cout<<endl;
            // cout<<req.size()<<endl;
            while(matchCnt >= temp)
            {
                // cout<<left<<" "<<right<<endl;
                if(right-left < len)
                {
                    start_idx=left;
                    len=right-left+1;
                }
                // cout<<start_idx<<" "<<len<<endl;
                char chl=s[left];
                if(curr_mp[chl]==req[chl]) matchCnt--;
                if(curr_mp[chl]==1) curr_mp.erase(chl);
                else curr_mp[chl]--;
                left++;
            }
        }
        if(len==INT_MAX) return "";
        string ans;
        for(int i=0;i<len;i++)
            ans+=s[start_idx+i];
        return ans;
    }
};