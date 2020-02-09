/*

case 1 : A[mid]==target
            return mid;
case 2:  A[mid]<=A[high]
    case 2a:  target >A[mid]&& target<=A[high]
                low =mid+1
              else
                 high=mid-1;
case 3: A[low]<=A[mid]
    case 3a: target>=A[low]&&target<A[mid]
                 high=mid-1;
              else
                   low=mid+1;

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
         int low = 0, high = nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target)
              return mid;
        if(nums[mid]<=nums[high])
          {
             if(target>nums[mid] && target<=nums[high])
                low=mid+1;
              else
                 high=mid-1;
          }
          if(nums[low]<=nums[mid])
          {
             if(target>=nums[low] && target <nums[mid])
                    high=mid-1;
              else
                   low=mid+1;
          }
        }
    return -1;
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

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/
  
        vector<int> A {4,5,6,7,0,1,2};
        int target = 0 ;
      
        
        
        
        
        int ret = Solution().search(A, target);

       cout<<"ret  "<<ret<<endl;
    return 0;
}