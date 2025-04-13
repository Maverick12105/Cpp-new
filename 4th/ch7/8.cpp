#include <iostream>
#include <vector>
using namespace std;

int main(){
    int iTemp;
    vector<int> gradesRaw;
    int gradeMax = 0;
    vector<int> grades;
    vector<int> gradesAmount;
    int gradesAmountMax = 0;

    while(true){
        cout << "Grade => ";
        cin >> iTemp;
        if(iTemp == -1)
            break;
        gradesRaw.push_back(iTemp);
    }

    for(int i = 0; i < gradesRaw.size(); ++i)
        for(int j = i; j < gradesRaw.size(); ++j)
            if(gradesRaw[i] > gradesRaw[j])
                swap(gradesRaw[i], gradesRaw[j]);

    for(int i = 0; i < gradesRaw.size(); ++i)//
        cout << gradesRaw[i];
    cout << endl;
    
    for(int i = 0; i < gradesRaw.size(); ++i){
        if(gradesRaw[i] != gradesRaw[i-1]){
            grades.push_back(gradesRaw[i]);
            gradesAmount.push_back(1);
        }
        else
            ++gradesAmount[gradesAmount.size() - 1];
    }

    for(int i = 0; i < gradesAmount.size(); ++i)
        if(gradesAmountMax < gradesAmount[i])
            gradesAmountMax = gradesAmount[i];

    for(int i = gradesAmountMax; i > 0 ; --i){
        for(int j = 0; j < grades.size(); ++j){
            if(gradesAmount[j] >= i)
                cout << "- ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for(int i = 0; i < grades.size(); ++i)
        cout << grades[i] << ' ';

    return 0;
}

/*
Write a program that outputs a histogram of grades for an assignment given to a class of students. 
The program should input each student's grade as an integer and store the grade in a vector. 
Grades should be entered until the user enters -1 for a grade.
The program should then scan through the vector and compute the histogram. 
In computing the histogram, the minimum value of a grade is 0, 
but your program should determain the maximum value entered by the user.
Output the histogram to the console. 
See Programming Project 5.7 for information on how to compute a histogram. 
*/