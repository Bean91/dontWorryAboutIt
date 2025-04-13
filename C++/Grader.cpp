#include <iostream>
using namespace std;
//Get the students GPA (max of 4.0), print the user grades for the following classes: ENG-92, MAT-6, SCI-99, ART-81, SOC-64.
//ask the user how many more classes they would like to add before doing your calculations
int main() {
    cout << "Welcome to the grader you failure. We will give you a GPA up to 4.0. The classes include the following: ENG-92, MAT-6, SCI-99, ART-81, SOC-64. Please tell me the number of additional classes you would like to add (Max 5)." << endl;
    int numAdditional;
    cin >> numAdditional;
    string classes[10];
    int grades[10];
    int numClasses = 5;
    double sumGrades = 0.0;
    classes[0] = "ENG-92";
    classes[1] = "MAT-6";
    classes[2] = "SCI-99";
    classes[3] = "ART-81";
    classes[4] = "SOC-64";
    string additionalClass;
    for(int i = 0; i < numAdditional; i++) {
        cout << "Please enter your next class" << endl;
        cin >> additionalClass;
        classes[(i+5)] = additionalClass;
        if(!additionalClass.empty()){
            numClasses++;
        }
    }
    for(int j = 0; j < numClasses; j++) {
        cout << "Please enter your grade out of 100 for the class: " << classes[j] << endl;
        cin >> grades[j];
        if(grades[j] >= 90) {
            sumGrades += 4.0;
        } else if(grades[j] >= 80) {
            sumGrades += 3.0;
        } else if(grades[j] >= 70) {
            sumGrades += 2.0;
        } else if(grades[j] >= 60) {
            sumGrades += 1.0;
        }
    }
    double averageGrade = sumGrades/numClasses;
    cout << "Your GPA(LOOOOOL): " << averageGrade << endl;
    return 0;
  
}