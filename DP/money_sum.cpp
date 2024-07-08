#include <bits/stdc++.h>
using namespace std;

void solve(int n, int arr[]) {
    // The maximum possible sum is the sum of all elements
    int max_sum = accumulate(arr, arr + n, 0);
    
    // Initialize a boolean array to track possible sums
    vector<bool> dp(max_sum + 1, false);
    dp[0] = true; // Sum of 0 is always possible (by choosing no elements)
    
    // Iterate over each element in the array
    for(int i = 0; i < n; i++) {
        for(int j = max_sum; j >= arr[i]; j--) {
            if(dp[j - arr[i]]) {
                dp[j] = true;
            }
        }
    }
    
    // Collect all possible sums
    set<int> st;
    for(int i = 1; i <= max_sum; i++) {
        if(dp[i]) {
            st.insert(i);
        }
    }
    
    // Output the results
    cout << st.size() << endl;
    for(auto it : st) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    solve(n, arr);
    
    return 0;
}