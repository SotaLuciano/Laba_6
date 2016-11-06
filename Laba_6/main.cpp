#include "TicketBusService.h"

void Sort_Obj(Amount_Of_Ticket_Service **AB, int size)
{

	int tmp, tmp1;
	for (int i(1); i < size; i++)
	{
		for (int j(0); j < (size - i); j++)
		{
			if (AB[j] < AB[j + 1])
			{
				tmp = AB[j]->GetMoney();
				tmp1 = AB[j + 1]->GetMoney();
				AB[j]->SetMoney(tmp1);
				AB[j + 1]->SetMoney(tmp);
			}
		}
	}
}

void main()
{
	//Тестування сортування + множинне наслідування
	Amount_Of_Ticket_Service **TS = new Amount_Of_Ticket_Service*[5];
	for (int i(0); i < 5; i++)
	{
		TS[i] = new TicketBusService();
	}
	int Money;
	for (int k(0); k < 5; k++)
	{
		cout << "Enter " << k << " object Total money: ";
		cin >> Money;
		TS[k]->SetMoney(Money);
	}
	Sort_Obj(TS, 5);
	int tmp;
	for (int i(0); i < 5; i++)
	{
		tmp = TS[i]->GetMoney();
		cout << tmp << endl;
	}
	//Тестування конвертування
	TicketBusService A;
	A.InputInfo("Lviv-Paris", 428, 8.00, 20.00);
	A.Sale();
	A.GetAmountOfTicketService();
	string K = A.Obj_To_Str();
	cout << K<< endl;
	A.Str_To_Obj(K);
	A.Print();
}