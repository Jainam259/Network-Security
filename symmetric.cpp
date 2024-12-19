// // AES,DES,BLOWFISH,TripleDes,HMACMD5,HMACSH1

#include<iostream>
#include<cstdlib>
#include<openssl/rand.h>
#include<openssl/evp.h>

using namespace std;

void generateSymmetricKey(int keylength,string algorithmName)
{
	unsigned char key[64];

	if(keylength > sizeof(key))
	{
		cout<<"Key Length exceeds maximum size of "<<sizeof(key)<<" bytes."<<endl;
		return;
	}

	if(RAND_bytes(key,keylength) != 1)
	{
		cout<<"Error Generating Random Bytes."<<endl;
		return;
	}

	cout<<algorithmName<<" Symmetric Key ("<<keylength * 8 <<" (Bits) = ";

	for(int i=0; i<keylength; i++)
	{
		printf("%02x",key[i]);
	}
	cout<<endl;
}

int main()
{
	int keylength;
	string algorithmName,keyType;

	cout<<"Enter The Key Type = ";
	cin>>keyType;

	cout<<"Enter The AlgorithmName = ";
	cin>>algorithmName;

	if(keyType == "symmetric")
	{
		if(algorithmName == "des")
		{
			keylength = 8;
		}
		else if(algorithmName == "blowfish")
		{
			keylength = 16;
		}
		else if(algorithmName == "idea")
		{
			keylength = 16;
		}
		else if(algorithmName == "triple des")
		{
			keylength = 24;
		}
		else
		{
			cout<<"Invalid algorithm. please choose from des,blowfish,triple des or idea."<<endl;
			return 1;
		}
		generateSymmetricKey(keylength,algorithmName);
	}
	else
	{
		cout<<"Invalid Key Type.please choose from correct name"<<endl;
	}

	return 1;
}


// #include<iostream>
// #include<cstdlib>
// #include<openssl/rand.h>
// #include<openssl/evp.h>
// using namespace std;

// void generateSymmetricKey(int keylength, string algorithmName) 
// {
//     unsigned char key[64];

//     if (keylength > sizeof(key)) 
//     {
//         cout << "Key Length exceeds maximum size of " << sizeof(key) << " bytes." << endl;
//         return;
//     }

//     // Generate random bytes for the symmetric key
//     if (RAND_bytes(key, keylength) != 1) 
//     {
//         cout << "Error Generating Random Bytes." << endl;
//         return;
//     }

//     cout << algorithmName << " Symmetric Key (" << keylength * 8 << " bits): ";

//     for (int i = 0; i < keylength; i++) 
//     {
//         printf("%02x", key[i]);
//     }
//     cout << endl;
// }

// int main() 
// {
//     int keylength;
//     string algorithmName, keyType;

//     cout << "Enter The Key Type (symmetric) = ";
//     cin >> keyType;

//     cout << "Enter The Algorithm Name (des, blowfish, idea, triple des) = ";
//     cin >> algorithmName;

//     if (keyType == "symmetric") 
//     {
//         if (algorithmName == "des") 
//         {
//             keylength = 8;
//         } 
//         else if (algorithmName == "blowfish") 
//         {
//             keylength = 16;
//         }
//         else if (algorithmName == "idea") 
//         {
//             keylength = 16;
//         } 
//         else if (algorithmName == "triple des") 
//         {
//             keylength = 24;
//         }
//         else if (algorithmName == "hmacmd5") 
//         {
//         	keylength = 16; // HMAC MD5 key length is 16 bytes (128 bits)
//     	} 
//     	else if (algorithmName == "hmacsha1") 
//     	{
//         	keylength = 20; // HMAC SHA1 key length is 20 bytes (160 bits)
//     	} 
//         else 
//         {
//             cout << "Invalid algorithm. Please choose from des, blowfish, triple des, or idea." << endl;
//             return 1;
//         }
//         generateSymmetricKey(keylength, algorithmName);
//     } 
//     else 
//     {
//         cout<<"Invalid Key Type. Please choose 'symmetric'." << endl;
//     }

//     return 1;
// }




// g++ symmetric.cpp -o symmetric -lssl -lcrypto
// ./symmetric

// Enter The Key Type (symmetric) = symmetric
// Enter The Algorithm Name (des, blowfish, idea, triple des) = des
// des Symmetric Key (64 bits): fcec5b997b908733
