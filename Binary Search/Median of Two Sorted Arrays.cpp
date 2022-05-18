// problem link --> https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int N=nums1.size()+nums2.size();
        int Nby2=(N+1)/2;
        
        int low=0,high=nums1.size();
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int aleft=(mid-1>=0)?nums1[mid-1]:INT_MIN;
            int aright=(mid<nums1.size())?nums1[mid]:INT_MAX;
            int bleft=(Nby2-mid-1>=0)?nums2[Nby2-mid-1]:INT_MIN;
            int bright=(Nby2-mid<nums2.size())?nums2[Nby2-mid]:INT_MAX;
            
            if(aleft<=bright && bleft<=aright){
                // find median of selected element
                if(N&1){// odd element case
                    return max(aleft,bleft);
                }
                else{ // even case
                    return (max(aleft,bleft)+min(aright,bright))/2.0;
                }
                
            }
            else if(aleft>bright){
                high=mid-1;
            }
            else{
                // bleft>aright
                low=mid+1;
            }
            
        }
        return 0.0;
    }
};