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
//��������� � ���������� ��� ���� ������� ������
	int SaleNumber;

	//������ ������
	double StartWorking;
	double EndWorking;


	//ʳ������ ����
	int AmountOfTicketService = 0;

public:
	TicketService();
	TicketService(double StartWorking_, double EndWorking_, int SaleNumber_);

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

	//�������� ������� ��������� ���
	void GetAmountOfTicketService();

	~TicketService();

};

