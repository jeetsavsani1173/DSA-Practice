// problem link --> https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

// rerooting Technique (DP on tree.)...

pair<int,int> dfs(int node,vector<int> graph[])
{
    if(graph[node].size()==0) return {1,1};
    
    vector<pair<int,int>> vpr;
    for(auto it:graph[node])
    {
        pair<int,int> temp=dfs(it,graph);
        vpr.push_back(temp);
    }
    sort(vpr.begin(),vpr.end());
    reverse(vpr.begin(),vpr.end());
    pair<int,int> rres={0,0};
    for(auto it:vpr)
    {
        rres.first=max(rres.first,1+it.first);
        rres.second=max(rres.second,it.second);
    }
    if(vpr.size()<=1) rres.second=max(rres.second,1+vpr[0].first);
    else rres.second=max(rres.second,1+vpr[0].first+vpr[1].first);
    return rres;
}
int Solution::solve(vector<int> &A) {
    vector<int> graph[A.size()+1]; 
    int root;
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            root=i;
        }else{
            graph[A[i]].push_back(i);
        }
    }
    pair<int,int> ans=dfs(root,graph);
    return ans.second-1;
}
