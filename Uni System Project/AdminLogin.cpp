#include "AdminLogin.h"

AdminLogin::AdminLogin()
{
    admin_passwords_["shahdM"] = "password1";

    admin_passwords_["shahdH"] = "password2";

    admin_passwords_["doha"] = "password3";
    //admin_passwords_.insert(make_pair("shahd", "password1"));
    //admin_passwords_.insert(make_pair("shahd", "password2")); // This line has no effect

}

bool AdminLogin::verifyAdminLogin(string username, string password)
{
    // Checks if the given username is in the hash table
    auto it = admin_passwords_.find(username);
    if (it == admin_passwords_.end())
    {
        return false; // Username not found
    }


    return password == it->second;
}
