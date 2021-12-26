#include <bits/stdc++.h>
using namespace std;

int computeGCD(int m)
{
	int returnValue = 0;
	for(int i=1; i <= m; i++)
		returnValue +=  __gcd(i, m);
	return returnValue;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++)
		cin>>arr[i];
	
	int q;
	cin>>q;
	map<int, int> map1;
	const unsigned int M = 1000000007;
	while(q--)
	{
		char c;
		cin>>c;
		if(c == 'C') //compute
		{
			int start, end;
			cin>>start;
			cin>>end;
			long long value = 0;
			for(int i = start-1; i<end; i++)
			{
				if(map1[arr[i]] != 0)
					value += map1[arr[i]];
				else
				{
					int temp = computeGCD(arr[i]);
					value += temp;
					// cout<<"in else"<<endl;
					map1[arr[i]] = temp;
				}
				// cout<<value<<endl;
			}
			cout<<value%M<<endl;
		}
		else //update
		{
			int x,y;
			cin>>x>>y;
			x--;
			arr[x] = y;
		}
	}
}


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;
const int MAX = 500005;
const int MAX1 = 1000005;
const long long MOD = 1e9 + 7;
long long toti[MAX], totiS[MAX], A[MAX1], tree[MAX1];
void update(int idx, long long val, int n)
{
    val %= MOD;
    while(idx <= n)
    {
        tree[idx] = (tree[idx] + val) % MOD;
        idx += (idx & -idx);
    }
}
long long read(int idx)
{
    long long sum = 0;
    while(idx > 0)
    {
        sum = (sum + tree[idx]) % MOD;
        idx -= (idx & -idx);
    }
    return sum;
}
void compute()
{
    int i, j, k, ans;
    for(i = 0;i < MAX;++i)
        toti[i] = i;
    for(i = 2;i < MAX;++i)
    {
        if(toti[i] == i)
        {
            toti[i] = i - 1;
            for(j = 2*i;j < MAX;j += i)
                toti[j] -= (toti[j] / i);
        }
    }
    for(i = 1;i < MAX;++i)
    {
        for(j = i, k = 1;j < MAX;j += i, k++)
        {
            totiS[j] += i*toti[k];
        }
    }
}
int main()
{
    int n, q, x, y;
    char c;
    long long ans = 0;
    compute();
    cin >> n;
    assert(n >= 1 and n <= 1000000);
    for(int i = 1;i <= n;++i)
    {
        cin >> A[i];
        assert(A[i] >= 1 and A[i] <= 500000);
        update(i, totiS[A[i]], n);
    }
    cin >> q;
    assert(q >= 1 and q <= 100000);
    while(q--)
    {
        cin >> c >> x >> y;
        assert(x >= 1 and x <= n);
        if(c == 'C')
        {
            assert(y >= 1 and y <= n);
            ans = (read(y) - read(x-1)) % MOD;
            if(ans < 0)
                ans += MOD;
            assert(ans >= 0 and ans < MOD);
            printf("%lld\n", ans);
        }
        else
        {
            assert(y >= 1 and y <= 500000);
            update(x, -totiS[A[x]], n);
            update(x, totiS[y], n);
            A[x] = y;
        }
    }
    return 0;
}
