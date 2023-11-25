#include "menhely.h"

using namespace std;

int main()
{
	string username, password;
	Menhely user("admin", "admin123");

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	if (user.loginValidate(username, password)) {
		std::cout << "Login successful! Welcome, " << username << "!\n";
	}
	else {
		std::cout << "Invalid username or password. Login failed.\n";
	}

	return 0;
}