
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("TheMaximumSubarray.case", "r", stdin);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N; cin >> N;
        int a[N]; 
        for (int i = 0; i < N; i++)  scanf("%d", &a[i]);

        int d[N]; // for continuous
        d[0] = a[0];
        for (int i = 1; i < N; i++)
            d[i] = max(d[i-1], 0) + a[i];
        int max_cont = d[0];
        for (int i = 1; i < N; i++) 
            max_cont = max(max_cont, d[i]);

        int max_non_cont = 0;
        for (int i = 0; i < N; i++)
            if (a[i] > 0)
                max_non_cont += a[i];
        if (max_non_cont == 0)
        {
            max_non_cont = a[0];
            for (int i = 1; i < N; i++)
                max_non_cont = max(a[i], max_non_cont);
        }

        cout << max_cont << ' ' << max_non_cont << endl;
    }

    return 0;
}
