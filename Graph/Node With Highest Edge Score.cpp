// problem link --> https://leetcode.com/problems/node-with-highest-edge-score/


class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> scores(edges.size(),0);
        
        for(int i=0;i<edges.size();i++)
            scores[edges[i]]+=i;
        
        long long mx_score=*max_element(scores.begin(),scores.end());
        
        for(int i=0;i<scores.size();i++)
            if(scores[i]==mx_score) 
                return i;
        return 0;
    }
};