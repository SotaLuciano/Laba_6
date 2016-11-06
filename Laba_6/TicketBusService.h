#pragma once
#include "MainTicketService.h"
#include "Converting.h"

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
	double CurrentTime;


protected:
	//Номер квитка
	int TicketNumber;
public:
	//Пасажир
	string passanger;

	//Конструктор без параметрів
	TicketBusService();

	//Конструктор з параметрами
	TicketBusService::TicketBusService(double StartWorking_, double EndWorking_, int SaleNumber_, int TotalMoney_, int Price_, string Trip_, int AmountOfPaper_, double CurrentTime_);

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

	//Перевантаження операторів порівняння
	friend bool operator>(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator==(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator<(TicketBusService& tmp1, TicketBusService& tmp2);

	//Get/Set Total Money
	int GetMoney();
	void SetMoney(int a);

	//Об'єкт у стрічку
	string Obj_To_Str();

	//Стрічку в об'єкт
	void Str_To_Obj(string Obj_);

	~TicketBusService();
};

