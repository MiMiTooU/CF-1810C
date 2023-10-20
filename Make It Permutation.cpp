#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    if (t >= 1 && t <= 1e4)
    {
        while (t--)
        {
            __int64 n, c, d, a, add = 0, del = 0, cost = 0, rep = 0;
            cin >> n >> c >> d;
            if (n >= 1 && c >= 1 && d >= 1 && n <= 1e5
                && n <= 1e5 && c <= 1e9 && d <= 1e9)
            {
                vector<__int64>a(n, 0);
                for (int i = 0; i < n; i++)
                {
                    cin >> a[i];
                }
                sort(a.begin(), a.end());
                auto it_a1 = a.end();
                for (int i = 0; i < n - 1; i++)
                {
                    if (a[i] == a[i + 1])
                    {
                        it_a1--;
                        rep++;
                    }
                }
                unique(a.begin(), a.end());
                a.erase(it_a1, a.end());
                it_a1 = a.begin();
                if (*it_a1 == 1)
                {
                    del = int(a.end() - it_a1) - 1 + rep;
                    cost = del * c;
                }
                else
                {
                    del = int(a.end() - it_a1) + rep;
                    add = 1;
                    cost = (del * c) + (add * d);
                }
                for (; it_a1 != a.end(); it_a1++)
                {
                    del = int(a.end() - it_a1) - 1 + rep;
                    add = *it_a1 - int(it_a1 - a.begin()) - 1;
                    if (cost > (del * c) + (add * d))
                    {
                        cost = (del * c) + (add * d);
                    }
                }
                cout << cost << endl;
            }
        }
    }
    return 0;
}