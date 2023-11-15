287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Code

//visited Solution Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int index= abs(nums[i]);
            //if already visited
            if(nums[index]<0){
                return index;
            } 
            //if not visited we will mark visited
            nums[index]*=-1;
        }
        return -1;
        
    }
};


//Position Method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]); 

        }
        return nums[0];
        
    }
};