// C++ program to find out all combinations of
// positive numbers that add upto given number
#include <iostream>
using namespace std;
 
/*    arr - array to store the combination
    index - next location in array
    num - given number
    reducedNum - reduced number */
void findCombinationsUtil(int arr[], int index,
                       int num, int reducedNum)
{
    // Base condition
    if (reducedNum < 0)
        return;
 
    // If combination is found, print it
    if (reducedNum == 0)
    {
        cout<<" series: ";
        for (int i = 0; i < index; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
 
    // Find the previous number stored in arr[]
    // It helps in maintaining increasing order
    int prev = (index == 0)? 1 : arr[index-1];
 
    // note loop starts from previous number
    // i.e. at array location index - 1
    for (int k = prev; k <= num ; k++)
    {
        cout<<"prev: "<<prev<<" k: "<<k<<endl;
        // next element of array is k
        arr[index] = k;
 
        // call recursively with reduced number
        findCombinationsUtil(arr, index + 1, num,
                                 reducedNum - k);
        cout<<"prev: "<<prev<<" k: "<<k<<endl;

    }
}
 
/* Function to find out all combinations of
   positive numbers that add upto given number.
   It uses findCombinationsUtil() */
void findCombinations(int n)
{
    // array to store the combinations
    // It can contain max n elements
    int arr[n];
 
    //find all combinations
    findCombinationsUtil(arr, 0, n, n);
}
 
// Driver code
int main()
{
    int n = 5;
    findCombinations(n);
    return 0;
}