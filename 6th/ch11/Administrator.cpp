#include "Administrator.h"
#include "Security.h"

#include <iostream>
using namespace std;

bool Administrator::Login(string username, string password){
    if (Security::validate(username, password) > 1)
        return true;
    return false;
}

