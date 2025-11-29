// Last updated: 11/29/2025, 4:15:39 PM
class Solution {
private:
    long long log4(long long num) {
        long long ans = 0;
        while (num / 4) {
            num /= 4;
            ans++;
        }
        return ans;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (vector<int> &query : queries) {
            long long left = query[0], right = query[1], temp = 0;
            while (right >= left) {
                long long exp = log4(right);
                long long nearestPow4 = pow(4, exp); 
                nearestPow4 = max(nearestPow4, left);
                temp += (right - nearestPow4 + 1) * (exp + 1); 
                right = nearestPow4 - 1;
            }
            ans += (temp + 1) / 2;
        }
        return ans;
    }
};
