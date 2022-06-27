// problem link --> https://www.codingninjas.com/codestudio/problems/reversing-queue_1170046

void reverse(queue < int > & q) {
    if(q.size()==0) return;
    int val=q.front();
    q.pop();
    reverse(q);
    q.push(val);
}