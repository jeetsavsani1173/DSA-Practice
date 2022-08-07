// problem link --> https://practice.geeksforgeeks.org/problems/polynomial-addition/1

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        Node* dummy=new Node(0,0);
        Node* tail=dummy;
        
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->pow==p2->pow){
                Node* temp=new Node(p1->coeff+p2->coeff,p1->pow);
                tail->next=temp;
                tail=tail->next;
                p1=p1->next;
                p2=p2->next;
            }else if(p1->pow>p2->pow){
                Node* temp=new Node(p1->coeff,p1->pow);
                tail->next=temp;
                tail=tail->next;
                p1=p1->next;
            }else{
                Node* temp=new Node(p2->coeff,p2->pow);
                tail->next=temp;
                tail=tail->next;
                p2=p2->next;
            }
        }
        
        while(p1!=NULL){
            Node* temp=new Node(p1->coeff,p1->pow);
            tail->next=temp;
            tail=tail->next;
            p1=p1->next;
        }
        
        while(p2!=NULL){
            Node* temp=new Node(p2->coeff,p2->pow);
            tail->next=temp;
            tail=tail->next;
            p2=p2->next;
        }
        
        return dummy->next;
    }
};