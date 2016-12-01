#include <iostream>
using namespace std;
int i,j,h,s,k=0;
int a[28];
int main()
{
	for(i=0;i<=27;i++)
		a[i]=0;
	for(i=0;i<=9;i++)
		for(j=0;j<=9;j++)
			for(h=0;h<=9;h++)
				{
					s=i+j+h;
					a[s]++;
			    }
	for(i=0;i<=27;i++)
		k=k+a[i]*a[i];
	cout<<k;
	return 0;
}