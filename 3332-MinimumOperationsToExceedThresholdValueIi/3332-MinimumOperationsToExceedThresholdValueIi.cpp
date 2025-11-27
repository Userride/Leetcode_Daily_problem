// Last updated: 11/27/2025, 5:16:53 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums)); //Heapify - log(n)

        int count = 0;

        while(!pq.empty() && pq.top() < k) {
            long smallest = pq.top(); //minimum
            pq.pop();

            long secondSmallest = pq.top(); //max
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }

        return count;

    }
};