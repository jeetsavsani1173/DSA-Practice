// problem link --> https://practice.geeksforgeeks.org/problems/topological-sort/1#

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> graph[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:graph[i])
                indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto child:graph[it])
            {
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        if(ans.size()!=V) return {};
        return ans;
	}
};