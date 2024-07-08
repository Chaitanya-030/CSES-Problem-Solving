#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++) {
        if(arr[i] > ans.back()) ans.push_back(arr[i]);
        else {
            int ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[ind] = arr[i];
        }
    }
    cout<<ans.size()<<endl;
    
    return 0;
}