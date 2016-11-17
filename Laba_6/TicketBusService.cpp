#include "TicketBusService.h"
#define convertToString(x) #x

TicketBusService::TicketBusService() :TicketBusService(0,0,0,0,0,"",0,"")
{
	passanger = "passanger";
	AmountOfTicketService++;
}

TicketBusService::TicketBusService(double StartWorking_, double EndWorking_, int SaleNumber_, int TotalMoney_, int Price_, string Trip_, int AmountOfPaper_, string CurrentTime_):MainTicketService( TotalMoney_, Price_, Trip_, StartWorking_, EndWorking_, SaleNumber_)
{

	int AmountOfPaper = AmountOfPaper_;
	SoldTickets = new int[AmountOfPaper];
	AmountOfRefundable = 0;
	NumberOfRefundable = new int[AmountOfPaper];
	CurrentTime.assign(CurrentTime_);
}

TicketBusService::TicketBusService(const TicketBusService &temp)
{
	SaleNumber = temp.SaleNumber;
	StartWorking = temp.StartWorking;
	EndWorking = temp.EndWorking;
	AmountSoldTickets = temp.AmountSoldTickets;
	TotalMoney = temp.TotalMoney;
	AmountOfPaper = temp.AmountOfPaper;
	if (SoldTickets != NULL)
	{
		for (int i(0); i < AmountOfPaper; i++)
		{
			SoldTickets[i] = temp.SoldTickets[i];
		}
	}
	if (NumberOfRefundable != NULL)
	{
		for (int j(0); j < 20; j++)
		{
			NumberOfRefundable[j] = temp.NumberOfRefundable[j];
		}
	}
	AmountOfRefundable = temp.AmountOfRefundable;
	passanger.assign(temp.passanger);
	CurrentTime.assign(temp.CurrentTime);
}

void TicketBusService::InputInfo(string Trip_, int SaleNumber_, double StartWorking_, double EndWorking_)
{
	Trip.assign(Trip_);
	SaleNumber = SaleNumber_;
	StartWorking = StartWorking_;
	EndWorking = EndWorking_;

	//string ctime = date_time_selling();
	//CurrentTime = ctime;

	cout << "Input Price: ";
	cin >> Price;


	cout << "Input Amount of paper: ";
	cin >> AmountOfPaper;

	cout << "Input Amount of sold tickets: ";
	cin >> AmountSoldTickets;
	SoldTickets = new int [AmountOfPaper];
	for (int i(0); i < AmountSoldTickets; i++)
		{
			cout << "Input Number of " << i << " sold ticket: ";
			cin >> SoldTickets[i];
		}
	TotalMoney = AmountSoldTickets * Price;

	cout << "Input Amount of refundable: ";
	cin >> AmountOfRefundable;
	NumberOfRefundable = new int [AmountOfPaper];
	for (int i(0); i < AmountOfRefundable; i++)
		{
			cout << "Input Number of " << i << " refundable ticket: ";
			cin >> NumberOfRefundable[i];
		}


	char choise;
	cout << "Do you want to enter your name? Y/N: ";
	cin >> choise;
	while (cin.get() != '\n');
	if (choise == 'Y' || choise == 'y')
	{
		cout << "Enter your name: ";
		getline(cin, passanger);
	}
}

bool TicketBusService::CheckTrip(string Trip_)
{
	ifstream Trips("Trips.txt");
	string tmp;
	bool Flag = false;
	while (getline(Trips, tmp))
	{
		if (tmp == Trip_)
			Flag = true;
	}
	tmp.empty();
	return Flag;
}

void TicketBusService::Dinner()
{
	passanger = "Dinner";
}


void TicketBusService::Sale(string Trip_)
{
	if (passanger != "Dinner")
	{
		if (CheckTrip(Trip_))
		{
			if ((TotalMoney + Price) < MaxTotalMoney && AmountOfPaper > 0)
			{
				TotalMoney += Price;
				AmountOfPaper--;
				SoldTickets[AmountSoldTickets] = TicketNumber;
				AmountSoldTickets++;
				Print();
				passanger = "";
			}
			else
			{
				cout << "Sorry, we can't sale you a ticket, try later.\n";
				return;
			}

		}
		else
		{
			cout << "There is no such trip\n";
			return;
		}
	}
	else
	{
		cout << "Sorry, we have a dinner, try later :)\n";
		return;
	}
}

void TicketBusService::Sale()
{
		Sale(Trip);
}

