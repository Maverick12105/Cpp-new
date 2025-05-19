#include <iostream>
using namespace std;
#include "Security.h"
#include "Administrator.h"
#include "User.h"

int main(){
    cout << Administrator::Login("costello", "tuesday") << endl;
    cout << Administrator::Login("abbott", "monday") << endl;
    cout << Administrator::Login("bella", "sunday") << endl;
    cout << endl;
    cout << User::Login("costello", "tuesday") << endl;
    cout << User::Login("abbott", "monday") << endl;
    cout << User::Login("bella", "sunday") << endl;

    return 0;
}

/*
    You would like to verify the credentials of a user for your system. 
    Listed nexy is a class named Security, which authenticates a user and password. 
    (Note that this example is really not very secure. Typically passwords would be encrypyted or stored in a database.)
        class Security{
            public:
                static int validate(string username, string password);
        };

        // This Subroutine hard-codes valid users and is not
        // considered a secure practice. 
        // It returns 0 if the credentials are invalid,
        // 1 if valid user, and
        // 2 if valid administrator

        int Security::validate(string username, string password){
            if((username == "abbott") && (password == "monday")) return 1;
            if((username == "costello") && (password == "tuesday")) return 2;
            return 0;
        }
    Break this class into two files, a file with the header Security.h and a file with the implementation Security.cpp. 
    Next, create two more classes that use the Security class by including the header file. 
    The first class should be name Administrator and contain a funcion name Login that returns true if a given username and password have administrator clearance. 
    The second class should be named User and contain a function named Login that returns true if a given username and password have either user or administrator clearance.
    both the user and Administrator classes should be split into separate files for the header and implementation. 
    Finally, write a main funcion that invokes the Login function for both the User and Administrator classes to test if they work properly. 
    The main function should be in a separate file.
    Be sure to use the ifndef directive to ensure that no header file is included more than once. 
*/