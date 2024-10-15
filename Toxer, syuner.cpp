#include <iostream>
#include <string>
using namespace std;

int main() {
    int mtx[100][100];  
    string str;
    cout << "Enter the sentence: ";
    getline(cin, str); 

    int count = str.length();
    cout << "The length of the sentence is: " << count << endl;

    int key;
    cout << "Enter the number: ";
    cin >> key;

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

    cout << "Printing the matrix column by column: " << endl;
    for (int j = 0; j < key; j++) {  
        for (int i = 0; i < m; i++) { 
            cout << (char)mtx[i][j];  /
        }
        cout << endl;  
    }

    return 0;
}
