#include<bits/stdc++.h>
using namespace std;
// printAct()
struct Activity
{
	int start, end, actNumber;
	char p;
};

bool activityCompare(Activity a1, Activity a2)
{
	return (a1.start < a2.start);
}

bool resultCompare(Activity a1, Activity a2)
{
	return (a1.actNumber< a2.actNumber);
}
struct person
{
	int c=0,j=0;
};

int main()
{
	int t;
	cin>>t;
	int caseN = 1;
	while(t--)
	{
		string result = "";
		int n;
		cin>>n;
		Activity schedule[n];
		for(int i=0;i<n;i++)
		{
			cin>>schedule[i].start;
			cin>>schedule[i].end;
			schedule[i].actNumber = i;
		}
		sort(schedule,schedule + n, activityCompare);
/*		for(int i=0;i<n;i++)
		{
			cout<<schedule[i].start<<" "<<schedule[i].end<<" "<<schedule[i].actNumber<<endl;
		}*/
		person p;
		for(int i=0;i<n;i++)
		{
			if(schedule[i].start>=p.c)
			{
				p.c = schedule[i].end;
				schedule[i].p = 'C';
				// result += "C";
			}
			else if(schedule[i].start>=p.j)
			{
				p.j = schedule[i].end;
				schedule[i].p = 'J';
				// result += "J";
			}
			else
			{
				result = "IMPOSSIBLE";
				break;
			}
			// cout<<p.c<<" "<<p.j<<endl;
		}
		sort(schedule, schedule+n, resultCompare);
		if(result != "IMPOSSIBLE")
			for(int i=0;i<n;i++)
				result += schedule[i].p;
/*		{
			result += schedule[i].p;
			cout<<schedule[i].actNumber<<" ";
			cout<<schedule[i].start<<" ";
			cout<<schedule[i].end<<" ";
			cout<<schedule[i].p<<endl;
		}*/
		cout<<"Case #"<<caseN<<": "<<result<<endl;
		caseN++;
	}
}