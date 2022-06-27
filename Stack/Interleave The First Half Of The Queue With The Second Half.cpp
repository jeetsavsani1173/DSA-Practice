// problem link --> https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450

void interLeaveQueue(queue < int > & q) {
    int len=q.size();
    queue<int> temp_q;
    for(int i=0;i<len/2;i++)
    {
        temp_q.push(q.front());
        q.pop();
    }
    
    for(int i=0;i<len/2;i++)
    {
        q.push(temp_q.front());
        temp_q.pop();
        q.push(q.front());
        q.pop();
    }
}