#include <bits/stdc++.h>
using namespace std;

int printSubSum(int ind, int arr[], int sum, int s, int n)
{
    // base case
    if (ind == n)
    {
        // true condition
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }

    // take case
    s += arr[ind];
    int l = printSubSum(ind+1,arr,sum,s,n);

    // not take case
    s -= arr[ind];
    int r = printSubSum(ind + 1, arr, sum, s, n);

    return (l+r);
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<printSubSum(0, arr, sum, 0, n)<<endl;
}