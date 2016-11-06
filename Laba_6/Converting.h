#pragma once
#include <string>

using namespace std;

class Converting
{
public: 
	//Об'єкт у стрічку
	virtual	string Obj_To_Str() = 0;

	//Стрічку в об'єкт
	virtual void Str_To_Obj(string Obj_) = 0;

};