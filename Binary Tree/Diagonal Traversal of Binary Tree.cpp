// problem link --> https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1#

vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       Node* curr=q.front();
       q.pop();
       
       while(curr){
           if(curr->left) q.push(curr->left);
           ans.push_back(curr->data);
           curr=curr->right;
       }
   }
   return ans;
}