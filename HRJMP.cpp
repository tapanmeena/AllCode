#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node* left, *right;
    int data;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

struct llist{
	node* root;
	llist* next;
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
	node* tree[indexes.size()+1];
	for(int i=0;i<indexes.size();i++)
	{
		tree[i+1] = new node(indexes[]);
		tree[i+1]->right = indexes[i][1];
	}
	return indexes;
}

int main()
{
	int n;
	cin>>n;
    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

	// swapNodes
	vector<vector<int>> result = swapNodes(indexes, queries);
}