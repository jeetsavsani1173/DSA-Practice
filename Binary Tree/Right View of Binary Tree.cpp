// problem link --> https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/#

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if(root==NULL) return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            
            while(len--){
                Node* node=q.front();
                q.pop();
                
                if(len==0) ans.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return ans;
    }
};

