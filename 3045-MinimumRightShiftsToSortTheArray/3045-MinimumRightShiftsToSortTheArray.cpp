// Last updated: 11/27/2025, 5:17:34 PM
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size(); 
        
        int cnt = 0; // Initialize a counter to keep track of the number of right shifts.

        while (!is_sorted(nums.begin(), nums.end())) { // Continue looping until the vector is sorted.
            vector<int> temp(n, 0); // Create a temporary vector of the same size as nums.

            for (int i = 0; i < n; i++) {
                // Shift the elements to the right by one position (circular shift).
                temp[(i + 1) % n] = nums[i];
            }
        
            cnt++; // Increment the shift counter.
            nums = temp; // Update nums with the newly shifted vector.

            if (cnt > n) {
                // If the number of shifts exceeds the size of the vector, 
                // it means it's not possible to sort it.
                return -1;
            }
        }
        
        return cnt; // Return the total number of right shifts required to sort the vector.
    }
};