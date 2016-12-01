#include <iostream>
using namespace std;
int x,s;
int main()
{
	cin>>x;
	s=x;
	x=x*x;
	s=(s+x)*(x+1)+1;
	cout<<s;
	return 0;
}