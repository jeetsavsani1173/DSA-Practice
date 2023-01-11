// problem link --> https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        for (auto it : piles)
            pq.push(it);

        while (!pq.empty() && k--)
        {
            int top = pq.top();
            pq.pop();

            top = top % 2 == 0 ? top / 2 : top / 2 + 1;
            // cout<<top<<endl;
            pq.push(top);
        }

        int ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};