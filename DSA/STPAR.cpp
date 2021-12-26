#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int order[n];
	for(int i=0;i<n;i++)
		cin>>order[i];
stack<int> lane; int need = 1;
bool state = true;
for (int i = 0; i < n; i++) {
	while (!lane.empty() && lane.top() == need) {
		need++;
		lane.pop();
	}
	if (order[i] == need) {
		need++;
	} else if (!lane.empty() && lane.top() < order[i]) {
		cout<<order[i]<<" "<<lane.top()<<endl;
		state = false;
		break;
	} else {
		lane.push(order[i]);
	}
}
if (state) cout << "yes" << "\n";
else cout << "no" << "\n";
}