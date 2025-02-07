#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6 + 9, MAXn = 1e6 + 9, MAXsn = 1e3 + 9;
int a[MAXn], c[MAXn], p[MAXn], ans[MAXn];
int last[MAX], bef[MAXn], nxt[MAXn];
int d[MAXsn][MAXsn];
int n, sn, dn;

pair<int, int> border(const int & di) {
    int p = (di - 1) * sn + 1;
    int q = min(di * sn, n);
    return {p, q};
}

int piece(const int & p, const int & q) {
    bitset<MAX> ved;
    int ans = 0;
    for (int i = p; i <= q; ++i) {
        ans += !ved[a[i]];
        ved[a[i]] = true;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    sn = sqrt(n);
    dn = (n - 1) / sn + 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        bef[i] = last[a[i]];
        if (bef[i]) nxt[bef[i]] = i;
        nxt[i] = n + 1;
        last[a[i]] = i;
    }

    for (int di = 1; di <= dn; ++di) {
        int p, q;
        tie(p, q) = border(di);
        d[di][di] = piece(p, q);
    }
    for (int dis = 2; dis <= sn; ++dis) {
        for (int di = 1; ; ++di) {
            int dj = di + dis - 1;
            if (dj > dn) break;
            d[di][dj] = d[di][dj - 1];
            // [di+0][di+1][di+2][di+3][dj-1][dj-0]
            // [         d[di][dj-1]        ]
            // ^bp                           ^p   ^q
            int bp = border(di).first, p, q;
            tie(p, q) = border(dj);
            for (int i = p; i <= q; ++i)
                d[di][dj] += bef[i] < bp;
                //^ Do not use `if (bef[i] < bp) ++d[di][dj];`,
                //^ or its running time will be doubled.
        }
    }

    int m;
    scanf("%d", &m);
    for (int _ = 1; _ <= m; ++_) {
        int p, q, ans = 0;
        scanf("%d %d", &p, &q);
        int l = p / sn + 1, r = q / sn + 1;
        if (r - l <= 1) {
            ans = piece(p, q);
        } else {
            ans = d[l + 1][r - 1];
            // {p+0}{p+1}[l+1][l+2][r-2][r-1]{q-1}{q-0}
            //           ^m                 ^n
            int m = border(l + 1).first, n = border(r - 1).second;
            for (int i = p; i < m; ++i)
                ans += nxt[i] > n;
            for (int i = q; i > n; --i)
                ans += bef[i] < p;
        }
        printf("%d\n", ans);
    }
    return 0;
}
