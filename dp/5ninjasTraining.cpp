// Using recursive approach
#include<bits/stdc++.h>

int fn(int ind,vector<vector<int>> &points,int lastAction){
    //for day 0
    int maxi;
    if(ind == 0){
        maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=lastAction){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    // for rest of the days
    maxi = 0;
    int point;
    for(int i=0;i<3;i++){
        if(i!=lastAction){
            point = points[ind][i] + fn(ind-1,points,i);
            maxi = max(point,maxi);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int lastAction = 3;
    // vector<vector<int>> dp()
    return fn(n-1,points,lastAction);
}
TC - exponential time complexity


// using dp

#include<bits/stdc++.h>


int fn(int ind,vector<vector<int>> &points,int lastAction,vector<vector<int>> &dp){
    //for day 0
    int maxi;
    if(ind == 0){
        maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=lastAction){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[ind][lastAction]!=-1)
        return dp[ind][lastAction];
    // for rest of the days
    maxi = 0;
    int point;
    for(int i=0;i<3;i++){
        if(i!=lastAction){
            point = points[ind][i] + fn(ind-1,points,i,dp);
            maxi = max(point,maxi);
        }
    }
    return dp[ind][lastAction] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int lastAction = 3;
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return fn(n-1,points,lastAction,dp);
}

// using tabular approach

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