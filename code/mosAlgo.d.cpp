#include <bits/stdc++.h>
using namespace std;
#define st(x) get<0>(x)
#define nd(x) get<1>(x)
#define rd(x) get<2>(x)
typedef tuple<int, int, int> tup;

constexpr int MAX = 1e6 + 9, MAXn = 1e6 + 9;
int a[MAXn], ans[MAXn];
int last[MAX], bef[MAXn], nxt[MAXn];
int cnt[MAX], sum = 0;
vector<tup> dq;
int n, m, unit;

bool cmp(const tup & x, const tup & y) {
    int bx = st(x) / unit, by = st(y) / unit;
    if (bx != by) return bx < by;
    if (bx & 1) return nd(x) < nd(y);
    return nd(x) > nd(y);
}

int main() {
    scanf("%d", &n);
    unit = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        bef[i] = last[a[i]];
        if (bef[i]) nxt[bef[i]] = i;
        nxt[i] = n + 1;
        last[a[i]] = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        dq.emplace_back(l, r, i);
    }
    sort(dq.begin(), dq.end(), cmp);
    int p = 1, q = 0, sum = 0;
    for (const tup& tu : dq) {
        const int l = st(tu), r = nd(tu), k = rd(tu);
        while (p < l) sum -= (q < nxt[p++]);
        while (p > l) sum += (q < nxt[--p]);
        while (q < r) sum += (p > bef[++q]);
        while (q > r) sum -= (p > bef[q--]);
        ans[k] = sum;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
