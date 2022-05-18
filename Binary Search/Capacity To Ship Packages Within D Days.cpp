// problem link --> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Quetion on Answer on Bianry Search

class Solution {
public:
    bool isPossible(vector<int> &pages,int books,int maxLoad,int Totalstudent)
    {
        int currStud=1;
        int currpages=0;
        
        for(int i=0;i<books;i++)
        {
            currpages+=pages[i];
            if(currpages>maxLoad)
            {
                currStud++;
                currpages=pages[i];
            }
            if(currStud>Totalstudent)
                return false;
        }
        
        return true;
    }
    int maxOfArray(vector<int> &pages,int books)
    {
        int mx=0;
        for(int i=0;i<books;i++)
            mx=max(mx,pages[i]);
            
        return mx;
    }
    int SumOfArray(vector<int> &pages,int books)
    {
        int sum=0;
        for(int i=0;i<books;i++)
            sum+=pages[i];
            
        return sum;
    }
    //Function to find minimum number of pages.
    int findPages(vector<int> &pages, int books, int Totalstudent) 
    {
        int low=maxOfArray(pages,books);
        int high=SumOfArray(pages,books);
        
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isPossible(pages,books,mid,Totalstudent))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // book-allocation Problem modified version
        return findPages(weights,weights.size(),days);
    }
};