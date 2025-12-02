// Last updated: 12/2/2025, 11:16:47 PM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long mod = 1000000007;
        unordered_map<int,long long> mp;
        for(auto &p: points) mp[p[1]]++;

        vector<long long> v;
        for(auto &x: mp){
            if(x.second >= 2){
                long long c = (x.second * (x.second - 1) / 2) % mod;
                v.push_back(c);
            }
        }

        long long sum = 0, ans = 0;
        for(long long x : v){
            ans = (ans + x * sum) % mod;
            sum = (sum + x) % mod;
        }
        return ans;
    }
};
