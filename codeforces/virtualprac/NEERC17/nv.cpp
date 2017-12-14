#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5 + 7;
const int SS = 4 * N;
int t[N], x[N], y[N];
set<pair<int, int> > st[SS];
int X[N], cnt;

void add(int l, int r, pair<int, int> val, int k, int s = 0, int e = cnt + 1, int v = 1)
{
    if (l >= e || r <= s)
        return;
    if (l <= s && e <= r)
    {
        if (k)
            st[v].insert(val);
        else
            st[v].erase(val);
        return;
    }
    int mid = (s + e) / 2;
    add(l, r, val, k, s, mid, 2 * v);
    add(l, r, val, k, mid, e, 2 * v + 1);
}

bool is_on(int X, int Y, int ind)
{
    return 1LL * (X - x[ind]) * (X - x[ind]) + 1LL * (Y - y[ind]) * (Y - y[ind]) < 1LL * y[ind] * y[ind];
}

int get(int ind, int x, int y, int s = 0, int e = cnt + 1, int v = 1)
{
    if (ind < s || ind >= e)
        return -2;
    auto it = st[v].lower_bound({y, 0});
    if (it != st[v].end())
    {
        if (is_on(x, y, it->second))
            return it->second;
    }
    if (it != st[v].begin())
    {
        it--;
        if (is_on(x, y, it->second))
            return it->second;
    }
    if (e - s < 2)
        return -2;
    int mid = (s + e) / 2;
    int res = -2;
    res = max(res, get(ind, x, y, s, mid, 2 * v));
    res = max(res, get(ind, x, y, mid, e, 2 * v + 1));
    return res;
}

int main()
{
    int q;
    cin >> q;
    for (int i=0; i<q; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        if (t[i] == 1)
        {
            X[cnt++] = x[i] - y[i]+1;
            X[cnt++] = x[i] + y[i];
        }
    }
    sort(X, X + cnt);
    cnt = unique(X, X + cnt) - X;
    for (int i=0; i<q; i++)
    {
        if (t[i] == 1)
        {
            int l = lower_bound(X, X + cnt, x[i] - y[i] + 1) - X + 1;
            int r = lower_bound(X, X + cnt, x[i] + y[i]) - X + 1;
            add(l, r, {y[i], i}, 1);
        }
        else
        {
            int ind = upper_bound(X, X + cnt, x[i]) - X;
            int id = get(ind, x[i], y[i]);
            cout << id+1 << "\n";
            if (id != -1)
            {
                int l = lower_bound(X, X + cnt, x[id] - y[id] + 1) - X + 1;
                int r = lower_bound(X, X + cnt, x[id] + y[id]) - X + 1;
                add(l, r, {y[id], id}, 0);
            }
        }
    }


}
