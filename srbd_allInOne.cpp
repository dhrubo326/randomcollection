A:
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int b, y; cin >> b >> y;
    long long ans = 0;
    for (int m = 0; m <= 62; m++) {
      int p = m / 2, q = m - p;
      int cost = p * p + q * q + m * y;
      if (cost <= b) {
        ans = (1LL << m);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

B:
#include<bits/stdc++.h>
using namespace std;

string p[] = { "blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (auto x: s) {
      cnt[x - 'a']++;
    }
    int ans = 0;
    for (int mask = (1 << 15) - 1; mask > 0; mask--) {
      auto cur = cnt;
      bool ok = true;
      for (int i = 0; i < 15 and ok; i++) {
        if (mask >> i & 1) {
          for (auto x: p[i]) {
            if (cur[x - 'a'] >= 1) {
              cur[x - 'a']--;
            }
            else {
              ok = false;
              break;
            }
          }
        }
      }
      if (ok) {
        ans = max(ans, __builtin_popcount(mask));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

C:
#include<bits/stdc++.h>
using namespace std;

const int N = 5000 + 9, mod = 1e9 + 7;

int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
int dp[N];
int n, m;
int yo(int i) {
  if (i > n) return 1;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = yo(i + 1);
  for (auto x: primes) {
    if (x < m and i + x - 1 <= n) {
      ans += yo(i + x + 1);
      if (ans >= mod) ans -= mod;
    } else break;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << yo(1) << '\n';
  }
  return 0;
}

D:
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9, LG = 19;

vector<int> g[N];
int par[N][LG + 1], dep[N], d[N];;
string s;
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  d[u] = d[p] + (s[u - 1] == '1');
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int dist(int u, int v) {
  int l = lca(u, v);
  return d[u] + d[v] - (d[l] << 1) + 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; i++) {
      int k; cin >> k;
      g[k].push_back(i);
    }
    cin >> s;
    dfs(1);
    while (q--) {
      int u, v; cin >> u >> v;
      cout << dist(u, v) << '\n';
    }

    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
  }
  return 0;
}

E:
#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 9;

int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
int a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    set<int> se;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (spf[a[i]] == a[i]) {
        se.insert(i);
      }
    }
    while (q--) {
      int ty; cin >> ty;
      if (ty == 1) {
        int x; cin >> x;
        int ans = 0;
        auto it = se.upper_bound(x);
        if (it == se.end()) ans += n - x;
        else ans += (*it) - x - 1;
        it = se.lower_bound(x);
        if (it == se.begin()) ans += x - 1;
        else ans += x - (*(--it)) - 1;
        cout << ans << '\n';
      }
      else {
        int i, y; cin >> i >> y;
        if (spf[a[i]] == a[i]) {
          se.erase(i);
        }
        a[i] = y;
        if (spf[a[i]] == a[i]) {
          se.insert(i);
        }
      }
    }
  }
  return 0;
}

F:
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};
int id[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  memset(id, -1, sizeof id);
  for (int i = 0; i < n; i++) {
    id[a[i]] = i + 1;
  }
  DSU d(n);
  for (int i = 2; i < N; i++) {
    int last = -1;
    for (int j = i; j < N; j += i) {
      if (id[j] != -1) {
        if (last != -1) d.merge(last, id[j]);
        last = id[j];
      }
    }
  }
  cout << d.count() << '\n';
  return 0;
}