#include <bits/stdc++.h>
using namespace std;

bool loopDetection(string check, unordered_map<string, string> arrlinks)
{
	unordered_map<string, int> umap;
	for(auto x 	: arrlinks)
		umap[x.first] = 0;

	bool found = false;
	umap[check] = 1;
	check = arrlinks[check];
	while(true)
	{
		if(check == "--")
			return true;
		if(check[0] == 'P')
			return false;
		if(umap[check]>0)
			return true;
		umap[check]++;
		check = arrlinks[check];
	}
}

string findPage(string s, unordered_map<string, string> umap)
{
	while(true)
	{
		string temp = umap[s];
		// cout<<temp<<endl;
		if(temp[0] == 'P')
			return temp;
		else if(temp[0] == 'S')
			s = temp;
		else if(temp[0] == '-')
			return "--";
	}
}

int main()
{
	int nPages, nShorts;
	cin>>nPages>>nShorts;
	// cout<<nPages<<nShorts;
	string arrPages[nPages];
	// string arrLinks[nShorts];

	string faltu;
	getline(cin,faltu);

	for(int i=0;i<nPages;i++)
		getline(cin, arrPages[i]);

	unordered_map<string,string> arrlinks;
	for(int i=0;i<nShorts;i++)
	{
		string temp;
		getline(cin,temp);
		string p = string(1,temp[0]);
		p += temp[1];
		string q = string(1,temp[3]);
		q += temp[4];
		arrlinks[p] = q;
	}

	map<string,string> umap;
	//doing shorts
	for (auto x : arrlinks)
	{
		string first = x.first;
		string second = x.second;
		if(second[1] == 'P')
		{
			umap[first] = second;
			cout<<first<<" "<<second<<endl;
		}
		bool found = loopDetection(first, arrlinks);
		if(found)
			arrlinks[first] = "--";
		// cout<<"loop checking "<<first<<" "<<found<<endl;
	}
	cout<<"Completed Loop Detection"<<endl;
	unordered_map<string, int> pages;
	for(int i=0;i<nPages;i++)
	{
		string temp = arrPages[i];
		string p = string(1,temp[0]);
		p += temp[1];
		pages[p] = 0;
	}

	for(int i=0;i<nPages;i++)
	{
		string temp = arrPages[i];
		int n = temp.size();
		string ss = string(1,temp[0]);
		ss += temp[1];
		cout<<"current "<<temp<<" size "<<n<<endl;
		for(int i=6;i<n;i++)
		{
			if(temp[i] == 'P')
			{
				string p = "P";
				p += temp[i+1];
				if(ss == p)
					continue;
				pages[p]++;
			}
			else if(temp[i] == 'S')
			{
				string s = "S";
				s += temp[i+1];
				string result = findPage(s, arrlinks);
				cout<<"result "<<result<<endl;
				if(result == ss)
					continue;
				if(result == "--")
					continue;
				else
					pages[result]++;
			}
		}
	}
	for( auto x : pages)
		cout<<x.first<<"  "<<x.second<<endl;
}