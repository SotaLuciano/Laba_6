#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "TicketService.h"

class MainTicketService : public TicketService
{
protected:
	//Сума виручки
	int TotalMoney;

	//Ціна
	int Price = 100;

	// Гранична допустима сума виручки
	const int MaxTotalMoney = 1000000;

	//Рейс
	string Trip;

public:
	MainTicketService();
	MainTicketService(int TotalMoney_, int Price_, string Trip_, double StartWorking_, double EndWorking_, int SaleNumber_);

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

	~MainTicketService();
};

