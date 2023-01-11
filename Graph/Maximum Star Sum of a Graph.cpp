// problem link --> https://leetcode.com/contest/biweekly-contest-93/problems/maximum-star-sum-of-a-graph

class Solution
{
public:
    static bool comp(int &a, int &b)
    {
        return (a > b);
    }
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {
        vector<int> graph[vals.size() + 1];
        vector<int> values[vals.size() + 1];
        for (auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < vals.size() + 1; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                values[i].push_back(vals[graph[i][j]]);
            }
            sort(values[i].begin(), values[i].end(), comp);
        }

        // for(int i=0;i<=6;i++)
        // {
        //     cout<<i<<" -> ";
        //     for(auto it:graph[i])
        //         cout<<it<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<=6;i++)
        // {
        //     cout<<i<<" -> ";
        //     for(auto it:values[i])
        //         cout<<it<<" ";
        //     cout<<endl;
        // }

        int ans = INT_MIN;

        for (int i = 0; i < vals.size(); i++)
        {
            int temp_sum = 0;
            int count = k;
            for (int j = 0; j < values[i].size() && count; j++, count--)
            {
                if (values[i][j] <= 0)
                    break;
                temp_sum += values[i][j];
            }
            ans = max(ans, temp_sum + vals[i]);
        }

        return ans;
    }
};