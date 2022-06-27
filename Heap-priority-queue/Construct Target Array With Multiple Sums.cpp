// problem link --> https://leetcode.com/problems/construct-target-array-with-multiple-sums/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum=0;
        priority_queue<int> pq;
        
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        
        while(pq.top()!=1){
            int value=pq.top();
            pq.pop();
            long diff=sum-value;
            
            if(diff==1) return true;
            
            if(diff>value || diff==0 || value%diff==0) return false;
            
            value%=diff;
            sum=diff+value;
            pq.push(value);
        }
        return true;
    }
};