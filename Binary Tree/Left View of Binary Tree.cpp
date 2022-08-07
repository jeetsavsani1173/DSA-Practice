// problem link --> https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/#

vector<int> leftView(Node *root)
{
   if(root==NULL) return {};
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            ans.push_back(q.front()->data);
            
            while(len--){
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return ans;
}
