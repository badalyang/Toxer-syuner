#include <iostream>
#include <string>
using namespace std;

void encrypt(const string& str, int key) {
    int mtx[100][100];
    int count = str.length();
    int m = count / key;
    if (count % key != 0) {
        m += 1;
    }

    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < key; j++) {
            if (index < count) {
                mtx[i][j] = str[index];
            } else {
                mtx[i][j] = ' '; 
            }
            index++;
        }
    }

    cout << "Encrypted message: ";
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < m; i++) {
            cout << (char)mtx[i][j];
        }
    }
    cout << endl;
}

void decrypt(const string& encrypted, int key) {
    int mtx[100][100];
    int count = encrypted.length();
    int m = count / key;
    if (count % key != 0) {
        m += 1;
    }

    int index = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < m; i++) {
            if (index < count) {
                mtx[i][j] = encrypted[index];
            } else {
                mtx[i][j] = ' ';
            }
            index++;
        }
    }

    cout << "Decrypted message: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < key; j++) {
            cout << (char)mtx[i][j];
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter the sentence to encrypt: ";
    getline(cin, str);

    int key;
    cout << "Enter the key number: ";
    cin >> key;

    encrypt(str, key);

    string encrypted;
    cout << "Enter the encrypted message to decrypt: ";
    cin.ignore();
    getline(cin, encrypted);

    decrypt(encrypted, key);

    return 0;
}
