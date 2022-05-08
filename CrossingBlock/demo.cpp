#include <bits/stdc++.h>
#define ll long long 
#define int long long
using namespace std;

void minArrayJumpR(vector<ll> arr, ll n)
{
    ll mx = -1;
    ll ans = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] > mx)
        {
            ans++;
            mx = arr[i];
        }
    }

    if (arr[0] >= mx)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}

int32_t main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        minArrayJumpR(arr, n);
    }

    return 0;
}