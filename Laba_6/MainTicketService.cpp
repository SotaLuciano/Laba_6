#include "MainTicketService.h"



MainTicketService::MainTicketService():MainTicketService(0,0,"",0,0,0)
{
}


MainTicketService::MainTicketService(int TotalMoney_, int Price_, string Trip_, double StartWorking_, double EndWorking_, int SaleNumber_) :TicketService(StartWorking_, EndWorking_,SaleNumber_)
{
	TotalMoney = TotalMoney_;
	Price = Price_;
	Trip.assign(Trip_);
}


MainTicketService::~MainTicketService()
{
	cout << "Deleted Main Ticket Service" << endl;
}
