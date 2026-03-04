//Brute recursively
#include<limits.h>
using namespace std;
int helper(int day,vector<vector<int>>&points,int task){
    int maxi = INT_MIN;
    if(day == 0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=task)
            {
                maxi = max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    maxi = 0;
    for(int i=0;i<3;i++)
    {
        if(i!=task)
        {
            int point = points[day][i] + helper(day-1,points,i);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int day = n-1;
    int maxi = INT_MIN;
    for(int i=0;i<3;i++)
    {
        //yaha s har uske liye chala do 
        int strt = points[day][i] + helper(day-1,points,i);
        maxi = max(strt,maxi);
    }
    return maxi;
}


//memoization && cache


#include<limits.h>
using namespace std;

int helper(int day,vector<vector<int>>&points,int task,
            vector<vector<int>>&dp){

    int maxi = INT_MIN;
    if(day == 0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=task)
            {
                maxi = max(maxi,points[day][i]);
            }
        }
        return maxi;
    }

    if(dp[day][task] != -1) return dp[day][task];

    maxi = 0;
    for(int i=0;i<3;i++)
    {
        if(i!=task)
        {
            int point = points[day][i] + helper(day-1,points,i,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][task] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(3,-1));
    int day = n-1;
    int maxi = INT_MIN;
    
    for(int i=0;i<3;i++)
    {
        //yaha s har uske liye chala do 
        int strt = points[day][i] + helper(day-1,points,i,dp);
        maxi = max(strt,maxi);
    }
    return maxi;
}


//tabulation

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max({points[0][0],points[0][1],points[0][2]});

    //yh base case ready hogye hai ab task hai age proceed krne ki to 
    //yh task humne bananeye day 0 k hisb s tho ab day 1 s strt krte hai 
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;    //ab isko hi find krna hai 
            for(int task=0;task<3;task++)
            {
                if(task!=last)      //agr jo humne dundha hai task wo alg hai 
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}



//space optimization

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>dummy(4,-1);
    dummy[0]=max(points[0][1],points[0][2]);
    dummy[1]=max(points[0][0],points[0][2]);
    dummy[2]=max(points[0][0],points[0][1]);
    dummy[3]=max({points[0][0],points[0][1],points[0][2]});

    //yh base case ready hogye hai ab task hai age proceed krne ki to 
    //yh task humne bananeye day 0 k hisb s tho ab day 1 s strt krte hai 
    for(int day=1;day<n;day++)
    {
        vector<int>dummy2(4,-1);
        for(int last=0;last<4;last++)
        {
            //dp[day][last]=0;    //ab isko hi find krna hai 
            dummy2[last] = 0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)      //agr jo humne dundha hai task wo alg hai 
                {
                    int point = points[day][task] + dummy[task];
                    dummy2[last] = max(dummy2[last],point);
                }
            }
        }
        dummy=dummy2;
    }
    return dummy[3];
}
