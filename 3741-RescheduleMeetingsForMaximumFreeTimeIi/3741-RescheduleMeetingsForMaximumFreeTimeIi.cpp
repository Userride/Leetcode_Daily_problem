// Last updated: 11/29/2025, 4:15:41 PM
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeDurations;
        freeDurations.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); i++) {
            freeDurations.push_back(startTime[i] - endTime[i - 1]);
        }

        freeDurations.push_back(eventTime - endTime.back());

        int n = freeDurations.size();
        vector<int> maxRight(n, 0);
        vector<int> maxLeft(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], freeDurations[i + 1]);
        }

        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], freeDurations[i - 1]);
        }

        int maxTime = 0;
        for (int i = 1; i < n; i++) {
            int duration = endTime[i - 1] - startTime[i - 1];

            if (duration <= max(maxLeft[i - 1], maxRight[i])) {
                maxTime = max(maxTime, freeDurations[i - 1] + duration + freeDurations[i]);
            }

            maxTime = max(maxTime, freeDurations[i - 1] + freeDurations[i]);
        }

        return maxTime;
    }
};
