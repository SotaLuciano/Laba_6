#include "TicketService.h"

TicketService::TicketService()
{
	SaleNumber = 0;
	StartWorking = 0;
	EndWorking = 0;
}

TicketService::TicketService(double StartWorking_, double EndWorking_, int SaleNumber_)
{
	SaleNumber = SaleNumber_;
	StartWorking = StartWorking_;
	EndWorking = EndWorking_;
}

void TicketService::GetAmountOfTicketService()
{
	cout << "Amount Of Ticket Service: " << AmountOfTicketService << endl;
}

TicketService::~TicketService()
{
	cout << "Deleted Ticket Service" << endl;
}