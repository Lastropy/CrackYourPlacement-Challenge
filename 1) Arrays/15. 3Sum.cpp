class Solution {
public:
    // https://leetcode.com/problems/3sum/
    // 2 sum upgraded + duplicates
    vector<vector<int>> threeSum(vector<int>& a) {
        if(a.size()<3)
             return vector<vector<int>>();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for(int i = 0; i < a.size(); i++)
        {
            if(-a[i] < 0) break;
            int f = i+1;
            int b =  a.size()-1;
            while(f<b){
                int s = a[i] + a[f]+a[b];
                if(s < 0)
                    f++;
                else if( s > 0)
                    b--;
                else{
                    vector<int> temp({a[i],a[f],a[b]});
                    ans.push_back(temp);
                    while(f < b && a[f] == temp[1] ) f++;
                    while(f < b && a[b] == temp[2]) b--;
                }
                while(i + 1 < a.size() && a[i+1]== a[i]) i++;
            }
        }
        return ans;
    }
};