void TicketBusService::Print()
{
	cout << "Congratulations, here is your ticket: \n";
	cout << "------------------------------------------------" << endl;
	cout << "Name: " << passanger << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Trip: " << Trip << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Price: " << Price << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Ticket Number: " << TicketNumber << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Time sold: " << CurrentTime << endl;
}

void PutInFileRefundableTickets(int TicketNumber_)
{
	ofstream FileWrite("Refundable.txt");
	FileWrite << TicketNumber_;
}

void TicketBusService::GetBack(int TicketNumber_)
{
	int temp = AmountSoldTickets;
	for (int i(0); i < temp; )
	{
		if (SoldTickets[temp] == TicketNumber_)
		{
			NumberOfRefundable[AmountOfRefundable] = TicketNumber_;
			AmountOfRefundable++;
			SoldTickets[temp] = NULL;
			for (int j(0); j < (AmountSoldTickets - temp); j++)
			{
				SoldTickets[temp] = SoldTickets[temp++];
				temp++;
			}
			break;
		}
		else
		{
			temp--;
		}
	}
	TotalMoney -= Price;
	AmountSoldTickets--;
	AmountOfPaper++;
}

string TicketBusService::Obj_To_Str()
{
	string Object = "";
	string tmp = " ";
	
	string tmp1 = to_string(SaleNumber);
	Object += tmp1 + tmp;
	
	tmp1 = to_string(StartWorking);
	Object += tmp1 + tmp;
	
	tmp1 = to_string(EndWorking);
	Object += tmp1 + tmp;

	tmp1 = to_string(AmountSoldTickets);
	Object += tmp1 + tmp;

	tmp1 = to_string(TotalMoney);
	Object += tmp1 + tmp;

	tmp1 = to_string(AmountOfPaper);
	Object += tmp1 + tmp;

	if (SoldTickets != NULL)
	{
		for (int i(0); i < AmountSoldTickets; i++)
		{
			tmp1 = to_string(SoldTickets[i]);
			Object += tmp1 + tmp;
		}
	}
	if (NumberOfRefundable != NULL)
	{
		for (int j(0); j < AmountOfRefundable; j++)
		{
			tmp1 = to_string(NumberOfRefundable[j]);
			Object += tmp1 + tmp;
		}
	}
	tmp1 = to_string(AmountOfRefundable);
	Object += tmp1 + tmp;

	tmp1 = CurrentTime;
	Object += tmp1;
	return Object;
}

void TicketBusService::Str_To_Obj(string Obj_)
{
	int amount = 0;
	int pos = -1;
	while ((pos = Obj_.find(" ", pos + 1)) != -1)
	{

		++amount;
	}
	string *arr = new string[amount + 1];
	int i = 0;
	pos = -1;
	while ((pos = Obj_.find(" ", pos + 1)) != string::npos)
	{
		arr[i] = Obj_.substr(0, pos);
		Obj_.erase(0, pos + 1);
		++i;
		pos = -1;
	}
	int amoutsold = amount - 7;
	int counter = 0;
	arr[i] = Obj_;
	SaleNumber = stoi(arr[1]);
	StartWorking = stoi(arr[2]);
	EndWorking = stoi(arr[3]);
	AmountSoldTickets = stoi(arr[4]);
	TotalMoney = stoi(arr[5]);
	AmountOfPaper = stoi(arr[6]);
	for (int j(1); j <= amoutsold; j++)
	{
		SoldTickets[counter] = stoi(arr[6 + j]);
		counter++;
	}
	AmountOfRefundable = stoi(arr[amount]);
	CurrentTime = arr[i];
}

bool operator>(TicketBusService& tmp1, TicketBusService& tmp2)
{
	if (tmp1.TotalMoney > tmp2.TotalMoney)
		return true;
	else
		return false;
}

bool operator==(TicketBusService& tmp1, TicketBusService& tmp2)
{
	if (tmp1.TotalMoney == tmp2.TotalMoney)
		return true;
	else
		return false;
}

bool operator<(TicketBusService& tmp1, TicketBusService& tmp2)
{
	if (tmp1.TotalMoney < tmp2.TotalMoney)
		return true;
	else
		return false;
}

int TicketBusService::GetMoney()
{
	return TotalMoney;
}

void TicketBusService::SetMoney(int a)
{
	TotalMoney = a;
}

TicketBusService::~TicketBusService()
{
	if (SoldTickets != NULL)
	{
		delete[] SoldTickets;
	}
	if (NumberOfRefundable != NULL)
	{
		delete[] NumberOfRefundable;
	}
	cout << "Deleted ticket bus service" << endl;
}