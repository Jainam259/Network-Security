#include <iostream>
#include <cstdlib>
#include <openssl/rand.h>
#include <openssl/evp.h>

using namespace std;

void generateSecretKey(int keylength, string algorithmName) {
    unsigned char key[64];

    if (keylength > sizeof(key)) {
        cout << "Key Length exceeds maximum size of " << sizeof(key) << " bytes." << endl;
        return;
    }

    // Generate random bytes for the secret key
    if (RAND_bytes(key, keylength) != 1) {
        cout << "Error Generating Random Bytes." << endl;
        return;
    }

    cout << algorithmName << " Secret Key (" << keylength * 8 << " bits): ";

    for (int i = 0; i < keylength; i++) {
        printf("%02x", key[i]);
    }
    cout << endl;
}

int main() {
    int keylength;
    string algorithmName, keyType;

    cout << "Enter The Key Type (symmetric) = ";
    cin >> keyType;

    cout << "Enter The Algorithm Name (des, blowfish, idea, triple des) = ";
    cin >> algorithmName;

    if (keyType == "symmetric") {
        if (algorithmName == "des") {
            keylength = 8;
        } else if (algorithmName == "blowfish") {
            keylength = 16;
        } else if (algorithmName == "idea") {
            keylength = 16;
        } else if (algorithmName == "triple des") {
            keylength = 24;
        } else {
            cout << "Invalid algorithm. Please choose from des, blowfish, triple des, or idea." << endl;
            return 1;
        }
        generateSecretKey(keylength, algorithmName);
    } else {
        cout << "Invalid Key Type. Please choose 'symmetric'." << endl;
    }

    return 0;
}
