// Last updated: 11/28/2025, 12:48:43 PM
class Solution {
public:
    int minSensors(int n, int m, int k) {
        int d = 2 * k + 1;  
        
        int r = 0; 
        int rows = 0;
        while (r < n) {
            rows++;
            r += d;  
        }
        
        int c = 0;  
        int coloumn = 0;
        while (c < m) {
            coloumn++;
            c += d;   
        }
        
        return rows * coloumn;
    }
};
