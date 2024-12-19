// RSA

#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a,int b)
{
    int t;
    while(1)
    {
        t = a % b;
        if(t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main()
{
    double p = 13;
    double q = 11;
    double n = p * q;
    double track;
    double phi = (p-1) * (q-1);
    double e = 7;

    while(e < phi)
    {
        track = gcd(e,phi);
        if(track == 1)
            break;
        else 
            e++;
    }

    double d1 = 1/e;
    double d = fmod(d1,phi);
    double message = 9;
    double c = pow(message,e);
    double m = pow(c,d);
    c = fmod(c,n);
    m = fmod(m,n);

    cout<<"Original Message = "<<message<<endl;
    cout<<"P = "<<p<<endl;
    cout<<"Q = "<<q<<endl;
    cout<<"N = PQ = "<<n<<endl;
    cout<<"Phi = "<<phi<<endl;
    cout<<"E = "<<e<<endl;
    cout<<"D = "<<d<<endl;

    cout<<"Encrypted Message = "<<c<<endl;
    cout<<"Decrypted Message = "<<m<<endl;

    return 1;
}