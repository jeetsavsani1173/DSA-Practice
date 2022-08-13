// problem link --> https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class Solution {
public:
    vector<int> graph[100005];
    void bfs(int node,vector<int> &dis)
    {
        vector<bool> vis(100005,false);
        queue<pair<int,int>> q;
        q.push({node,0});
        dis[node]=0;
        vis[node]=true;
        
        while(!q.empty()){
            int currNode=q.front().first;
            int cost=q.front().second;
            q.pop();
            
            for(auto it:graph[currNode]){
                if(!vis[it]){
                    dis[it]=cost+1;
                    q.push({it,cost+1});
                    vis[it]=true;
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        
        vector<int> dist1(n,INT_MAX);
        bfs(node1,dist1);
        // for(auto it:dist1) cout<<it<<" ";
        // cout<<endl;
        
        vector<int> dist2(n,INT_MAX);
        bfs(node2,dist2);
        // for(auto it:dist2) cout<<it<<" ";
        // cout<<endl;
        
        int ans=INT_MAX;
        int idx=-1;
        
        for(int i=0;i<n;i++){
            if(ans>max(dist1[i],dist2[i])){
                ans=max(dist1[i],dist2[i]);
                idx=i;
            }
            // ans=min(ans,max(dist1[i],dist2[i]));
        }
        return idx;
    }
};