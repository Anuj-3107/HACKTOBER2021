//Leetcode 
//1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n=nums.size();
        vector<int> res;
        int x;
        
        for(int i=0;i<n;i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                x=nums[i];
                res.push_back(i);
                break;
            }
            
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
            if(nums[i]==target-x)
            {
                res.push_back(i);
                break;
            }
        
        return res;
    }
};