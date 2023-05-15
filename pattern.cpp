#include<bits/stdc++.h>
using namespace std;

void pattern(int n){
    for(int i=0;i<=2*n-2;i++){
        for(int j=0;j<=2*n-2;j++){
            int min1 = min(i,j);
            int min2 = min(2*n-2-i,2*n-2-j);
            cout<<n-min(min1,min2);
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    pattern(n);
}