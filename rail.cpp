// Rail Fence

#include<iostream>
using namespace std;

int main()
{
	string pt;
	int key;

	cout<<"Enter text:";
	cin>>pt;

	cout<<"Enter Key:";
	cin>>key;

	string rails[key];
	int direction = 1;
	int currentRail = 0; 

	for(int i=0; i<pt.length(); i++)
	{
		rails[currentRail] += pt[i];

		if(currentRail == 0)
			direction = 1;
		else if(currentRail == key - 1)
			direction = -1;
		currentRail += direction;
	}

	string ct;
	for(int i=0; i<key; i++)
	{
		ct += rails[i];
	}
	cout<<"Cipher:"<<ct<<endl;

	return 0;
}


// output

// Enter text:Hello
// Enter Key:3
// Cipher:Hoell
