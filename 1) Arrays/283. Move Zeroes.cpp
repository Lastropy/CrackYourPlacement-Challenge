class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // https://leetcode.com/problems/move-zeroes/
        // one pointer
        int pos = 0;
        for(int i: nums){
            if(i == 0)
                continue;
            nums[pos++] = i;
        }
        for(int i = pos; i < nums.size(); i++)
            nums[i] = 0;
        
    }
};
