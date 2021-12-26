int merge(int arr[], int l, int m, int r)
{
    int tempArr[r - l + 1];
    int n = r - l + 1;
    int a = l, b = m + 1; 
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(a <= m && b <= r)
        {
            if(arr[a] <= arr[b])
            {
                tempArr[i] = arr[a];
                a++;
            }
            else
            {
                tempArr[i] = arr[b];
                count += (m - a + 1);
                b++;
            }
        }
        else if(a > m)
        {
            tempArr[i] = arr[b];
            b++;
        }
        else if(b > r)
        {
            tempArr[i] = arr[a];
            a++;
        }
    }
    for(int i = l, z = 0; i <= r; i++,z++)
        arr[i] = tempArr[z];
    return count;
}

int mergeSort(int arr[], int l, int r)
{
    int count = 0;
    if(l < r)
    {
        int m = l + (r - l)/2;
        count += mergeSort(arr, l , m);
        count += mergeSort(arr, m + 1, r);
        count += merge(arr, l ,m ,r);
    }
    return count;
}


int Solution::countInversions(vector<int> &A) {
    int n = A.size();
    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = A[i];
    int count = mergeSort(arr, 0, n-1);
    return count;
}
