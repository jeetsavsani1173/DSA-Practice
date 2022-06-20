// problem link -->https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> graph[2005];
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
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
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};