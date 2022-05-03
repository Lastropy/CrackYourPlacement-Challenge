class Solution {
public:
    // https://leetcode.com/problems/find-the-duplicate-number/
    // using cyclic sort to rearrange the array
     int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            while(nums[nums[i]-1] != nums[i])
                swap(nums[nums[i]-1],nums[i]); 
        for(int i = 0; i < nums.size(); i++)
            if(nums[i]!=i+1)
                return nums[i];
        return -1;
    }
};
