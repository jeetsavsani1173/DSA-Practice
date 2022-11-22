// problem link --> https://leetcode.com/contest/weekly-contest-318/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost=0;
        priority_queue<long long, vector<long long>, greater<long long> > left;
        priority_queue<long long, vector<long long>, greater<long long> > right;
        if(candidates>=((costs.size()+1)/2)){
            for(auto it:costs)
            {
                left.push(it);
            }
            while(k--)
            {
                cost+=left.top();
                left.pop();
            }
        }
        else{
            int l=0;
            for(l=0;l<candidates;l++)
                left.push(costs[l]);
            
            int r=costs.size()-1;
            int temp=candidates;
            while(temp--)
            {
                right.push(costs[r]);
                r--;
            }
            
            // cout<<l<<" "<<r<<endl;
            
            while(k--)
            {
                if(left.empty()){
                    cost+=right.top();
                    right.pop();
                    if(l<=r){
                        right.push(costs[r]);
                        r--;
                    }
                }
                else if(right.empty()){
                    cost+=left.top();
                    left.pop();
                    
                    if(l<=r){
                        left.push(costs[l]);
                        l++;
                    }
                }
                else if(left.top()<=right.top()){
                    cost+=left.top();
                    left.pop();
                    
                    if(l<=r){
                        left.push(costs[l]);
                        l++;
                    }
                }else{
                    cost+=right.top();
                    right.pop();
                    if(l<=r){
                        right.push(costs[r]);
                        r--;
                    }
                }
            }
        }
        
        return cost;
    }
};