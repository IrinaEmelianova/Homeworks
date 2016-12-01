#include <iostream>
using namespace std;
int m,n,i;
int x[100000];
void f(int a,int b)
{
	while(a<b)
	{
		swap (x[a],x[b]);
		a++;
		b--;
	}
}
int main()
{
	cin>>m>>n;
	for(i=1;i<=m+n;i++)
		cin>>x[i];
	f(1,m);
	f(m+1,n+m);
	f(1,m+n);
	for(i=1;i<=m+n;i++)
		cout<<x[i]<<" ";
	return 0;
}