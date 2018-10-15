//string01.cpp(p.184)
#include <iostream>
#include <string>
using namespace std;

int main() {


	string a; //空の文字列を構築
	string b = "sample"; //文字列から文字列オブジェクトを生成
	/*元となる文字列bの一番目の文字から３文字までの
	部分文字列オブジェクトを生成*/
	string c(b, 1, 3); 
	string d("sample", 2); //文字列の先頭２文字からなる文字列オブジェクトを生成 
	string e(10, 't'); //10文字分の文字tからなる文字列オブジェクトを生成
	string f{'s', 'a', 'm', 'p', 'l', 'e'}; //文字の初期化子リストから文字列オブジェクトを生成
	string g = b; //コピー構築。渡された文字列の複製
	string h0 = b; //ムーブ構築。渡された文字列を*thisに移動。コピー構築より速い
	string h = move(h0); //move元は未既定の値となる（＝壊される）
	string i(b.begin(), b.end()); //イテレータで指定医された範囲の文字列オブジェクトを生成
	
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
	cout << "e:" << e << endl;
	cout << "f:" << f << endl;
	cout << "g:" << g << endl;
//	cout << "h0:" << h0 << endl;
	cout << "h:" << h << endl;
	cout << "i:" << i << endl;

	char z;
	cin >> z;
	return 0;
}