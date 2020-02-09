/* Binary search
   BinarySearch(A ,n,x)
   low <-0
   high <- n-1;
   while(low<=high)
      mid <- (high+low)/2;
      if(x==A[mid])
          return mid
      else if(x<A[mid])
            high=mid-1
      else
            low= mid+1;
*/

/*First occurance
   BinarySearch(A ,n,x)
   low <-0
   high <- n-1;
   result = -1
   while(low<=high)
      mid <- (high+low)/2;
      if(x==A[mid])
          result=mid; high=mid-1
      else if(x<A[mid])
            high=mid-1
      else
            low= mid+1;
     return result;
*/
/*Last occurance
   BinarySearch(A ,n,x)
   low <-0
   high <- n-1;
   result = -1
   while(low<=high)
      mid <- (high+low)/2;
      if(x==A[mid])
          result=mid; low=mid+1
      else if(x<A[mid])
            high=mid-1
      else
            low= mid+1;
     return result;
*/


#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
int LastOccurance(vector<int>& nums, int target)
{
      int  low  = 0;
    int   high = nums.size()-1;
   int result = -1;
    int mid;
   while(low<=high)
   {
      mid = (high+low)/2;
      if(target == nums[mid])
      {
          result=mid;
          low=mid+1;
       }
        else if(target<nums[mid])
            high=mid-1;
      else
            low= mid+1;
   }
     return result;
}
int FirstOccurance(vector<int>& nums, int target)
{
      int  low  = 0;
    int   high = nums.size()-1;
   int result = -1;
    int mid ;
   while(low<=high)
   {
      mid = (high+low)/2;
      if(target == nums[mid])
      {
          result=mid;
          high=mid-1;
       }
        else if(target<nums[mid])
            high=mid-1;
      else
            low= mid+1;
   }
     return result;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    { 
         vector<int> indices {-1, -1};
        if (!nums.size())
            return indices;
    
            
               indices[0]  =  FirstOccurance (nums, target) ;
                indices[1] =  LastOccurance ( nums, target) ;
               
                return indices;
  
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

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
 vector<int> A {5,7,7,8,8,10};
        int target = 8 ;

  vector<int>res = Solution().searchRange(A, target);
  printArray(res);
  return 0;
  }


