// probelm link --> https://leetcode.com/problems/reorganize-string/

class Solution
{
public:
    string reorganizeString(string s)
    {
        if (s.size() == 1)
            return s;
        map<char, int> mp;
        for (auto it : s)
            mp[it]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
            pq.push({it.second, it.first});

        if (pq.top().first > (s.size() + 1) / 2)
        {
            return "";
        }

        int i = s.size();
        string ans;
        while (i--)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            if (ans.back() == top1.second)
            {
                top2.first--;
                ans.push_back(top2.second);
            }
            else
            {
                top1.first--;
                ans.push_back(top1.second);
            }
            pq.push(top1);
            pq.push(top2);
        }

        return ans;
    }
};