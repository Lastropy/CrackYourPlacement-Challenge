class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // https://leetcode.com/problems/two-sum/
        // use a map to check the compliments presence
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(target-nums[i])!= m.end())
                return vector<int>({i,m[target-nums[i]]});
            m.insert({nums[i],i});
        }
        return  vector<int>();
    }
};
