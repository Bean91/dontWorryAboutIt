#include <iostream>
using namespace std;

int main() {
    int numTimes;
    cout << "Number of times to say Fuiyoh" << endl;
    cin >> numTimes;
    if(numTimes == 42){
        cout << "Da meaning of life" << endl;
    } else if(numTimes == 420){
        cout << "My birthday" << endl;
    } else if(numTimes == 69){
        cout << "You're weird" << endl;
    } else if(numTimes == 91){
        cout << "One of my favorite numbers" << endl;
    } else if(!numTimes){
        cout << "Your just plain mean. HAIYA" << endl;
    } else{
        for(int i = 0; i < numTimes; i++) {
            cout << "Fuiyoh" << endl;
        }
    }
    while(numTimes){
        if(numTimes % 2 == 0){
            if(numTimes == 10){
                // numTimes--;
                // continue;
                goto emotional_damage;
            }
            cout << numTimes << endl;
        }
        back_to_work:
        numTimes--;
    }

    if(false) {
        emotional_damage:
        cout << "EMOTIONAL DAMAGE" << endl;
    }
    if(numTimes) {
        goto back_to_work;
    }
    return 0;
}