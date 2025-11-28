// Last updated: 11/28/2025, 12:48:59 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int r1= abs(z-x);
        int r2=abs(z-y);

        if(r1==r2){
            return 0;
        }
        else if(r1>r2){
            return 2;
        }
        else{
            return 1;
        }
        return -1;
    }
};