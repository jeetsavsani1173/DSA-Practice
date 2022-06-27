// problem link --> https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271

class NStack
{
public:
    vector<int> arr,next,top;
    int freeIdx;
    NStack(int k, int N)
    {
        arr=vector<int>(N,0);
        next=vector<int>(N,0);
        top=vector<int>(k,-1);
        
        for(int i=0;i<N;i++)
            next[i]=i+1;
        next[N-1]=-1;
        
        freeIdx=0;
    }

    bool push(int x, int m)
    {
        if(freeIdx==-1) return false;
        
        int currIdx=freeIdx;
        arr[currIdx]=x; 
        freeIdx=next[freeIdx];
        next[currIdx]=top[m-1];
        top[m-1]=currIdx;
        
        return true;
    }
    
    int pop(int m)
    {
        if(top[m-1]==-1) return -1;
        
        int currIdx=top[m-1];
        top[m-1]=next[currIdx];
        next[currIdx]=freeIdx;
        freeIdx=currIdx;
        
        return arr[currIdx];
    }
};