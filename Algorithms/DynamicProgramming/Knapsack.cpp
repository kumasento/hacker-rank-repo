
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    freopen("Knapsack.case", "r", stdin);
    
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, k; scanf("%d%d", &n, &k);
        int a[n+1]; 
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        
        int f[k+1];
        memset(f, 0, sizeof(f));
        // knapsack: f[i][j] = max{f[i-1][j], f[i-1][j-Vi]+W}
        for (int i = 1; i <= n; i++)
            for (int w = 1; a[i] * w <= k; w ++) 
                for (int j = k; j >= a[i] * w; j--)
                    f[j] = max(f[j], f[j-w*a[i]] + w*a[i]);

        cout << f[k] << endl;
    }

    return 0;
}
