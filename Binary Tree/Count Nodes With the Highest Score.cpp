// problem link --> https://leetcode.com/problems/count-nodes-with-the-highest-score/

class Solution {
public:
    vector<long> graph[100005];
    long dfs(long node)
    {
        long count=1;
        for(auto it:graph[node])
            count+=dfs(it);
        return count;
    }
    long find_highest_score(long node,long &TotalNodes,long &HighScore)
    { 
        long lcount=0,rcount=0;
        if(graph[node].size()>=1)
            lcount=find_highest_score(graph[node][0],TotalNodes,HighScore);
        if(graph[node].size()==2)
            rcount=find_highest_score(graph[node][1],TotalNodes,HighScore);
        
        long remain=TotalNodes-1-lcount-rcount;
        HighScore=max(HighScore,((remain!=0)?remain:1)*((lcount!=0)?lcount:1)*((rcount!=0)?rcount:1));
        // cout<<HighScore<<endl;
        return 1+lcount+rcount;
    }
    long count_Highest_score(long node,long &TotalNodes,long &HighScore,long &count)
    {
        long lcount=0,rcount=0;
        if(graph[node].size()>=1)
            lcount=count_Highest_score(graph[node][0],TotalNodes,HighScore,count);
        if(graph[node].size()==2)
            rcount=count_Highest_score(graph[node][1],TotalNodes,HighScore,count);
        
        long remain=TotalNodes-1-lcount-rcount;
        long temp_score=((remain!=0)?remain:1)*((lcount!=0)?lcount:1)*((rcount!=0)?rcount:1);
        if(temp_score==HighScore)
            count++;

        return 1+lcount+rcount;
    }
    long countHighestScoreNodes(vector<int>& parents) {
        long root=0;
        for(long i=1;i<parents.size();i++)
            graph[parents[i]].push_back(i);
        long TotalNodes=dfs(root);
        
        long HighScore=0;
        find_highest_score(root,TotalNodes,HighScore);
        // cout<<HighScore<<endl;
        long Highest_count=0;
        count_Highest_score(root,TotalNodes,HighScore,Highest_count);
        
        return Highest_count;
    }
};