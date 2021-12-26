#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int parent[N], rnk[N];
multiset <int> vals[N];
int u[N], v[N], val[N];
int ans[N];
int remve[N];
void make(int v){
	parent[v] = v;
	rnk[v] = 0;
	vals[v].insert(val[v]);
}

int find(int v){
	if(parent[v] != v)
		parent[v] = find(parent[v]);
	return parent[v];
}

void merge(int a, int b){
	for(auto it : vals[b]){
		vals[a].insert(it);
	}
	vals[b].clear();
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(rnk[a] < rnk[b])
			swap(a, b);
		parent[b] = a;
		merge(a,b);
		if(rnk[a] == rnk[b])
			rnk[a]++;
	}
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
		cin >> u[i] >> v[i];

	for(int i = 1; i <= n; ++i)
		cin >> val[i];

	set <int> chk;
	for(int i = 1; i < n; ++i){
		cin >>remve[i];
		chk.insert(remve[i]);
	}

	for(int i = 0; i <= n; ++i){
		make(i);
	}

	int x;
	int mx = 0; 
	for(int i = n-1; i >= 1; --i){
		ans[i] = mx;
		x = remve[i];
		Union(u[x], v[x]);
		int tmp = find(u[x]);
		mx = max(mx, *(--vals[tmp].end()) - (*vals[tmp].begin()));	
	}
	for(int i = 1; i < n; ++i){
		cout << ans[i] << endl;
	}
}
