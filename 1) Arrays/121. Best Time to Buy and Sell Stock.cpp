class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
        // Concept similar to Kadane's Algo -> Global minima and local minima
        int ans = 0;
        int minSoFar = INT_MAX;
        for(int price : prices)
        {
            minSoFar = min(minSoFar,price);
            ans = max(ans, price- minSoFar);
        }
        return ans;
    }
};
