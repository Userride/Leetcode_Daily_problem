// Last updated: 11/27/2025, 5:17:01 PM
class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n+1)/2)*(m/2) + 1LL*(n/2)*((m+1)/2);
        
    }
};