// Last updated: 11/29/2025, 4:15:40 PM
class Solution {
public:
    int maxFreeTime(int eventDuration, int maxBreaks, vector<int>& startTimes, vector<int>& endTimes) {
        
        vector<int> freeTimeGaps;
        freeTimeGaps.push_back(startTimes[0]);

        for(int i = 1; i < startTimes.size(); i++) {
            freeTimeGaps.push_back(startTimes[i] - endTimes[i - 1]);
        }

        freeTimeGaps.push_back(eventDuration - endTimes.back());

        int totalFreeTime = 0;
        if(freeTimeGaps.size() <= maxBreaks) {
            for(int i = 0; i < freeTimeGaps.size(); i++) {
                totalFreeTime += freeTimeGaps[i];
            }
            return totalFreeTime;
        } else {
            int left = 0, right = 0, currentSum = 0, maxFreeWindow = 0;
            while(right < freeTimeGaps.size()) {
                currentSum += freeTimeGaps[right];
                if(right - left + 1 < maxBreaks + 1) {
                    right++;
                } else if(right - left + 1 == maxBreaks + 1) {
                    maxFreeWindow = max(maxFreeWindow, currentSum);
                    currentSum -= freeTimeGaps[left];
                    left++;
                    right++;
                }
            }
            return maxFreeWindow;
        }
    }
};
