#include <bits/stdc++.h>
using namespace std;

bool printSubSum(int ind, vector<int> &ds, int arr[], int sum, int s, int n)
{
    // base case
    if (ind == n)
    {
        // true condition
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // take case
    s += arr[ind];
    ds.push_back(arr[ind]);
    if (
        printSubSum(ind + 1, ds, arr, sum, s, n) == true)
        return true;

    // not take case
    s -= arr[ind];
    ds.pop_back();
    if (
        printSubSum(ind + 1, ds, arr, sum, s, n) == true)
        return true;

    return false;
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
    vector<int> ds;
    printSubSum(0, ds, arr, sum, 0, n);
}