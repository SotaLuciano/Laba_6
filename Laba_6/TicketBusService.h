#pragma once
#pragma warning(disable: 4996)
#include "MainTicketService.h"
#include <ctime>

using namespace std;

class TicketBusService : public MainTicketService, public Converting
{

private:	
	// Кількість паперу
	int AmountOfPaper;
	
	//Масив проданих квитків
	int *SoldTickets;
	
	//Кількість проданих квитків
	int AmountSoldTickets;

	//Масив номерів повернених квитків
	int *NumberOfRefundable;
	
	//Кількість повернених квитків
	int AmountOfRefundable;
	
	//Поточний час
	string CurrentTime;


protected:
	//Номер квитка
	int TicketNumber;
public:
	//Пасажир
	string passanger;

	//Конструктор без параметрів
	TicketBusService();

	//Конструктор з параметрами
	TicketBusService(double StartWorking_, double EndWorking_, int SaleNumber_, int TotalMoney_, int Price_, string Trip_, int AmountOfPaper_, string CurrentTime_);

	//Конструктор копіювання
	TicketBusService(const TicketBusService &temp);

	//Введення списку рейсів із файлу
	virtual bool CheckTrip(string Trip_);

	//Введення інформації (всієї)
	virtual void InputInfo(string Trip_, int SaleNumber_, double StartWorking_, double EndWorking);

	//Обід
	virtual void Dinner();

	//Продаж з параметрами
	virtual void Sale(string Trip_);

	//Продаж без параметрів(перевірка чи працює каса)
	virtual void Sale();

	//Повернення
	virtual void GetBack(int TicketNumber_);

	//Вивід
	virtual void Print();
	
	//Час і дата
	void SetCurrentTime(string time)
	{
		CurrentTime.assign(time);
	}
	
	//Перевантаження операторів порівняння
	friend bool operator>(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator==(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator<(TicketBusService& tmp1, TicketBusService& tmp2);

	TicketBusService& operator=(const TicketBusService& temp)
	{
		SaleNumber = temp.SaleNumber;
		StartWorking = temp.StartWorking;
		EndWorking = temp.EndWorking;
		AmountSoldTickets = temp.AmountSoldTickets;
		TotalMoney = temp.TotalMoney;
		AmountOfPaper = temp.AmountOfPaper;
		//if (SoldTickets != NULL)
		//{
		//	for (int i(0); i < AmountOfPaper; i++)
		//	{
		//		SoldTickets[i] = temp.SoldTickets[i];
		//	}
		//}
		//if (NumberOfRefundable != NULL)
		//{
		//	for (int j(0); j < 20; j++)
		//	{
		//		NumberOfRefundable[j] = temp.NumberOfRefundable[j];
		//	}
		//}
		AmountOfRefundable = temp.AmountOfRefundable;
		passanger.assign(temp.passanger);
		CurrentTime.assign(temp.CurrentTime);
		Trip.assign(temp.Trip);
		Price = temp.Price;
		return *this;
	}

	//Get/Set Total Money
	int GetMoney();
	void SetMoney(int a);

	//Об'єкт у стрічку
	string Obj_To_Str();

	//Стрічку в об'єкт
	void Str_To_Obj(string Obj_);

	~TicketBusService();
};

