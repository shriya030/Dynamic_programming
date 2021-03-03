#include<bits/stdc++.h>
using namespace std;
bool memo[2000][2000] = {false};
bool isSubsetSum(int arr[], int n, int sum) {
    if(memo[n][sum])
        return true;
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(arr[n-1] <= sum) 
        return memo[n][sum] = isSubsetSum(arr, n - 1, sum - arr[n-1]) || isSubsetSum(arr, n - 1, sum);
    return memo[n][sum] = isSubsetSum(arr, n - 1, sum);
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
