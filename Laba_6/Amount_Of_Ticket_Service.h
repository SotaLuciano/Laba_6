#pragma once

using namespace std;

class Amount_Of_Ticket_Service
{
public:
	virtual void GetAmountOfTicketService() = 0;
	virtual int GetMoney() = 0;
	virtual void SetMoney(int a) = 0;
};

