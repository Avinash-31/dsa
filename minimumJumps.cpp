//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array
#include<bits/stdc++.h>
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int pos=0,des=0,j=0;
        
        for(int i=0;i<n;i++)
        {
            
            des=max(des,i+arr[i]);
            if(pos==i)
            {
                pos=des;
                
                j++;
                if(pos>=n-1) return j;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends