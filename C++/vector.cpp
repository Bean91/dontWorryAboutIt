#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numbers[10];
    for(int i = 0; i<10; i++) {
        numbers[i] = i;
        // cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }
    string myText = "12345";

    cout << "Size: " << size(myText) << endl;
    // cout << "Length: " << number.length() << endl;
    for(int j=0; j < size(numbers); j++) {
        if(numbers[j] % 2 == 0) {
            numbers[j]++;
        }
        // cout << "numbers[" << j << "] = " << numbers[j] << endl;
    }
    //int num[1]={}; //default values: string == "" double == 0.0 float == 0.f or 0.0f, bool == false, char == '\0' (this is a null character)
    // cout << num[0] << endl;
    vector<int> vectorOhYeah ={54,23,234,245,64};
    vectorOhYeah.push_back(32);
    // Erase the first elementout 
    vectorOhYeah.erase(vectorOhYeah.begin());

    // Erase the last element
    vectorOhYeah.erase(vectorOhYeah.end() - 1);

    // Erase the second element (index 1)
    vectorOhYeah.erase(vectorOhYeah.begin() + 1);
    cout<<vectorOhYeah.empty()<<endl;
    for(int i = 0; i < size(vectorOhYeah); i++) {
        cout << vectorOhYeah[i] << endl;
    }
    return 0;
    //input a and input b
    //NAND(A, A) = NOT(A AND A) = NOT(A)
}