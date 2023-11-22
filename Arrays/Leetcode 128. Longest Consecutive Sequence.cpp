Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Approach 1 brute force.
class Solution {
public:
     bool findnumber(int num,vector<int>& nums){
         for(int a: nums){  //O(N)
             if(a==num)return true;
         }
         return false;
     }
    int longestConsecutive(vector<int>& nums) {
       int n= nums.size();
        int ans=0;
        for(int i=0;i<n;i++){  //O(N)
            int start=nums[i];
            while(findnumber(start,nums)){   //O(N*N) 
                start++;

            }
   ans=max(ans,start-nums[i]);
        }
        return ans;
    }
};


Approach 2 via sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.empty())return 0;
        int seqlen=1;
        int  maxlen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                seqlen++;
            }
            else if(nums[i]==nums[i-1]) continue;
            else{//pechala number seq mi nahi hai islia jo seq chal raha tha usse band karke dusra seq start karunga
                seqlen=1;     
            }
            maxlen=max(maxlen,seqlen);
        }
        return maxlen;
        
    }
};


Approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int> box;
        for(int i=0;i<nums.size();i++){
            box.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int start=nums[i];
            if(box.find(start-1)!=box.end()) continue;
            while(box.find(start)!=box.end()){
                start++;
            }
            ans=max(ans,start-nums[i]);
        }
        return ans;

        
    }
};