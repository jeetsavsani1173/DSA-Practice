// problem link --> https://leetcode.com/problems/fruit-into-baskets/

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        map<int, int> mp;
        int left = 0, right = 0;
        int ans = 1;
        for (; right < fruits.size(); right++)
        {
            mp[fruits[right]]++;
            while (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            if (mp.size() <= 2)
            {
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
