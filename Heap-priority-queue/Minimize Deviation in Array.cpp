// problem link --> https://leetcode.com/problems/minimize-deviation-in-array/

// first solution 
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                nums[i]*=2;
            mn=min(mn,nums[i]);
            pq.push(nums[i]);
        }

        int diff_ans=INT_MAX;
        while(1)
        {
            int mx=pq.top();
            pq.pop();
            diff_ans=min(diff_ans,mx-mn);
            mn=min(mx/2,mn);
            if(mx%2==0)
            {
                mx/=2;
                pq.push(mx);
            }   
            else
                break;
        }

        return diff_ans;
    }
};

// second Solution
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
                nums[i]*=2;
            st.insert(nums[i]);
        }

        int diff_ans=INT_MAX;
        while(true)
        {
            int mx=*(--st.end());
            int mn=*st.begin();
            diff_ans=min(diff_ans,mx-mn);
            if(mx%2==0)
            {
                st.erase(mx);
                st.insert(mx/2);
            }
            else
                break;
        }

        return diff_ans;
    }
};