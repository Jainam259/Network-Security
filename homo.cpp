// Homophonic ceaser cipher

#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;

int main()
{
	string map[26] = {
		"QWE","RTY","UIO","ASD","FGH","HJK","LZX","CVB","NMQ",
		"WER","TYU","IOP","ASD","FGH","JKL","ZXC","VBN","MQW",
		"ERT","YUI","OPA","SDF","GHJ","KLZ","XCV","BNM"
	};

	int i,j;
	string pt,ct;
	int char_val,key;

	cout<<"Enter Plain text:";
	getline(cin,pt);

	for(i=0; i<pt.size(); i++)
	{
		if(isalpha(pt[i]))
		{
			key = rand() % 3;
			cout<<endl<<"K = "<<key;

			char_val = pt[i] - 'A';
			ct = ct + map[char_val][key];
		}
		else
		{
			ct = ct + pt[i];
		}

	}
	cout<<endl<<"Encryption = "<<ct<<endl;	
}





// OUTPUT:

// Enter Plain text:HELLO WORLD

// K = 1
// K = 1
// K = 0
// K = 1
// K = 2
// K = 1
// K = 1
// K = 0
// K = 0
// K = 1
// Encryption = VGIOL HKMIS














































// #include<iostream>
// #include<cstdlib>
// #include<cctype>
// using namespace std;

// int main()  // Corrected to main() from manin()
// {
//     string map[26] = {
//         "QWE", "RTY", "UIO", "ASD", "FGH", "HJK", "LZX", "CVB", "NMQ",
//         "WER", "TYU", "IOP", "ASD", "FGH", "JKL", "ZXC", "VBN", "MQW",
//         "ERT", "YUI", "OPA", "SDF", "GHJ", "KLZ", "XCV", "BNM"
//     };

//     int i, key;
//     string pt, ct;
//     int char_val;

//     cout << "Enter Plain text: ";
//     getline(cin, pt); 

//     for(i = 0; i < pt.size(); i++) 
//     {
//         if(isalpha(pt[i]))  
//         {
//             key = rand() % 3;  
//             cout << endl << "K = " << key;

//             char_val = toupper(pt[i]) - 'A';  
            
//             if (char_val >= 0 && char_val < 26) {
//                 ct += map[char_val][key];  
//             } else {
//                 ct += pt[i];
//             }
//         }
//         else
//         {
//             ct += pt[i];  
//         }

//         // cout << endl << "Encryption so far: " << ct;
//     }

//     cout << endl << "Final Encrypted text: " << ct << endl;  
//     return 0;
// }






