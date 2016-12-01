#include <iostream>
using namespace std;
int main()
{
	int n, k=0;
	int a[100000];

	cout<<"Type the number of elements:";
	cin>>n;

	cout<<"Type the elements:";
	for (int i=0; i<n; i++)
		{
			cin>>a[i];
			    if (a[i]==0)
				   k++;
	        }

	cout<<k;
	return 0;
}