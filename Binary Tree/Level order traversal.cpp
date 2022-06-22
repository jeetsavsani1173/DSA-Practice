// problem link --> https://practice.geeksforgeeks.org/problems/level-order-traversal/1

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(root==NULL) return {};
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int LevelSize=q.size();
            for(int i=0;i<LevelSize;i++)
            {
                Node* curr=q.front();
                q.pop();
                ans.push_back(curr->data);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return ans;
    }
};