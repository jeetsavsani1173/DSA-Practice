// problem link --> https://practice.geeksforgeeks.org/problems/find-length-of-loop/1#

//Function to find the length of a loop in the linked list.
int countNodesinLoop(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    
    if(fast==NULL || fast->next==NULL)
        return 0;
    else{
        int cnt=1;
        Node* temp=slow->next;
        while(temp!=slow){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
}