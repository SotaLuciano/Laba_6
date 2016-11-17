#pragma once
#pragma warning(disable: 4996)
#include "MainTicketService.h"
#include <ctime>

using namespace std;

class TicketBusService : public MainTicketService, public Converting
{

private:	
	// ʳ������ ������
	int AmountOfPaper;
	
	//����� �������� ������
	int *SoldTickets;
	
	//ʳ������ �������� ������
	int AmountSoldTickets;

	//����� ������ ���������� ������
	int *NumberOfRefundable;
	
	//ʳ������ ���������� ������
	int AmountOfRefundable;
	
	//�������� ���
	string CurrentTime;


protected:
	//����� ������
	int TicketNumber;
public:
	//�������
	string passanger;

	//����������� ��� ���������
	TicketBusService();

	//����������� � �����������
	TicketBusService(double StartWorking_, double EndWorking_, int SaleNumber_, int TotalMoney_, int Price_, string Trip_, int AmountOfPaper_, string CurrentTime_);

	//����������� ���������
	TicketBusService(const TicketBusService &temp);

	//�������� ������ ����� �� �����
	virtual bool CheckTrip(string Trip_);

	//�������� ���������� (�񳺿)
	virtual void InputInfo(string Trip_, int SaleNumber_, double StartWorking_, double EndWorking);

	//���
	virtual void Dinner();

	//������ � �����������
	virtual void Sale(string Trip_);

	//������ ��� ���������(�������� �� ������ ����)
	virtual void Sale();

	//����������
	virtual void GetBack(int TicketNumber_);

	//����
	virtual void Print();
	
	//��� � ����
	void SetCurrentTime(string time)
	{
		CurrentTime.assign(time);
	}
	
	//�������������� ��������� ���������
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

	//��'��� � ������
	string Obj_To_Str();

	//������ � ��'���
	void Str_To_Obj(string Obj_);

	~TicketBusService();
};

