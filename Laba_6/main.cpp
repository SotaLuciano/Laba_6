#include "TicketBusService.h"

string date_time_selling()
{
	char* a = new char[30];
	time_t t = time(0);
	struct tm * now = localtime(&t);
	sprintf(a, "%02d:%02d:%02d %02d.%02d.%4d", now->tm_hour, now->tm_min, now->tm_sec, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	string my_row(a);
	return my_row;
}

void main()
{
	//Тестування сортування + множинне наслідування
	TicketBusService TS[3];
	int Money;
	for (int k(0); k < 3; k++)
	{
		cout << "Enter " << k << " object Total money: ";
		cin >> Money;
		TS[k].SetMoney(Money);
	}
	TicketBusService tmp;
	//Сортування
	for (int i = 0; i <3 - 1; ++i) 
	{
		for (int j = 0; j < 3 - 1; ++j)
		{
			if (TS[j + 1] < TS[j])
			{
				tmp = TS[j + 1];
				TS[j + 1] = TS[j];
				TS[j] = tmp;
			}
		}
	}
	int temp;
	//вивід
	for (int k(0); k < 3; k++)
	{
		temp = TS[k].GetMoney();
		cout << temp << endl;
	}
	
	//Тестування конвертування
	TicketBusService A;
	A.InputInfo("Lviv-Paris", 428, 8.00, 20.00);
	string time = date_time_selling();
	A.SetCurrentTime(time);
	A.Sale();
	A.GetAmountOfTicketService();
	string K = A.Obj_To_Str();
	cout << K<< endl;
	A.Str_To_Obj(K);
	A.Print();
}