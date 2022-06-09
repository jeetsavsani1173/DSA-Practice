// problem link --> https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    map<int,int> mp;

    for(int i=0;i<B;i++)
        mp[A[i]]++;
    
    ans.push_back(mp.size());

    for(int i=B;i<A.size();i++)
    {
        mp[A[i]]++;
        mp[A[i-B]]--;
        if(mp[A[i-B]]==0)
            mp.erase(A[i-B]);
        ans.push_back(mp.size());
    }
    return ans;
}
