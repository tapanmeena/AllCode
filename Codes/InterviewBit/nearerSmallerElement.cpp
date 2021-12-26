#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A[] = {3, 6, 17, 15, 13, 15, 6, 12, 9, 1};
	int n = sizeof(A)/sizeof(A[0]);

	int n = A.size();
	vector<int> result(n);
	result[0] = -1;
	bool found = false;
	for(int i = 1; i<n;i++)
	{
		found = false;
		if(A[i] > A[i-1])
		{
			result[i] = A[i-1];
			found = true;
		}
		else
		{
			for(int j = i-1; j>=0; j--)
			{
				if(A[i] > A[j])
				{
					result[i] = A[j];
					found = true;
					break;
				}
			}
		}
		if(!found)
			result[i] = -1;
	}

	for(int i=0; i<n; i++)
		cout<<result[i]<<" ";
	cout<<endl;
}

/*
    int n=A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top()>=A[i]) 
            st.pop();
        if(!st.empty())
            ans[i]=st.top();
        st.push(A[i]);
    }
    return ans;
 */