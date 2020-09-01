#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a > b ? a : b);
}

int count(char a[], int m){
    int i, j;
    int T[m+1][m+1];
    char b[m];
    for(i=0; i<m; i++){
        b[i] = a[i];
    }
    for(i=0; i<m+1; i++){
        for(j=0; j<m+1; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
        }
    }
    for(i=1; i<m+1; i++){
        for(j=1; j<m+1; j++){
            if(a[i-1] == b[j-1] && i!=j)
                T[i][j] = 1+T[i-1][j-1];
            else
                T[i][j] = max(T[i][j-1], T[i-1][j]);
        }
    }
    return T[m][m];

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, res;
        cin>>n;
        char X[n];
        for(int i=0; i<n; i++){
            cin>>X[i];
        }
        res = count(X, n);
        cout<<res<<endl;
    }
}