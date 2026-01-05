Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        int arrows = 1;
        long end = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > end) {
                arrows++;
                end = points[i][1];
            } else {
                end = min(end, (long)points[i][1]);
            }
        }
        return arrows;
    }
};
