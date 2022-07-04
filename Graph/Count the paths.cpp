// problem link --> https://practice.geeksforgeeks.org/problems/count-the-paths4332/1#

public:
    int ans;
    void dfs(int node,int d,vector<int> graph[])
    {
        if(node==d) ans++;
        
        for(auto it:graph[node])
            dfs(it,d,graph);
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> graph[20];
	    for(auto it:edges)
	    {
	        graph[it[0]].push_back(it[1]);
	    }
	    ans=0;
	    dfs(s,d,graph);
	    return ans;
	}
};