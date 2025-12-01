// Last updated: 12/1/2025, 12:51:54 PM
class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};