#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arrival[n];
		int departure[n];
		for(int i = 0; i < n; i++)
			cin>>arrival[i];
		for(int i = 0; i < n; i++)
			cin>>departure[i];

		sort(arrival, arrival + n);
		sort(departure, departure + n);

		stack<int> timings;
		int j = 0,k = 0;
		int platform_needed = 0;
		for(int i = 0; i < 2*n; i++)
		{
			if(arrival[j] <= departure[k] && j < n && k < n)
			{
				timings.push(arrival[j]);
				if(timings.size() > platform_needed)
					platform_needed = timings.size();
				j++;
			}
			else if(departure[k] < arrival[j])
			{
				timings.pop();
				k++;
			}
		}
		cout<<platform_needed<<endl;
	}
}