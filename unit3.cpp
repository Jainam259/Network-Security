// 1. VRC

/*

#include<iostream>
using namespace std;

int main()
{
    string data;
    cout<<"Enter Data (Only Binary) = ";
    cin>>data;
    
    int ch = 1;
    cout<<"Enter Your Choice = ";
    cin>>ch;
    
    int count = 0;
    for(int i=0; i<data.length(); i++)
    {
        if(data[i] == '1')
            count++;
    }
    
    if(ch == 1)
    {
        if(count % 2 == 0)
            data.append("0");
        else
            data.append("1");
    }
    else if(ch == 2)
    {
        if(count % 2 != 0)
            data.append("0");
        else
            data.append("1");
    }
    else
    {
        cout<<"Invalid Choice!";
        return 1;
    }
    
    cout<<"VRC = "<<data<<endl;
    return 0;
}

*/


// Enter Data (Only Binary) = 1101001
// Enter Your Choice = 1
// VRC = 11010010












// 2. LRC

/*

#include<iostream>
using namespace std;

int main()
{
    string data;
    cout<<"Enter Data (Only Binary OR Even Length) = ";
    cin>>data;
    
    int bit;
    cout<<"Enter Bit = ";
    cin>>bit;
    
    int len = data.length() / bit;
    
    char dat[len][bit];
    
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<bit; j++)
        {
            dat[i][j] = data[i * bit + j];
        }
    }
    
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<bit; j++)
        {
            cout<<dat[i][j];
        }
        cout<<endl;
    }
    
    int parity[bit];
    int ch;
    
    cout<<"Enter Your Choice (1-Even,2-ODD) = ";
    cin>>ch;
    cout<<"\n";
    
    for(int j=0; j<bit; j++)
    {
	int count = 0;
        for(int i=0; i<len; i++)
        {
            if(dat[i][j] == '1')
                count++;
        }
    
        if(ch == 1)
        {
            if(count % 2 == 0)
                parity[j] = 0;
            else
                parity[j] = 1;
        }
        else if(ch == 2)
        {
            if(count % 2 != 0)
                parity[j] = 0;
            else
                parity[j] = 1;
        }
    }
    
    cout<<endl<<" Parity = ";
    for(int j=0; j<bit; j++)
    {
        cout<<parity[j];
    }
    cout<<endl;
}


*/










// 3. CRC

/*

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

char exor(char a,char b)
{
    if(a == b)
        return '0';
    else
        return '1';
}

void crc(char data[],char key[])
{
    int datalen = strlen(data);
    int keylen = strlen(key);
    
    for(int i=0; i<keylen-1; i++)
    {
        data[datalen+i] = '0';
        data[datalen+keylen-1] = '\0';
    }
    
    int codelen = datalen + keylen - 1;
    
    char temp[20],rem[20];
    
    for(int i=0; i<keylen; i++)
        rem[i] = data[i];
        
    for(int j=keylen; j<=codelen; j++)
    {
        for(int i=0; i<keylen; i++)
            temp[i] = rem[i];
            
        if(rem[0] == '0')
        {
            for(int i=0; i<keylen-1; i++)
                rem[i] = temp[i+1];
        }
        else
        {
            for(int i=0; i<keylen-1; i++)
                rem[i] = exor(temp[i+1],key[i+1]);
        }
        
        if(j != codelen)
            rem[keylen-1] = data[j];
        else
            rem[keylen-1] = '\0';
    }
    
    for(int i=0; i<keylen-1; i++)
    {
        data[datalen+i] = rem[i];
        data[codelen] = '\0';
    }
    cout<<"CRC = "<<rem<<"\nDataword = "<<data<<endl;
}

int main()
{
    char key[20],data[20];
    
    cout<<"Enter The Data = ";
    cin>>data;
    
    cout<<"Enter The Key = ";
    cin>>key;
    
    crc(data,key);
}

*/

// Enter The Data = 1001
// Enter The Key = 1011
// CRC = 110
// Dataword = 1001110


























// 4.Hellman Algorithm

#include<iostream>
#include<cmath>
using namespace std;

long long int func(long long int g,long long int h,long long int Ps)
{
    if(h == 1)
        return g;
    else
        return (((long long int)pow(g,h)) % Ps);
}

int main()
{
    long long int p,q,g,h,Ps,Gs,K_A,K_B;
    
    Ps = 32;
    cout<<"Value of Ps is = "<<Ps<<endl;
    
    Gs = 5;
    cout<<"Value of Gs is = "<<Gs<<endl;
    
    g = 6;
    cout<<"Private Key of G is = "<<g<<endl;
    
    p = func(Gs,g,Ps);
    
    h = 2;
    cout<<"Private Key of H is = "<<h<<endl;
    
    q = func(Gs,h,Ps);
    
    K_A = func(q,g,Ps);
    K_B = func(p,h,Ps);
    
    cout<<"Allen's Secret Key is = "<<K_A<<endl;
    cout<<"Roy's Secret Key is = "<<K_B<<endl;
}


// Value of Ps is = 32
// Value of Gs is = 5
// Private Key of G is = 6
// Private Key of H is = 2
// Allen's Secret Key is = 17
// Roy's Secret Key is = 17
