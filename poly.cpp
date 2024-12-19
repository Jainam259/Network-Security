// Polyalphabetic ceaser cipher

#include<iostream>
#include<string>
using namespace std;

string generatekey(string pt,string key)
{
	int x = pt.size();
	for(int i=0;;i++)
	{
		if(x == i)
			i = 0;
		if(key.size() == pt.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

string polyenc(string pt,string key)
{
	string ct = "";
	for(int i=0; i<pt.size(); i++)
	{
		char x = (pt[i] + key[i]) % 26;
		x += 'A';
		ct.push_back(x);
	}
	return ct;
}

string polydec(string ct,string key)
{
	string pt = "";
	for(int i=0; i<ct.size(); i++)
	{
		char x = (ct[i] - key[i] + 26) % 26;
		x += 'A';
		pt.push_back(x); 
	}
	return pt;
}

int main()
{
	string key,txt;

	cout<<"Enter Text(Upper Case Letter Only):";
	getline(cin,txt);

	cout<<"Enter Key(Upper Case Letter Only):";
	getline(cin,key);

	string gkey = generatekey(txt,key);

	string enc = polyenc(txt,gkey);
	cout<<"Encryption:"<<enc<<endl;

	string dec = polydec(enc,gkey);
	cout<<"Decryption:"<<dec<<endl;

	return 1;
}


// output:

// Enter Text(Upper Case Letter Only):HELLO
// Enter Key(Upper Case Letter Only):KEY
// Encryption:RIJVS
// Decryption:HELLO
