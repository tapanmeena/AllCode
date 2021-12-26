#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define inputArray(arr,n) for(int ia = 0; ia<n; ia++) cin>>arr[ia]
#define printArray(arr,n) for(int ia = 0; ia<n; ia++) cout<<arr[ia]<<" "

struct pair_hash{
	template <class T1,class T2> 
	size_t operator() (pair<T1,T2> const &pair) const{
	size_t h1 = hash<T1>()(pair.first);
	size_t h2 = hash<T2>()(pair.second);
	return h1 ^ h2;
	}
};

int main(){
	unordered_set <pair<int,int> , pair_hash> set;
	set.insert(make_pair(0,0));
	set.insert(make_pair(1,1));
	set.insert(make_pair(1,2));
	set.insert(make_pair(2,2));
	set.insert(make_pair(3,3));

	for(auto const &p:set)
		cout<<p.first<<" : "<<p.second<<endl;
}

// #include <bits/stdc++.h>
// #include <utility>
// #include <boost/functional/hash.hpp>
// using namespace std;
// typedef pair<string,int> Pair;

// int main(){
// 	unordered_set<Pair,boost::hash<Pair>> set = {{"two",2},{"tapan",1}};

// 	for(auto const &p:set)
// 		cout<<p.first<<" : "<<p.second<<endl;
// }