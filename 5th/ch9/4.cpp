#include <iostream>
using namespace std;

int main(){
    bool repeat = true;
    string strIn;
    bool flag;

    while (repeat){
        cin >> strIn;
        bool flag = false;
        if (strIn.length() > 3){
            for (int i = 0; i < 4; ++i)
                if (!isalpha(strIn[i])){
                    flag = true;
                    break;
                }
            if (!flag)
                for (int i = 4; i < strIn.length(); ++i)
                    if (isalpha(strIn[i])){
                        flag = true;
                        break;
                    }
        }
        else 
            flag = true;
        if (flag)
            cout << strIn;
        else{
            if (isupper(strIn[0]))
                cout << "Love";
            else
                cout << "love";
            for (int i = 4; i < strIn.length(); ++i)
                cout << strIn[i];
        }
        if (isspace(cin.peek()))
            cout << (char) cin.get();
        
            cout << "Repeat? => ";
            cin >> repeat;
            if (!repeat)
                break;
    }

    

    return 0;
}

/*
Write a program that reads in a line of text and replaces all four-letter words with the word "love". 
For example, the input string
    I hate you, you dodo!
should produce the following output:
    I love you, you love!
Of course, the output will not always make sense. 
For example, the input string
    John will run home. 
should produce the following output: 
    Love love run love. 
If the four-letter word starts with a capital letter, it should be replaced by "Love", not by "love". 
You need not check capitalization, except for the first letter of a word. 
A word is any string consisting of the letter of the alphabet and delimited at each end by a blank, 
the end of the line, or any other character that is not a letter.
Your program should repeat this action until the user says to quit. 
*/