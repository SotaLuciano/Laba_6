#pragma once
#include "MainTicketService.h"
#include "Converting.h"

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
	double CurrentTime;


protected:
	//����� ������
	int TicketNumber;
public:
	//�������
	string passanger;

	//����������� ��� ���������
	TicketBusService();

	//����������� � �����������
	TicketBusService::TicketBusService(double StartWorking_, double EndWorking_, int SaleNumber_, int TotalMoney_, int Price_, string Trip_, int AmountOfPaper_, double CurrentTime_);

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

	//�������������� ��������� ���������
	friend bool operator>(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator==(TicketBusService& tmp1, TicketBusService& tmp2);
	friend bool operator<(TicketBusService& tmp1, TicketBusService& tmp2);

	//Get/Set Total Money
	int GetMoney();
	void SetMoney(int a);

	//��'��� � ������
	string Obj_To_Str();

	//������ � ��'���
	void Str_To_Obj(string Obj_);

	~TicketBusService();
};

