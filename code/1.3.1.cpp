#include <bits/stdc++.h>
#define st(x) get<0>(x)
#define nd(x) get<1>(x)
#define rd(x) get<2>(x)
using namespace std;
typedef tuple<int, int, int> tup;
const int MAXn = 1e6 + 9;
int a[MAXn], c[MAXn], p[MAXn], ans[MAXn];
map<int, int> mp;
vector<tup> dq;
int n, m;

bool cmp(const tup & x, const tup & y) {
    if (nd(x) == nd(y)) return st(x) < st(y);
    return nd(x) < nd(y);
}

int lowbit(int x) {
    return x & (-x);
}

void fadd(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int fquery(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        p[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) {
        int l, r;
        scanf("%d%d", &l, &r);
        dq.push_back(tup{l, r, i});
    }
    sort(dq.begin(), dq.end(), cmp);
    int now = 1;
    for (tup tu : dq) {
        int l = st(tu), r = nd(tu), k = rd(tu);
        for (; now <= r; now ++) {
            fadd(now, 1);
            if (p[now]) fadd(p[now], -1);
        }
        ans[k] = fquery(r) - fquery(l - 1);
    }
    for (int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}