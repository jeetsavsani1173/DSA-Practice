// problem link -->> https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        
        int count=1;
        ans+=chars[0];     
        for(int i=1;i<chars.size();i++)
        {
            if (chars[i] == chars[i - 1])
			{
				count++;
				if (i == chars.size() - 1)
                    if(count>1)
					ans += to_string(count);
			}
			else
			{
				if (count != 1)
					ans += to_string(count);
				ans += chars[i];
                count = 1;
				if (i == chars.size() - 1)
                    if(count>1)
					ans += to_string(count);
			}
        }
        
        for(int i=0;i<ans.size();i++)
            chars[i]=ans[i];
        
        return ans.size();
    }
};