//string02.cpp(p.187)
#include <iostream>
#include <string>
using namespace std;
//using namespace std::literals;
//using namespace std::string_literals;

int main() {

	auto str = "hello"s;
	auto u8str = u8"hello"s;
	auto u32str = U"hello"s;

	cout << str << endl;
	cout << u8str;
	//cout << u32str;

	char z;
	cin >> z;
}