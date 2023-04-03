// problem link --> https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    class Compare
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return sqrt(a.first * a.first + a.second * a.second) < sqrt(b.first * b.first + b.second * b.second);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int n = points.size();
        for (int i = 0; i < k; i++)
            pq.push({points[i][0], points[i][1]});

        for (int i = k; i < n; i++)
        {
            pair<int, int> tp = pq.top();
            pair<int, int> b = {points[i][0], points[i][1]};
            if (sqrt(tp.first * tp.first + tp.second * tp.second) > sqrt(b.first * b.first + b.second * b.second))
            {
                pq.pop();
                pq.push(b);
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            pair<int, int> pr = pq.top();
            pq.pop();
            ans.push_back({pr.first, pr.second});
        }
        return ans;
    }
};