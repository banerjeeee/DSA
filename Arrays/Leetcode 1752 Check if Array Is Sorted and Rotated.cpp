Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].


class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]> nums[(i+1)% nums.size()]){
                count++;
            }
            if(count>1){ 
                return false;
            }
        }
        return true;;
        
    }
};



2nd Approach
class Solution {
public:
    bool check(vector<int>& nums) {
      int n=nums.size();
      int count=0;
      for(int i=0;i<n-1;i++){
          if(nums[i]>nums[i+1])
            count++;
      }
        if(nums[0]<nums[n-1])
         count ++;

         return count<=1;
    }
};