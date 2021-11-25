// problem link -->>  https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/?category[]=Arrays&category[]=Arrays&difficulty[]=0&difficulty[]=1&page=1&query=category[]Arraysdifficulty[]0difficulty[]1page1category[]Arrays


class Solution{
    public:
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        
        if(arr.size()==1)
        return ;
        else if(arr.size()==2)
        {
            swap(arr[0],arr[1]); 
            return ;
        }
        else
        {
            int i=0;
            int j=1;
            while(i<=(n-2))
            {
                swap(arr[i],arr[j]);
                i+=2;
                j+=2;
            }
        }
    }
};