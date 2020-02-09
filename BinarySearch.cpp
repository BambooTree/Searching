#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
         {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) 
            {
                return mid;
            }
            if(nums[mid] < target) 
            {
                left += 1;
            }
            if(nums[mid] > target) 
            {
                right -= 1;
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
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

*/
  
        vector<int> A {-1,0,3,5,9,12};
        printArray(A);
        int target = 9; 

        int res = Solution().search(A,target);
        cout<<"res "<<res<<endl;
        return 0;
        }