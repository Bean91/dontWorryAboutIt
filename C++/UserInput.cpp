#include <iostream>
using namespace std;

int main(){
    int ssn;
    cout << "Hello Bozos, give me your social security number. Now. Or you die. I have a Glock-18C. It has Happy Mode." << endl;
    cin >> ssn;
    if (ssn == 0) {
        cout << "You no give me your social security, now you die. *pew pew pew*" << endl;
    }
    else {
        cout << ssn << ", is this true? No? Ok, now you die. *pew pew pew*" << endl;
    }
    return 0;
}