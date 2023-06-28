//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

// i*i<n can be used to prevent the calling of another function

// vector<int> ls;
// for(int i=0;i<sqrt(n);i++){            ----> O(sqrt(n))
//     if((n%i)==0){
//         ls.push_back(i);
//         if(n/i!=i)
//             ls.push_back(n/i);
//     }
//     sort(ls.begin(),ls.end()) ---> O(no of factors * log(no of factors))

//  for(auto it : ls){ cout<<it<<endl;} --> O(no of factors)
// }

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum = 0;
        for(int i=0;i<N;i++){
            sum+=(N/i)*i;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends