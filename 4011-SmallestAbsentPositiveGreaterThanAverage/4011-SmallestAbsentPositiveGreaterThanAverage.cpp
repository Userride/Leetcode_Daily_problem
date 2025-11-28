// Last updated: 11/28/2025, 12:48:30 PM
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg = 0; 
        int n = nums.size();
        int tavg;
        set<int> st(nums.begin(), nums.end()); 

        for (int i = 0; i < n; i++) {
            avg += nums[i]; 
        }
         tavg = avg / n;   

        int start = (tavg) + 1;     
        if (start < 1) 
        {
            start = 1; 
        }

        while (true) {   
            if (st.find(start) == st.end()) {
                return start;
            }
            start++;
        }
    }
};
