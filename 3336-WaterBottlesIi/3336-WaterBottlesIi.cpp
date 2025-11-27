// Last updated: 11/27/2025, 5:16:52 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            numExchange++;
            bottleDrunk++;
            emptyBottles++;
        }
        return bottleDrunk;
    }
};