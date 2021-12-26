#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string A)
{
	stack<char> charStack;
	string result;

	for(int i = 1; i<A.size(); i++)
	{
		if(A[i] == '/')
			continue;
		else if(A[i] == '.')
		{
			if(i+1 < A.size() && A[i+1] == '.')
			{
				if(!charStack.empty())
					charStack.pop();
			}
		}
		else
		{
			charStack.push(A[i]);
		}
	}
	while(!charStack.empty())
	{
		result += charStack.top();
		charStack.pop();
	}
	result += "/";
	string finalResult;
	for (int i = result.size()-1; i >= 0; --i)
	{
		finalResult += result[i];
		if(i!= 0)
			finalResult += "/";
	}
	return finalResult;
}

int main()
{
	/*
		/a/..
		/a/../
		/../../../../../a
		/a/./b/./c/./d/
		/a/../.././../../.
		/a//b//c//////d
	*/
	// string A = "/a/./b/../../c/..";
	while(true)
	{
		string A;
		cin>>A;
		cout<<simplifyPath(A)<<endl;		
	}
}


/*
stack<string> st;
    
    int len = A.length();
    
    for(int i=0;i<len;i++){
        if(A[i]=='/'){
            continue;
        }
        if(A[i]=='.'){
            if(i+1<len && A[i+1]=='.'){
                if(!st.empty())
                    st.pop();
                i++;
            }
        }
        else{
            string tem="";
            while(i<len && A[i]!='/'){
                tem = tem+A[i];
                i++;
            }
            st.push(tem);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }

    return (ans=="")?"/":ans;

  
*/
