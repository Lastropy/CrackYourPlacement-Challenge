class Solution {
public:
    void sortColors(vector<int>& nums) {
        //https://leetcode.com/problems/sort-colors/submissions/
        // use counting sort concept.
        int count[3]={0};
        for(int i: nums)
            count[i]++;
        int pos = 0;
        for(int i = 0; i < 3; i++)
            while(count[i]--)
                nums[pos++]=i;
    }
};
