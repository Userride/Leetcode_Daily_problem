// Last updated: 11/27/2025, 5:17:50 PM
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int i = 1;  
        int count = 0;

        while (i <= 60) {   
            long long x = (long long)num1 - (long long)i * num2;

            if (x >= i && __builtin_popcountll(x) <= i) {
                return i;
            }

            i++;
        }
        return -1;   
    }
};
