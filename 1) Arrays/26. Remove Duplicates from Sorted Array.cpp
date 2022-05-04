class Solution {
public:
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    // pointer
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            nums[++pos] = nums[i];
        }
        return pos+1;
    }
};
