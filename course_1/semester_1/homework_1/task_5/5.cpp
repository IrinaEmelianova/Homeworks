#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int k=0;

	cout<<"Type the string:";
	getline (cin, s);
		
	for (int i=0; i<s.length(); i++)
		{
			if ( s[i]=='(' )
			    k++;
	                if ( s[i]==')' )
			    k--;
		        if ( k<0 )
			    break;
	        }

	if ( k==0 )
		cout<<"balance is ok";
	else
		cout<<"balance is wrong";

	return 0;
}