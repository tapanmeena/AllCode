#include <bits/stdc++.h>
using namespace std;
int min(int a, int b); 
  
int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j; 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 
  
int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 

vector<pair<int,int>> checkSteps(vector<pair<int,int>> arr,vector<pair<int,int>> visited,vector<pair<int,int>> restricted)
{
	if(visited.size() == 0)
		return arr;
	vector<pair<int,int>> result;
	vector<pair<int,int>> result1;
	set_difference(arr.begin(), arr.end(), visited.begin(), visited.end(),
        inserter(result, result.begin()));
	if(restricted.size() == 0)
		return result;
	set_difference(result.begin(), result.end(), restricted.begin(), restricted.end(),
	        inserter(result1, result1.begin()));

	return result1;
}


int main()
{
	int t = 1;
	// cin>>t;
	int casen = 1;
	while(t--)
	{
		int n = 501;
		// cin>>n;
		vector<pair<int,int>> arr;
		vector<pair<int,int>> visited;
		vector<pair<int,int>> restricted;
		pair<int,int> prev;
		pair<int,int> curr;
		curr.first = 1;
		curr.second = 1;
		pair<int,int> possibleChoice;
		possibleChoice = curr;
		n--;

		if(n==0)
			visited.push_back({1,1});
		else
		{
			visited.push_back({1,1});
			while(n>0)
			{
				arr.clear();
				cout<<"value of n "<<n<<endl;
				int ri = visited[visited.size()-1].first;
				int ki = visited[visited.size()-1].second;
				pair<int,int> temp;
				if(ri-1>=1 && ki-1>=1)
				{
					temp.first = ri-1;
					temp.second = ki-1;
					arr.push_back(temp);
				}
				if(ri-1>=1 && ki>=1)
				{
					temp.first = ri-1;
					temp.second = ki;
					arr.push_back(temp);
				}
				if(ri>=1 && ki-1>=1)
				{
					temp.first = ri;
					temp.second = ki-1;
					arr.push_back(temp);
				}
				if(ri>=1 && ki+1<=ri)
				{
					temp.first = ri;
					temp.second = ki+1;
					arr.push_back(temp);
				}
				if(ri+1>=1 && ki>=1)
				{
					temp.first = ri+1;
					temp.second = ki;
					arr.push_back(temp);
				}
				if(ri+1>=1 && ki+1<=ri+1)
				{
					temp.first = ri+1;
					temp.second = ki+1;
					arr.push_back(temp);
				}
				// visited.push_back({1,1});

				cout<<"before"<<endl;
				for(int i=0;i<arr.size();i++)
					cout<<arr[i].first<<" "<<arr[i].second<<endl;

				arr = checkSteps(arr, visited, restricted);
				cout<<"after"<<endl;
				for(int i=0;i<arr.size();i++)
					cout<<arr[i].first<<" "<<arr[i].second<<endl;
				cout<<"--"<<endl;
				int min = INT_MAX;
				int minVal = 0;
				for(int i=0;i<arr.size();i++)
				{
					int val = binomialCoeff(arr[i].first-1,arr[i].second-1);
					cout<<"val vae "<<val<<endl;
					int tempV = n - val;
					cout<<"val te "<<tempV<<endl;
					if(tempV>=0 && tempV<min)
					{
						minVal = val;
						min = tempV;
						possibleChoice = arr[i];
					}
				}
				if(min == INT_MAX)
				{
					restricted.push_back(possibleChoice);
					if(visited.size()!=0)
						visited.pop_back();
					n+=binomialCoeff(possibleChoice.first-1, possibleChoice.second-1);
					continue;
				}
				visited.push_back(possibleChoice);
				cout<<"value of min "<<min<<endl; 
				cout<<"value of minv "<<minVal<<endl; 
				cout<<"possible choise "<<possibleChoice.first<<"  "<<possibleChoice.second<<endl; 
				n -= minVal;
				for(int i=0;i<visited.size();i++)
					cout<<visited[i].first<<" "<<visited[i].second<<endl;

			}

		}
		// cout<<possibleChoice.first<<"  "<<possibleChoice.second<<endl;
		// if(n==1)

		cout<<"Case #"<<casen<<": "<<endl;
		casen++;
		for(int i=0;i<visited.size();i++)
			cout<<visited[i].first<<" "<<visited[i].second<<endl;
	}
}
/*
	possible moves
	(ri - 1, ki - 1), (ri - 1, ki), 
	(ri, ki - 1), (ri, ki + 1), 
	(ri + 1, ki), (ri + 1, ki + 1). 
 */