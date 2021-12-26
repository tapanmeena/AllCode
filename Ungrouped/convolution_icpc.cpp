#include<bits/stdc++.h>
using namespace std;
#define M 998244353
#define ll long long int

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int A[n],B[m];
		ll yb=0;
		ll ya=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			ya=ya+A[i];
		}
		for(int i=0;i<m;i++){
			cin>>B[i];
			yb=yb+B[i];
		}
		int Q;
		cin>>Q;
		while(ya<0)
		{
			ya += M;
			ya %= M;
		}

		while(yb<0)
		{
			yb += M;
			yb %= M;
		}
		ya %= M;
		yb %= M;

		ll sc=(ya*yb)%M;
						
		while(Q--)
		{
			int type;
			cin>>type;
			if(type==1)
			{
				ll l,r,x;
				cin>>l>>r>>x;
				// for (int i=l-1;i<r;i++){
				// 	A[i]=A[i]+x;
				// }
				// 
				ll change = x*(r-l+1);
				while(change<0)
				{
					change += M;
					change %= M;
				}
				change %= M;
				sc=sc+change*yb;
				ya=ya+change;
				while(ya<0)
				{
					ya += M;
					ya %= M;
				}
				ya %= M;
			}
			else if(type==2)
			{
				ll l,r,x;
				cin>>l>>r>>x;
				// for (int i=l-1;i<r;i++){
				// 	B[i]=B[i]+x;
				// }
				ll change = x*(r-l+1);
				while(change<0)
				{
					change += M;
					change %= M;
				}
				
				sc=sc+change*ya;
				yb=yb+change;
				while(yb<0)
				{
					yb += M;
					yb %= M;
				}
				yb %= M;
			}
			else
				cout<<sc%M<<endl;
		}
	}
	return 0;
}