#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Amount_Of_Ticket_Service.h"
#include "Converting.h"

using namespace std;
class TicketService: public Amount_Of_Ticket_Service
{
protected:
//Вноситься в інформацію про місце продажу квитка
	int SaleNumber;

	//Години роботи
	double StartWorking;
	double EndWorking;


	//Кількість касс
	int AmountOfTicketService = 0;

public:
	TicketService();
	TicketService(double StartWorking_, double EndWorking_, int SaleNumber_);

	//Введення списку рейсів із файлу
	virtual bool CheckTrip(string Trip_) = 0;

	//Введення інформації (всієї)
	virtual void InputInfo(string Trip_, int SaleNumber_, double StartWorking_, double EndWorking) = 0;

	//Обід
	virtual void Dinner() = 0;

	//Продаж з параметрами
	virtual void Sale(string Trip_) = 0;

	//Продаж без параметрів(перевірка чи працює каса)
	virtual void Sale() = 0;

	//Повернення
	virtual void GetBack(int TicketNumber_) = 0;

	//Вивід
	virtual void Print() = 0;

	//Отримати кількість створених кас
	void GetAmountOfTicketService();

	~TicketService();

};

