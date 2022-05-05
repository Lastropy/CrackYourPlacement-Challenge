class Solution {
public:
    int maxProfit(vector<int>& a) {
        //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
        // keep adding positive profits till prev < current
        int ans = 0;
        for(int i =1 ; i < a.size(); i++)
        {
            if(a[i-1] < a[i])
                ans += a[i] - a[i-1];
        }
        return max(ans,0);
    }
};
