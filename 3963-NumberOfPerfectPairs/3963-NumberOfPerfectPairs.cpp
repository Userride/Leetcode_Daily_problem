// Last updated: 11/28/2025, 12:48:40 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = (int)nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = llabs((long long)nums[i]);
        sort(a.begin(), a.end());

        long long result = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < i + 1) j = i + 1;                  
            while (j < n && a[j] <= 2 * a[i]) ++j;    
            result = result + (j - i - 1);                      
        }
        return result;
    }
};
