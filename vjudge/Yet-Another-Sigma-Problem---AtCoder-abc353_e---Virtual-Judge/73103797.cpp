// Problem: problem
// Platform: vjudge
// Contest: Yet Another Sigma Problem - AtCoder abc353_e - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc353_e
// Solved on: 2026-10-06T20:31:25.713Z

    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define f first
    #define s second
    #define int ll
    //#define double long double
    #define TryingToDoBetter   ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define IN  freopen("prime_subtractorization_input.txt", "r", stdin);
    #define OUT freopen("output.txt", "w", stdout) ;
    class PresentationFile;
    class Spreadsheet;
    class TextFile;
    class IDocument;
    using namespace std;
    using ll = long long;
    using ld = double;
    using vi = deque<int>;
    template<class T>
    using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0, 0, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1, 0};
   using namespace __gnu_pbds;
   template<class T> using ordered_set =tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
    //find_by_order()returns an iterator to the k-th largest element (counting from zero),
    //order_of_key()the number of items in a set that are strictly smaller than our item.
    //Erase on multi  ordered set : s.erase(--s.lower_bound(value))

    // Before submit check:
    // Corner cases
    // Conditions
const int N=1e5+5, M=1e3+5, MOD=1e9+7,OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;

ll egcd(ll a, ll b, ll &x, ll &y){ /// ax + by = gcd(a,b)
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll g=egcd(b,a%b,y,x);
    y-=(a/b)*x;
    return g;
}

ll modInverse(ll a, ll m){ /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x,y,g;
    g=egcd(a,m,x,y);
    if(g>1)
        return -1;
    return (x+m)%m;
}

ll fixMod(ll a, ll m){
    return (a + m)%m;
}

ll pushBack(ll h, ll x, ll p, char ch){
    return (((h*x)%p)+ch)%p;
}

ll pushFront(ll h, ll xp, ll p, char ch){ // xp=XP[len]
    return (h+(xp*ch)%p)%p;
}

ll popBack(ll h, ll x, ll p, char ch){
    return (fixMod(h-ch,p)*modInverse(x,p))%p;
}

ll popFront(ll h, ll xp, ll p, char ch){ // xp=XP[len-1]
    return fixMod(h-((xp*ch)%p),p);
}

int to(int h1 , int h2 , int p2){
    return h1*p2+h2;
}
int x=128, p1=1e9+7, p2=1e9+9;

 void solve()
 {
    int n,res=0;cin>>n;
     vector<string> vs(n);
     map<pair<int,int>,int>have;
    for (int i = 0; i < n; ++i) {
        cin>>vs[i];
    }
    for (int i = 0; i < n; ++i) {

        int last=0;

        pair<ll,ll> total = {0, 0};

        for (char ch : vs[i]) {
            total.first = pushBack(total.first, x, p1, ch);
            total.second = pushBack(total.second, x, p2, ch);
        }
        while (!vs[i].empty()) {
        int &now=have[total];
        res+=(now-last)*vs[i].size();
        last=now;
        now++;
        total.first = popBack(total.first, x, p1, vs[i].back());
        total.second = popBack(total.second, x, p2, vs[i].back());
        vs[i].pop_back();
        }
    }
     cout<<res;

 }

    int32_t main() {
   TryingToDoBetter
        int t = 1;
   //  cin >> t;

    vector<ll>XP1(1e5+1),XP2(1e5+1);
    XP1[0]=XP2[0]=1;
    for(int i=1; i<=100000; i++){
        XP1[i]=(XP1[i-1]*x)%p1;
        XP2[i]=(XP2[i-1]*x)%p2;
    }
        while (t--) {
            solve();
        cout << "\n";
        }

        return 0;
    }