#include <iostream>
using namespace std;
int main()
{
	bool a[100000];
	int n, k=2;

	cin>>n;
	for (int i=2; i<=n; i++)
		a[i]=true;

	while (k<=n/2)
	{
		for (int i=2; i<=n; i++)
		if ( i%k==0 && i!=k )
			a[i]=false;
	        k++;
	}

	for (int i=2; i<=n; i++)
		if (a[i]==true)
			cout<<i<<" ";

	return 0;
}