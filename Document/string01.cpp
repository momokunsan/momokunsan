//string01.cpp(p.184)
#include <iostream>
#include <string>
using namespace std;

int main() {


	string a; //��̕�������\�z
	string b = "sample"; //�����񂩂當����I�u�W�F�N�g�𐶐�
	/*���ƂȂ镶����b�̈�Ԗڂ̕�������R�����܂ł�
	����������I�u�W�F�N�g�𐶐�*/
	string c(b, 1, 3); 
	string d("sample", 2); //������̐擪�Q��������Ȃ镶����I�u�W�F�N�g�𐶐� 
	string e(10, 't'); //10�������̕���t����Ȃ镶����I�u�W�F�N�g�𐶐�
	string f{'s', 'a', 'm', 'p', 'l', 'e'}; //�����̏������q���X�g���當����I�u�W�F�N�g�𐶐�
	string g = b; //�R�s�[�\�z�B�n���ꂽ������̕���
	string h0 = b; //���[�u�\�z�B�n���ꂽ�������*this�Ɉړ��B�R�s�[�\�z��葬��
	string h = move(h0); //move���͖�����̒l�ƂȂ�i���󂳂��j
	string i(b.begin(), b.end()); //�C�e���[�^�Ŏw��コ�ꂽ�͈͂̕�����I�u�W�F�N�g�𐶐�
	
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