#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "TicketService.h"

class MainTicketService : public TicketService
{
protected:
	//���� �������
	int TotalMoney;

	//ֳ��
	int Price = 100;

	// �������� ��������� ���� �������
	const int MaxTotalMoney = 1000000;

	//����
	string Trip;

public:
	MainTicketService();
	MainTicketService(int TotalMoney_, int Price_, string Trip_, double StartWorking_, double EndWorking_, int SaleNumber_);

	//�������� ������ ����� �� �����
	virtual bool CheckTrip(string Trip_) = 0;

	//�������� ���������� (�񳺿)
	virtual void InputInfo(string Trip_, int SaleNumber_, double StartWorking_, double EndWorking) = 0;

	//���
	virtual void Dinner() = 0;

	//������ � �����������
	virtual void Sale(string Trip_) = 0;

	//������ ��� ���������(�������� �� ������ ����)
	virtual void Sale() = 0;

	//����������
	virtual void GetBack(int TicketNumber_) = 0;

	//����
	virtual void Print() = 0;

	~MainTicketService();
};

