#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

//https://www.youtube.com/watch?v=LPFhl65R7ww

using namespace std;



 class Solution {
public:
    double findMedianSortedArraysBS(vector<int>& input1, vector<int>& input2) {
          //if input1 length is greater than switch them so that input1 is smaller than input2.
        if (input1.size() > input2.size()) {
            return findMedianSortedArraysBS(input2, input1);
        }
        int x = input1.size();
        int y = input2.size();

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2;
            int partitionY = (x + y + 1)/2 - partitionX;

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? INT_MIN : input1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : input1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
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
   int[] x = {1, 3, 8, 9, 15};
        int[] y = {7, 11, 19, 21, 18, 25};

*/
  
        vector<int> A {1, 3, 8, 9, 15};
       vector<int> B{7, 11, 19, 21, 18, 25};
        
        
        
        
        double ret = Solution().findMedianSortedArraysBS(A, B);

       cout<<"ret  "<<ret<<endl;
    return 0;
}