// problem link --> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// first solution SC : O(H) where H is height of binary tree
class Solution {
public:
    bool find_path(TreeNode* root,TreeNode* target,vector<TreeNode*> &path)
    {
        if(root==NULL) return false;
        if(root==target){
            path.push_back(root);
            return true;
        }
        
        path.push_back(root);
        if(find_path(root->left,target,path)==true) return true;
        if(find_path(root->right,target,path)==true) return true;
        path.pop_back();
        return false;
    }
    void kLevelDown(TreeNode* root,TreeNode* blocker,int k,vector<int> &ans)
    {
        if(root==NULL || k<0 || root==blocker) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kLevelDown(root->left,blocker,k-1,ans);
        kLevelDown(root->right,blocker,k-1,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> RToNpath;// root to target node path..
        if(find_path(root,target,RToNpath)==false) return {};
        
        vector<int> ans;
        RToNpath.push_back(NULL);
        for(int i=RToNpath.size()-2;i>=0;i--)
        {
            TreeNode* curr=RToNpath[i];
            TreeNode* blocker=RToNpath[i+1];
            kLevelDown(curr,blocker,k,ans);
            k--;
        }
        return ans;
    }
};

// second solution.. SC : O(1)
class Solution {
public:
    int find_path(TreeNode* root,TreeNode* target,int k,vector<int> &ans)
    {
        if(root==NULL) return -1;
        if(root==target){
            kLevelDown(root,NULL,k,ans);
            return 1;
        }
        
        int left=find_path(root->left,target,k,ans);
        if(left>0){
            kLevelDown(root,root->left,k-left,ans);
            return left+1;
        }
        
        int right=find_path(root->right,target,k,ans);
        if(right>0){
            kLevelDown(root,root->right,k-right,ans);
            return right+1;
        }
        
        return -1;
    }
    void kLevelDown(TreeNode* root,TreeNode* blocker,int k,vector<int> &ans)
    {
        if(root==NULL || k<0 || root==blocker) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kLevelDown(root->left,blocker,k-1,ans);
        kLevelDown(root->right,blocker,k-1,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        find_path(root,target,k,ans);
        return ans;
    }
};