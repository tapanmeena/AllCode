#include<bits/stdc++.h>
using namespace std;
#define printarr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];

        int rowCount = 0;
        for(int i=0;i<n;i++)
        {
            int checkArr[n+1];
            memset(checkArr,0,sizeof(checkArr));
            for(int j=0;j<n;j++)
                checkArr[mat[i][j]]++;
            for(int j=1;j<=n;j++)
            {
                if(checkArr[j]>1)
                {
                    rowCount++;
                    break;
                }                
            }
            // printarr(checkArr,n+1);
            // cout<<endl;
        }
        // cout<<rowCount<<endl;

        int colCount = 0;
        for(int i=0;i<n;i++)
        {
            int checkArr[n+1];
            memset(checkArr,0,sizeof(checkArr));
            for(int j=0;j<n;j++)
                checkArr[mat[j][i]]++;
            for(int j=1;j<=n;j++)
            {
                if(checkArr[j]>1)
                {
                    colCount++;
                    break;
                }                
            }
            // printarr(checkArr,n+1);
            // cout<<endl;
        }
        cout<<rowCount<<" "<<colCount<<endl;
    }
}