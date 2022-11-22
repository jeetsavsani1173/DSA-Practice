// problem link --> https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int> &arr, int n)
    {
        vector<pair<int, int>> arrPos(n);
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos.begin(), arrPos.end());

        vector<bool> vis(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] || arrPos[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;

                j = arrPos[j].second;
                cycle_size++;
            }
            if (cycle_size > 0)
            {
                ans += (cycle_size - 1);
            }
        }

        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int lsize=q.size();
            vector<int> vect;
            while(lsize--)
            {
                auto it=q.front();
                q.pop();
                
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                
                vect.push_back(it->val);
            }
            
            ans+=minSwaps(vect,vect.size());
        }
        
        return ans;
    }
};