#include <bits/stdc++.h>
using namespace std;

int parentArr[100001];
long long sizeArr[100001];

void initialise(int n)
{
	for(int i=1;i<=n;i++)
	{
		parentArr[i]=i, sizeArr[i]=1;
	}
}

int root(int i)
{
    while(parentArr[i] != i)
    {
    	i = parentArr[i];
    }
    return i;
}

void unionXY(int x, int y)
{
  // if(sizeArr[x] <= sizeArr[y])
	if(x <= y)
	{
		// sizeArr[y] += sizeArr[x];
		parentArr[x] = parentArr[y];
	}
	else
	{
		// sizeArr[x] += sizeArr[y];
		parentArr[y] = parentArr[x];
	}
}

void updateSizeArray(int n)
{
	for(int i=1; i<=n;i++)
	{
		int temp;
		temp = root(i);
		sizeArr[i] = sizeArr[temp];
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	int temp = M;
	initialise(N);
	while(temp--)
	{
		int u,v;
		cin>>u>>v;
		int x = root(u);
		int y = root(v);
		// cout<<"x "<<x<<" y "<<y<<endl;
		if(x == y)
			continue;
		unionXY(x, y);
	}
  // for(int i=1;i<=N;i++)
  //   cout<<parentArr[i]<<" ";
  cout<<endl;
  int q;
  cin>>q;
  while(q--)
  {
    int x,y;
    cin>>x>>y;
    if(root(x) == root(y))
    {
      cout<<"TLE"<<endl;
      continue;
    }
    else if(root(x) > root(y))
    {
      cout<<x<<endl;
    }
    else
      cout<<y<<endl;
  }
	// updateSizeArray(N);
  // long long mul = 1;
	// for(int i=1; i<=N; i++)
    // if(root(i) == i)
      // mul = (mul * sizeArr[i])%1000000007;
		// cout<<sizeArr[parentArr[i]]-1<<" ";
  // cout<<mul;
	// cout<<endl;
}