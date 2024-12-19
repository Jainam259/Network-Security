// Hashing

#include<iostream>
#include<string>
using namespace std;

// RS Hash function

unsigned int RSHash(string str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for(int i=0; i<str.length(); i++)
	{
		hash = hash * a + str[i];
		a = a*b;
	}
	return hash;
}

// JS Hash function
unsigned int JSHash(string str)
{
	unsigned int hash = 1315423911;
	for(int i=0; i<str.length(); i++)
	{
		hash ^= ((hash << 5) + str[i] + (hash>>2)); 
	}
	return hash;
}

// BKDR Hash
unsigned int BKDRHash(string str)
{
	unsigned int seed = 131;
	unsigned int hash = 0;

	for(int i=0; i<str.length(); i++)
	{
		hash = hash * seed + str[i];
	}
	return hash;
}

unsigned int DJBHash(string str)
{
	unsigned int hash = 5381;

	for(int i=0; i<str.length(); i++)
	{
		hash = ((hash << 5) + hash) + str[i];
	}
	return hash;
}


int main()
{
	string input;
	cout<<"Enter A String to Hash = ";
	getline(cin,input);

	cout<<"RSHash = "<<RSHash(input)<<endl;

	cout<<"JSHash = "<<JSHash(input)<<endl;

	cout<<"BKDRHash = "<<BKDRHash(input)<<endl;

	// cout<<"SDBMHash = "<<SDBMHash(input)<<endl;

	cout<<"DJBHash = "<<DJBHash(input)<<endl;
}