#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ways(int arr[], int sum, int n){
    int i,j;
    int T[n+1][sum+1];
    for(i=0; i<n+1; i++){
        for(j=0; j<sum+1; j++){
            if(i==0)
                T[i][j] = 0;
            if(j==0)
                T[i][j] = 1;
        }
    }
    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                T[i][j] = (T[i][j - arr[i-1]] + T[i-1][j]);
            }
            else
            {
                T[i][j] = T[i-1][j];
            }
            
        }
    }
    return T[n][sum];
}
int main(){
    int t;
    cin>>t;
    int score[] = {3, 5, 10};
    while(t--){
        int n, res;
        cin>>n;
        res = ways(score, n, 3);
        cout<<res<<endl;
    }
    return 0;
}