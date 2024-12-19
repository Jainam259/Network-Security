// Modified Ceaser Cipher

#include<iostream>
#include<string>
// #include<limits>
using namespace std;

string encmodified(string t,int supper,int slower)
{
	string ct = "";
	for(int i=0; i<t.length(); i++)
	{
		char c = t[i];
		if(isupper(c))
			c = (c - 'A' + supper) % 26 + 'A';
		else if(islower(c))
			c = (c - 'a' + slower) % 26 + 'a';
		ct += c;
	}
	return ct;
}

string decmodified(string t,int supper,int slower)
{
	string pt = "";
	for(int i=0; i<t.length(); i++)
	{
		char c = t[i];
		if(isupper(c))
			c = (c - 'A' - supper + 26) % 26 + 'A';
		else if(islower(c))
			c = (c - 'a' - slower + 26) % 26 + 'a';
		pt += c;
	}
	return pt;
}

int main()
{
	string pt;
	int supper,slower;

	cout<<"Enter Plain Text:";
	getline(cin,pt);

	cout<<"Enter Shifting for Uppercase Letter:";
	cin>>supper;

	cout<<"Enter Shifting for Lowercase Letter:";
	cin>>slower;

	string dec = encmodified(pt,supper,slower);
	cout<<"Encrypted text:"<<dec<<endl;

	string enc = decmodified(dec,supper,slower);
	cout<<"Decrypted text:"<<enc<<endl;
}