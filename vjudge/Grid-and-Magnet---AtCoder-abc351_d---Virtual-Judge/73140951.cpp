// Problem: problem
// Platform: vjudge
// Contest: Grid and Magnet - AtCoder abc351_d - Virtual Judge
// Language: C++23 (GCC 15.2.0)
// Verdict: Accepted
// URL: https://vjudge.net/problem/AtCoder-abc351_d
// Solved on: 2026-10-06T20:39:41.437Z

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
using namespace std;
using ll = long long;
using ld = double;
using vi = deque<int>;
const int N=2e5+5, M=1e3+5, MOD=1e9+7,OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
template<class T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx4[] = {1, 0, 0, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}, dy4[] = {0, 1, -1, 0};
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order()returns an iterator to the k-th largest element (counting from zero),
//order_of_key()the number of items in a set that are strictly smaller than our item.
//Erase on multi  ordered set : s.erase(--s.lower_bound(value))

// Before submit check:
// Corner cases
// Conditions

vector<vector<int>>type,vis;
int n ,m,res=1,ti=0;
int dfs(int i,int j) {

    if (i<0 or j<0 or i ==n or j==m)
        return 0;

    if (vis[i][j]==ti)
        return 0;
    vis[i][j]=ti;

    if (type[i][j]<2)
        return type[i][j];


   return 1+ dfs(i+1,j) +dfs(i,j+1) + dfs(i-1,j) +dfs(i,j-1);

}

void solve() {
    cin>>n>>m;
    char in;
     type.resize(n,vector<int>(m,2));
    vis.resize(n,vector<int>(m,0));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>in;
            if (in=='#') {
                type[i][j]=0;
                for (int k = 0; k < 4; ++k) {
                    int x=dx4[k]+i,y=j+dy4[k];
                    if (x>-1 and x<n and y>-1 and y<m )
                        type[x][y]=min(type[x][y],1ll);
                }

            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]==0 and type[i][j]==2) {
                ti++;
                res=max(res,dfs(i,j));
            }
        }
    }

    cout<<res;
}


int32_t main() {
TryingToDoBetter
    int t = 1;
//  cin >> t;

    while (t--) {
        solve();
    cout << "\n";
    }

        return 0;
}