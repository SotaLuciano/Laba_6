#pragma once
#include <string>

using namespace std;

class Converting
{
public: 
	//��'��� � ������
	virtual	string Obj_To_Str() = 0;

	//������ � ��'���
	virtual void Str_To_Obj(string Obj_) = 0;

};