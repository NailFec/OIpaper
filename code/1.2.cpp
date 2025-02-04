#include <bits/stdc++.h>
using namespace std;
#define st(x) get<0>(x)
#define nd(x) get<1>(x)
#define rd(x) get<2>(x)
typedef tuple<int, int, int> tup;

constexpr int MAXn = 1e6 + 9;
int a[MAXn], c[MAXn], p[MAXn], ans[MAXn];
map<int, int> last;
vector<tup> dq;
int n, m;

bool cmp(const tup & x, const tup & y) {
    if (nd(x) == nd(y)) return st(x) < st(y);
    return nd(x) < nd(y);
}

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        p[i] = last[a[i]];
        last[a[i]] = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        dq.emplace_back(l, r, i);
    }
    sort(dq.begin(), dq.end(), cmp);
    int now = 1;
    for (const tup & tu : dq) {
        const int l = st(tu), r = nd(tu), k = rd(tu);
        for (; now <= r; ++now) {
            add(now, 1);
            if (p[now]) add(p[now], -1);
        }
        ans[k] = query(r) - query(l - 1);
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
