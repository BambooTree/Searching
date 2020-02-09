//https://www.youtube.com/watch?v=XOdT5_uXjJc

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end =nums.size()-1;
        int mid ;
        while(start+1 <end)
        {
            
            int mid = start + (end-start)/2;
            if(nums[mid]== target)
            {
                return mid ;
            }
            else if (nums[mid]>target)
            {
                end = mid;
            }
            else {
                // nums[mid]<target
                start = mid;
            }
                
        }
        
        if(nums[end]<target)
            return end+1;
        else if (nums[start]>= target)
            return start;
        else 
            // nums[start]<target<nums[end]
            return end;
    }
};
void printArray(vector<int> arr) 
{ 
    for (int i=0; i < arr.size(); i++) 
        cout << arr[i] << " "; 
    cout << "\n"; 
}

int main() 
{
/*Input: [1,3,5,6], 5
Output: 2

Input: [1,3,5,6], 2
Output: 1

Input: [1,3,5,6], 7
Output: 4


Input: [1,3,5,6], 0
Output: 0
*/

   vector<int>A{1,3,5,6};
   int target = 2;
   int res = Solution().searchInsert(A,target);
   cout << "res "<<res<<endl;

   return 0;
}