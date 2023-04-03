// problem link --> https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    vector<int> graph[n + 1];
    for (auto it : edges)
    {
        graph[it.first].push_back(it.second);
        graph[it.second].push_back(it.first);
    }

    queue<pair<int, int>> q;
    q.push({s, -1});
    vector<int> par(n + 1, -2);

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        if (par[node] != -2)
            continue;
        ;
        par[node] = parent;
        for (auto it : graph[node])
        {
            if (par[it] == -2)
            {
                q.push({it, node});
            }
        }
    }

    // for(auto it:par)
    //     cout<<it<<" ";
    // cout<<endl;
    vector<int> ans;
    int idx = t;
    while (true)
    {
        ans.push_back(idx);
        idx = par[idx];
        if (idx == -1)
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    // for(auto it:ans)
    //     cout<<it<<" ";
    // cout<<endl;
    return ans;
}
