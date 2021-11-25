// problem link -->> https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums2.size());
        temp[nums2.size()-1]=-1;
        stack<int> st;
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--)
        {
            while(st.size()>0 && st.top()<=nums2[i])
                st.pop();
            
            if(st.size()>0)
                temp[i]=st.top();
            else
                temp[i]=-1;
            
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans.push_back(temp[j]);
                    break;
                }
            }
        }
        
        return ans;
    }
};