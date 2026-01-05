
https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> v;
        for(int i=0;i<start.size();i++)
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), cmp);

        int cnt = 1;
        int lastEnd = v[0].second;

        for(int i=1;i<v.size();i++){
            if(v[i].first > lastEnd){
                cnt++;
                lastEnd = v[i].second;
            }
        }
        return cnt;
    }
};

