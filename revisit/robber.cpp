#include<bits/stdc++.h>


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int lastAction = 3;
    vector<vector<int>> dp(n,vector<int>(4,0));
    // For base case (day 0)
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));

    // for other days
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task = 0;task<3;task++){
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

// space optimization

#include<bits/stdc++.h>


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int lastAction = 3;
    vector<int> prev(4);
    // For base case (day 0)
    // stores the previous values
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));

    // for other days
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last] = 0;
            for(int task = 0;task<3;task++){
                if(task!=last){
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last],point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}