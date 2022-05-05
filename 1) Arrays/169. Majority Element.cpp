class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // https://leetcode.com/problems/majority-element/
        // Moore's Voting Algorithm
        int cnt = 0;
        int ele;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt == 0)
                ele = nums[i];
            if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for(int i: nums)
            if(i == ele)
                cnt++;
        if(cnt >= (int)(nums.size()/2))   return ele;
        return -1;
    }
};
