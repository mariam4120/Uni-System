#pragma once
#include <iostream>
#include<unordered_map>

using namespace std;


// Hash function for strings
struct StringHasher{
	size_t operator()(const string & st) const {
		return hash<string>()(st);
	}
};
class AdminLogin
{
   public:
	   AdminLogin();
	   bool verifyAdminLogin(string username, string password);

   private:
	   // Hash table to store admin usernames and hashed passwords
	   unordered_map<string, string,StringHasher> admin_passwords_;


};

