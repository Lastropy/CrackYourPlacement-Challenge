class Solution {
public:
    // https://leetcode.com/problems/find-all-duplicates-in-an-array/
    // cyclic sort
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[nums[i]-1] != nums[i] )
            {
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i]!= i+1)
                ans.push_back(nums[i]);
        return ans;
    }
};
