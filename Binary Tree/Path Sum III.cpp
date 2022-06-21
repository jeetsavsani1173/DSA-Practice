// problem link --> https://leetcode.com/problems/path-sum-iii/

// first solution TC: O(N^2)
class Solution {
public:
    int ans;
    void isStarted(TreeNode* root,long long CurrSum,int targetSum)
    {
        if(root==NULL) return;
        
        CurrSum+=(root->val);
        if(CurrSum==targetSum)
            ans++;
        
        isStarted(root->left,CurrSum,targetSum);
        isStarted(root->right,CurrSum,targetSum);
    }
    void PathSumhelper(TreeNode* root,int targetSum) // consider all node as a root..
    {
        if(root==NULL) return;
        
        isStarted(root,0ll,targetSum);
        PathSumhelper(root->left,targetSum);
        PathSumhelper(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        PathSumhelper(root,targetSum);
        return ans;
    }
};

// second solution.. hashmap+backtracking TC : O(N)
class Solution {
public:
    int ans;
    void dfs(TreeNode* root,long long CurrSum,int targetSum,map<int,int>&mp)
    {
        if(root==NULL) return;
        
        CurrSum+=(root->val);
        ans+=(mp[CurrSum-targetSum]);
        mp[CurrSum]++;
        
        dfs(root->left,CurrSum,targetSum,mp);
        dfs(root->right,CurrSum,targetSum,mp);
        mp[CurrSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        map<int,int> mp;
        mp[0]=1;
        dfs(root,0ll,targetSum,mp);
        return ans;
    }
};