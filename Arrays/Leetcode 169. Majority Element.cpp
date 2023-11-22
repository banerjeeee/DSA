Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3


Approach 1 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto a:nums){
            m[a]++;
            if(m[a]>nums.size()/2)return a;
        }
        return -1;
        
    }
};

  Approach 2
  class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int major=nums[nums.size()/2];
        return major;
        
    }
};



Approach 3 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int votes=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==candidate){
                votes++;

            }
            else{
                votes--;
            }
            if(votes==0){
                candidate=nums[i];
                votes=1;
            }
        }
        return candidate;

        
    }
};