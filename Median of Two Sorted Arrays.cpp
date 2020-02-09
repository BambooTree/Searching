#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

//https://www.youtube.com/watch?v=oVPIQdHt_T8

using namespace std;

class Solution {
public:

  // using Binary Search
    double findMedianSortedArraysBS(vector<int>& nums1, vector<int>& nums2) 
    {
   
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        int numsSize = nums1Size + nums2Size;
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int>nums(numsSize*sizeof(int));
        while (i < nums1Size || j < nums2Size)
        {
            if (i < nums1Size && j < nums2Size)
            {
                if (nums1[i] < nums2[j])
                {
                    nums[k] = nums1[i];
                    i++;
                    k++;
                } 
                else 
                {
                    nums[k] = nums2[j];
                    j++;
                    k++;
                }
            } 
            else if (i < nums1Size) 
            {
                nums[k] = nums1[i];
                i++;
                k++;
            } 
            else if (j < nums2Size) 
            {
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }

        if (numsSize % 2 == 0) 
        {
            return (double)(nums[numsSize/2-1] + nums[numsSize/2]) / 2.0;
        } 
        else 
        {
            return nums[numsSize/2];
        }
        
    }

    // using DP Programming

int findkth(vector<int>&nums1, int start1,vector<int>&nums2, int start2,int k)
{
    int nums1Size = nums1.size();
    int nums2Size = nums2.size();    
    if(start1>=nums1Size)
    {
        return nums2[start2+k-1];
    }

    if(start2>=nums2Size)
    {
        return nums1[start1+k-1];
    }
    if(k==1)
    {
        return min(nums1[start1],nums2[start2]);
    }

    int index1=start1+k/2-1;
    int index2=start2+k/2-1;

    int key1= index1<nums1Size? nums1[index1]:INT_MAX;
    int key2= index2<nums2Size? nums2[index2]:INT_MAX;

    if(key1<key2)
    {
        return findkth(nums1 ,start1+k/2,nums2,start2,k-k/2 );
    }
    else
    {
         return findkth(nums1 ,start1,nums2,start2+k/2,k-k/2 );
    }
      
    
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
 {
    int total= nums1.size()+nums2.size();


    if(total %2==1)
    {
        return findkth(nums1 ,0,nums2,0,total/2+1);
    }
    else
    {
        return (findkth(nums1,0,nums2,0,total/2)+findkth(nums1,0,nums2,0,total/2+1))/2.0;

    }
}

};

void printArray(vector<int> arr) 
{ 
    for (int i=0; i < arr.size(); i++) 
        cout << arr[i] << " "; 
    cout << "\n"; 
}

int main() {

    /*
Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/
  
        vector<int> A {1,2};
        vector<int> B {3,4};
        
        
        
        double ret = Solution().findMedianSortedArraysBS(A, B);

       cout<<"ret  "<<ret<<endl;
    return 0;
}