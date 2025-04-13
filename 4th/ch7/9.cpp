#include <iostream>
using namespace std;
#include <math.h>

class zip_code{
    public:
        zip_code(int codeValue): code(codeValue){}
        zip_code(string codeValue);
        string getCodeNum() const; 
        string getCodeStr() const;
    private:
        int code;
};

int main(){
    zip_code zipcodenum(10500);
    zip_code zipcodestr("110100101000101011000010011");

    cout << zipcodenum.getCodeNum() << endl;
    cout << zipcodenum.getCodeStr() << endl;
    cout << endl;
    cout << zipcodestr.getCodeNum() << endl;
    cout << zipcodestr.getCodeStr() << endl;
    
    return 0;
}

zip_code::zip_code(string codeValue){
    code = 0;
    int temp;
    int values[5] = {7, 4, 2, 1, 0};
    for(int i = 0; i < 5; ++i){
        temp = 0;
        for(int j = 0; j < 5; ++j)
            temp += (codeValue[i * 5 + j + 1] - '0') * values[j];
        if(temp != 11)
            code += temp * pow(10, 4 - i);
    }
}

string zip_code::getCodeNum() const{
    char temp[5];
    
    for(int i = 0; i < 5; ++i)
        temp[i] = (char) (code / (int) pow(10, 4 - i) % 10) + '0';
    
    return temp;
}

string zip_code::getCodeStr() const{
    string temp = "";
    for(int i = 0; i < 5; ++i)
        switch(code / (int) pow(10, 4 - i) % 10){
            case 0:
                temp += "11000";
                break;
            case 1:
                temp += "00011";
                break;
            case 2:
                temp += "00101";
                break;
            case 3:
                temp += "00110";
                break;
            case 4:
                temp += "01001";
                break;
            case 5:
                temp += "01010";
                break;
            case 6:
                temp += "01100";
                break;
            case 7:
                temp += "10001";
                break;
            case 8:
                temp += "10010";
                break;
            case 9:
                temp += "10100";
                break;
        }
    return "1" + temp + "1";
}

/*
Prior to 2009 the bar code on an envelope used bt the U.S. Postal service represented
 a five (or more) digit zip code using a format called POSTNET. 
 The bar code consists of long and short bars as shown here: 
    llIlIIlILIIIlIlIllIIIIlIIll
For this program, we will represent the bar code as a string of digits.
The digit 1 represents a long bar, and the digit 0 represent a short bar. 
Therefore, the bar code shown would be represented in out program as follows: 
    110100101000101011000010011
The first and last digits of the bar code are always 1.
Removing these leave 25 digits. 
If these 25 digits are split into groups of five digits each then we have the following: 
    10100 10100 01010 11000 01001
Next, consider each group of digits. 
Each digit stands for a number.
From left to right, the digits encode the values 7, 4, 2, 1 and 0. 
Multiply the corresponding value with the digt and compute the sum to get the final encoded digit for the zip code. 
The following table shows the encoding for 10100.
    Bar Code Digits 1 0 1 0 0
    Value           7 4 2 1 0
    Digit * Value   7 0 2 0 0
    Zip Code Digit = 7 + 0 + 2 + 0 + 0 = 9
Repeat this for each group of five digits and concatenate to get the complete zip code. 
There is one special value. 
If the sum of a group of five digits is 11, then this represents the digit 0 
(this is necessary because with two digits per group it is not possible to represent zero). 
The zip code for the sample bar code decodes to 99504. 
While the POSTNET scheme may seem unnecessarily complex, 
its design allows machines to detect ehether errors have been made in scanning the zip code. 
Write a zip code class that encodes and decodes five-digit bar codes used by the U.S. Postal service on envelopes. 
The class should have two constructors.
The first constructor should input the zip code as an integer, and the second constructor should input
the zip code as a bar code string consisting of 0's and 1's as described above. 
Although you gave two ways to input the the zip code, inetnally, the class should only store the zip code using one format. 
(You may choose to store it as a bar code string or as a zip code number.)
The class also hould have at least two public member functions: one to return the zip code as an integer 
and the other to return the zip code in bar code format as a string. 
All helper functions should be declared private. 
Embed your class definition in a suitable test program. 
*/