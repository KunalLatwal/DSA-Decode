class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int>mp;
    for(int i=0;i<tasks.size();i++)
    {
        char ch = tasks[i];
        mp[ch]++;
    }
    priority_queue<tuple<int,char>>q;
    for(auto i : mp)
    {
        int freq = i.second;
        char task = i.first;

        q.push({freq,task});
    }
    int timer=0;
    queue<tuple<int,int,char>>rq;
    //yh hold krege freq  or entry time and task
    while(!q.empty() || !rq.empty())
    {
        timer++;
        if(!q.empty())
        {
            //running k element process
            auto [f,t] = q.top();
            q.pop();
            f--;
            if(f>0) rq.push({f,timer+n,t});
        }
        if(!rq.empty())
        {
            //ab hum ready queue krenge process
            auto [freq,entry,task]  = rq.front();
            if(entry == timer)
            {
                q.push({freq,task});
                rq.pop();
            }
        } 
    }
    return timer;
    }
};
