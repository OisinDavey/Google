//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

ll k;

void modulo(ll& x){
    if(x >= mod7){
        x %= mod7;
    }
}

ll binpow(ll base, ll expo){
    if(expo == 0ll){
        return 1ll;
    }else if(expo == 1ll){
        return base;
    }
    ll tmp = binpow(base, expo/2);
    tmp *= tmp;
    modulo(tmp);
    if(expo % 2 == 1){
        tmp *= base;
        modulo(tmp);
    }
    return tmp;
}

ll g(ll x){
    ll tmp = binpow(x, k+1);
    if(tmp == 0){
        tmp = mod7-1;
    }else{
        --tmp;
    }
    ll tmp2 = binpow(x-1ll, mod7-2);
    tmp *= tmp2;
    modulo(tmp);
    if(tmp == 0){
        tmp = mod7-1;
    }else{
        --tmp;
    }
    return tmp;
}

void solve(int t){
    ll n;
    cin >> n >> k;
    ll x, y, C, D, E1, E2, F;
    cin >> x >> y >> C >> D >> E1 >> E2 >> F;
    ll a[n];
    for(int i=0;i<n;++i){
        a[i] = (x + y)%F;
        ll _x = (C*x + D*y + E1)%F;
        ll _y = (D*x + C*y + E2)%F;
        x = _x;
        y = _y;
    }
    ll ans = 0ll;
    ll f[n+1];
    f[1] = k;
    for(int i=2;i<=n;++i){
        f[i] = f[i-1] + g(i);
        modulo(f[i]);
    }
    for(int i=0;i<n;++i){
        ll tmp = a[i]*(n-i);
        modulo(tmp);
        tmp *= f[i+1];
        modulo(tmp);
        ans += tmp;
        modulo(ans);
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        solve(t);
    }
}
