#include <bits/stdc++.h>
#define ll long long
ll md = 1000000007;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0);                       
    cout.tie(0);
    ll t, n, q, x;
    cin >> t;
    while (t--){
        cin >> n >> q;
        vector<ll> v1, v2;
        for (ll i = 0; i < n; i++) cin >> x, v1.push_back(x);
        for (ll i = 0; i < n; i++) cin >> x, v2.push_back(x);
        vector<ll> pre, suf;
        ll s = 0;
        for (ll i = 0; i < n; i++){
            s += v1[i];
            pre.push_back(s);
        }
        s = 0;
        for (ll i = n - 1; i >= 0; i--){
            s += v1[i];
            suf.push_back(s);
        }
        vector<ll> pmn, smn;
        ll mn = pre[0];
        pmn.push_back(mn);
        for (ll i = 1; i < n; i++){
            mn = min(mn, pre[i]);
            pmn.push_back(mn);
        }
        mn = v1[n - 1];
        s = v1[n - 1];
        smn.push_back(mn);
        for (ll i = n - 2; i >= 0; i--){
            s += v1[i];
            mn = min(mn, s);
            smn.push_back(mn);
        }
        reverse(smn.begin(), smn.end());
        reverse(suf.begin(), suf.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++){
            ll cnt = v1[i] + max(0ll, v2[i]) * q;
            if (i){
                cnt += (pre[i - 1] - min(pmn[i - 1], 0ll));
            }
            if (i != n - 1){
                cnt += (suf[i + 1] - min(smn[i + 1], 0ll));
            }
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
}
