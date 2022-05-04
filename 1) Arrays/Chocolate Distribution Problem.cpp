class Solution{
    // https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/#
    // Basic Sliding Window after sorting
    public:
        long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        if(m == 1)
            return 0;
        long long ans = INT_MAX;
        sort(a.begin(),a.end());
        for(int i = 0; i < n-m+1; i++){
              if(a[i+m-1]-a[i] < ans)
                  ans  = a[i+m-1]-a[i];
        }
         return ans;
    }   
};
