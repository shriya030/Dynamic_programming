#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[n+1][sum+1];
    for(int i = 0; i <= n; i++) 
    for(int j = 0; j <= sum; j++) {
        if(i == 0)
            dp[i][j] = false;
        if(j == 0)
            dp[i][j] = true;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int sum = 6;
    if(isSubsetSum(arr, n, sum))
        cout<<"True";
    else
        cout<<"False";
}
