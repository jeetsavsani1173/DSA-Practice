// problem link --> https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,vector<string>> graph;
        // formulate the graph..
        for(int i=0;i<bank.size();i++)
        {
            for(int j=i+1;j<bank.size();j++)
            {
                string first=bank[i];
                string second=bank[j];
                int cnt=0;
                for(int i=0;i<8;i++)
                    if(first[i]!=second[i]) cnt++;
                
                if(cnt==1){
                    graph[first].push_back(second);
                    graph[second].push_back(first);
                }
            }
            string first=bank[i];
            string second=start;
            int cnt=0;
            for(int i=0;i<8;i++)
                if(first[i]!=second[i]) cnt++;
                
            if(cnt==1){
                graph[first].push_back(second);
                graph[second].push_back(first);
            }
        }
        
        map<string,int> vis;
        queue<pair<string,int>> q; // pair<gen,dis>
        // make BFS for finding minimum distance.
        q.push({start,0});
        vis[start]++;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            
            if(top.first==end)
                return top.second;
            
            for(auto it:graph[top.first]){
                if(vis[it]==0){
                    q.push({it,top.second+1});
                    vis[it]++;
                }
            }
        }
        return -1;
    }
};