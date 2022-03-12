/* SeibertProj5.cpp
   Levi Seibert
   00086809
   lseiber1@my.athens.edu

   This program creates a "Monaco" style movie theater that allows the user to order tickets for a specific showing of a movie. */


#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

//global variables
const int ROWS = 7;
const int COLS = 10;
const int MOVIE1 = 1;
const int MOVIE2 = 2;
const int MOVIE3 = 3;
const int MOVIE4 = 4;
const int MOVIE5 = 5;
const int TIME1 = 1;
const int TIME2 = 2;
const int TIME3 = 3;
const int TIME4 = 4;
const int ADMIN = -99;
const int SOLD_OUT = 52;
const double MATINEE = 9.00;
const double EVENING = 12.00;

//function prototypes
void orderTickets(char[][COLS], int, double, double &, int &, int &, int &, double &, double &);
void displaySeats(const char[][COLS], int);
void chooseSeats(char[][COLS], int, int, double, double &, double &, double &);
bool soldOut(char[][COLS], int);
void administrator(char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], 
	char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], 
	char[][COLS], char[][COLS], char[][COLS], char[][COLS], char[][COLS], int, double, int, int, int, double, double);

int main()
{
	double total = 0.0, matineeTotal = 0.0, eveningTotal = 0.0;
	int totalTickets = 0, matineeTickets = 0, eveningTickets = 0;
	int movieChoice, timeChoice;
	bool stop = false;

	//initialize arrays
	char ford1[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char ford2[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char ford3[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char ford4[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
							   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char charlies1[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char charlies2[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char charlies3[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char charlies4[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								   {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char doctor1[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char doctor2[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								 {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char christmas1[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char christmas2[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char christmas3[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char christmas4[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
									{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char playing1[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char playing2[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char playing3[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	char playing4[ROWS][COLS] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
								  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

	//display menu
	do
	{
		cout << "Please select a movie (1-5): " << endl
			<< endl << "Matinee (12:45-4:05) price: $9.00       Evening (6:45-9:35) price: $12.00" << endl << endl
			<< "1. Ford Vs. Ferrari   PG13  2D		Times: 12:45, 3:45, 6:45, 9:35" << endl
			<< "2. Charlies Angels    PG13  2D		Times: 1:25, 4:05, 6:55, 9:25" << endl
			<< "3. Doctor Sleep       R     2D	        Times: 3:55, 7:00" << endl
			<< "4. Last Christmas     PG13  2D		Times: 1:20, 3:50, 7:05, 9:25" << endl
			<< "5. Playing with Fire  PG    2D          Times: 1:20, 4:00, 6:50, 9:20" << endl;
		cin >> movieChoice;

		//admin mode
		if (movieChoice == ADMIN)
		{
			administrator(ford1, ford2, ford3, ford4, charlies1, charlies2, charlies3, charlies4, 
				doctor1, doctor2, christmas1, christmas2, christmas3, christmas4, playing1, playing2, 
				playing3, playing4, ROWS, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
		}

		//input validation
		while (((movieChoice < 1) && (movieChoice!= -99)) || (movieChoice > 5))
		{
			cout << "Invalid choice.  Please try again: ";
			cin >> movieChoice;
		}

		//decide action
		switch (movieChoice)
		{
		case MOVIE1:
			cout << endl << "What time (1-4)? 1. 12:45, 2. 3:45, 3. 6:45, 4. 9:35" << endl;
			cin >> timeChoice;

			while ((timeChoice < 1) || (timeChoice > 4))
			{
				cout << "Invalid choice.  Please try again: ";
				cin >> timeChoice;
			}

			switch (timeChoice)
			{
			case TIME1:
				orderTickets(ford1, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME2:
				orderTickets(ford2, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME3:
				orderTickets(ford3, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME4:
				orderTickets(ford4, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			}
			break;

		case MOVIE2:
			cout << endl << "What time (1-4)? 1. 1:25, 2. 4:05, 3. 6:55, 4. 9:25" << endl;
			cin >> timeChoice;

			while ((timeChoice < 1) || (timeChoice > 4))
			{
				cout << "Invalid choice.  Please try again: ";
				cin >> timeChoice;
			}

			switch (timeChoice)
			{
			case TIME1:
				orderTickets(charlies1, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME2:
				orderTickets(charlies2, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME3:
				orderTickets(charlies3, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME4:
				orderTickets(charlies4, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			}
			break;

		case MOVIE3:
			cout << endl << "What time (1-2)? 1. 3:55, 2. 7:00" << endl;
			cin >> timeChoice;

			while ((timeChoice < 1) || (timeChoice > 2))
			{
				cout << "Invalid choice.  Please try again: ";
				cin >> timeChoice;
			}

			switch (timeChoice)
			{
			case TIME1:
				orderTickets(doctor1, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME2:
				orderTickets(doctor2, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			}
			break;

		case MOVIE4:
			cout << endl << "What time (1-4)? 1. 1:20, 2. 3:50, 3. 7:05, 4. 9:25" << endl;
			cin >> timeChoice;

			while ((timeChoice < 1) || (timeChoice > 4))
			{
				cout << "Invalid choice.  Please try again: ";
				cin >> timeChoice;
			}

			switch (timeChoice)
			{
			case TIME1:
				orderTickets(christmas1, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME2:
				orderTickets(christmas2, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME3:
				orderTickets(christmas3, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME4:
				orderTickets(christmas4, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			}
			break;

		case MOVIE5:
			cout << endl << "What time (1-4)? 1. 1:20, 2. 4:00, 3. 6:50, 4. 9:20" << endl;
			cin >> timeChoice;

			while ((timeChoice < 1) || (timeChoice > 4))
			{
				cout << "Invalid choice.  Please try again: ";
				cin >> timeChoice;
			}

			switch (timeChoice)
			{
			case TIME1:
				orderTickets(playing1, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME2:
				orderTickets(playing2, ROWS, MATINEE, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME3:
				orderTickets(playing3, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			case TIME4:
				orderTickets(playing4, ROWS, EVENING, total, totalTickets, matineeTickets, eveningTickets, matineeTotal, eveningTotal);
				break;
			}
			break;
		}

		cout << endl;

	} while (!stop);
	return 0;
}

//******************************************************************
// The orderTickets() function allows the user to order a specific *
// number of tickets as long as the showing has not sold out.      *
//******************************************************************
void orderTickets(char seats[][COLS], int ROWS, double time, double &total, int &totalTickets, int &matineeTickets, int &eveningTickets, double &matineeTotal, double &eveningTotal)
{
	int numTickets;

	if (!soldOut(seats, ROWS))
	{
		cout << "How many tickets do you want? ";
		cin >> numTickets;

		while (numTickets < 0)
		{
			"Invalid number of tickets.  Please try again: ";
			cin >> numTickets;
		}

		totalTickets += numTickets;

		if (time == MATINEE)
		{
			matineeTickets += numTickets;
		}

		else if (time == EVENING)
		{
			eveningTickets += numTickets;
		}

		displaySeats(seats, ROWS);
		chooseSeats(seats, ROWS, numTickets, time, total, matineeTotal, eveningTotal);
	}

	else
	{
		cout << "Sorry!  This showing has sold out." << endl;
	}

}

//**********************************************
// The displaySeats() function displays        *
// the seating chart for the selected showing. *
//**********************************************
void displaySeats(const char seats[][COLS], int ROWS)
{
	cout << endl << setw(28) << "1 2 3 4 5 6 7 8 9 10" << endl;
	for (int count = 0; count < ROWS; count++)
	{
		cout << "Row " << (count + 1) << "\t";
		for (int index = 0; index < COLS; index++)
		{
			cout << seats[count][index] << " ";
		}
		cout << endl;
	}
}

//*********************************************
// The chooseSeats() function allows the      *
// user to choose their seat(s) for the show. *
//*********************************************
void chooseSeats(char seats[][COLS], int ROWS, int tickets, double time, double &total, double &matineeTotal, double &eveningTotal)
{
	int ticketRow, ticketColumn;
	double ticketPrice;
	char choice;

	cout << endl << "Enter the row number (1-7) and the column number (1-10), separated by a space for each ticket: " << endl;
	for (int count = 1; count <= tickets; count++)
	{
		cout << "Ticket " << count << ": ";
		cin >> ticketRow >> ticketColumn;

		//input validation
		while ((ticketRow < 1) || (ticketRow > 7) || (ticketColumn < 1) || (ticketColumn > 10))
		{
			cout << "Invalid seat selection.  Please try again: ";
			cin >> ticketRow >> ticketColumn;
		}

		seats[(ticketRow - 1)][(ticketColumn - 1)] = '*';
		displaySeats(seats, ROWS);
	}

	ticketPrice = time * tickets;
	cout << "Show total: $" << showpoint << fixed << setprecision(2) << ticketPrice << endl;

	if (time == MATINEE)
	{
		matineeTotal += ticketPrice;
	}

	else if (time == EVENING)
	{
		eveningTotal += ticketPrice;
	}

	//calculates total sales
	total += ticketPrice;
	cout << "Would you like to see the total of all ticket sales? (Y/N) ";
	cin >> choice;

	if ((choice == 'y') || (choice == 'Y'))
	{
		cout << "Grand total: $" << total << endl;
	}

}

//*************************************
// The soldOut() function checks if   *
// the selected showing has sold out. *
//*************************************
bool soldOut(char seats[][COLS], int ROWS)
{
	int sold = 0;

	for (int count = 0; count < ROWS; count++)
	{
		for (int index = 0; index < COLS; index++)
			if (seats[count][index] == '*')
			{
				sold += 1;
			}
	}

	if (sold >= SOLD_OUT)
	{
		return true;
	}

	return false;
}

//*************************************************************
// The administrator() function allows the admin to           *
//view number of tickets, ticket profits, and sold-out shows. *  
// It then allows the admin to quit the program.              *
//*************************************************************
void administrator(char ford1[][COLS], char ford2[][COLS], char ford3[][COLS], char ford4[][COLS], char charlies1[][COLS],
	char charlies2[][COLS], char charlies3[][COLS], char charlies4[][COLS], char doctor1[][COLS], char doctor2[][COLS],
	char christmas1[][COLS], char christmas2[][COLS], char christmas3[][COLS], char christmas4[][COLS], char playing1[][COLS],
	char playing2[][COLS], char playing3[][COLS], char playing4[][COLS], int ROWS, double total, int totalTickets, int matineeTickets,
	int eveningTickets, double matineeTotal, double eveningTotal)
{
	char viewSold, leaveChoice;
	int ticketChoice, totalChoice = 0;
	cout << "Entering Admin Mode" << endl;

	//display number of tickets
	cout << endl << "Would you like to see the number of tickets by 1. type or 2. total: ";
	cin >> ticketChoice;

	while ((ticketChoice != 1) && (ticketChoice != 2))
	{
		cout << "Invalid selection.  Please try again: ";
		cin >> ticketChoice;
	}

	if (ticketChoice == 1)
	{
		cout << "Total Matinee tickets: " << matineeTickets << endl;
		cout << "Total Evening tickets: " << eveningTickets << endl;
	}

	else if (ticketChoice == 2)
	{
		cout << "Total tickets sold: " << totalTickets << endl;
	}

	//display ticket sales
	cout << endl << "Would you like to see the ticket sales 1. by type or 2. total: ";
	cin >> totalChoice;

	while ((totalChoice != 1) && (totalChoice != 2))
	{
		cout << "Invalid selection.  Please try again: ";
		cin >> totalChoice;
	}

	if (totalChoice == 1)
	{
		cout << setprecision(2) << fixed << showpoint << "Total Matinee sales: $" << matineeTotal << endl;
		cout << "Total Evening sales: $" << eveningTotal << endl;
	}

	else if (totalChoice == 2)
	{
		cout << setprecision(2) << fixed << showpoint << "Total ticket sales: $" << total << endl;
	}

	cout << endl << "Would you like to see which shows are sold out? (Y/N) ";
	cin >> viewSold;

	//find which shows are sold out
	if (viewSold == 'y' || viewSold == 'Y')
	{
		if (soldOut(ford1, ROWS))
		{
			cout << "Ford vs. Ferrari - 12:45" << endl;
		}

		if (soldOut(ford2, ROWS))
		{
			cout << "Ford vs. Ferrari - 3:45" << endl;
		}

		if (soldOut(ford3, ROWS))
		{
			cout << "Ford vs. Ferrari - 6:45" << endl;
		}

		if (soldOut(ford4, ROWS))
		{
			cout << "Ford vs. Ferrari - 9:35" << endl;
		}

		if (soldOut(charlies1, ROWS))
		{
			cout << "Charlies Angels - 1:25" << endl;
		}

		if (soldOut(charlies2, ROWS))
		{
			cout << "Charlies Angels - 4:05" << endl;
		}

		if (soldOut(charlies3, ROWS))
		{
			cout << "Charlies Angels - 6:55" << endl;
		}

		if (soldOut(charlies4, ROWS))
		{
			cout << "Charlies Angels - 9:25" << endl;
		}

		if (soldOut(doctor1, ROWS))
		{
			cout << "Doctor's Sleep - 3:55" << endl;
		}

		if (soldOut(doctor2, ROWS))
		{
			cout << "Doctor's Sleep - 7:00" << endl;
		}

		if (soldOut(christmas1, ROWS))
		{
			cout << "Last Christmas - 1:20" << endl;
		}

		if (soldOut(christmas2, ROWS))
		{
			cout << "Last Christmas - 3:50" << endl;
		}

		if (soldOut(christmas3, ROWS))
		{
			cout << "Last Christmas - 7:05" << endl;
		}

		if (soldOut(christmas4, ROWS))
		{
			cout << "Last Christmas - 9:25" << endl;
		}

		if (soldOut(playing1, ROWS))
		{
			cout << "Playing with Fire - 1:20" << endl;
		}

		if (soldOut(playing2, ROWS))
		{
			cout << "Playing with Fire - 4:00" << endl;
		}

		if (soldOut(playing3, ROWS))
		{
			cout << "Playing with Fire - 6:50" << endl;
		}

		if (soldOut(playing4, ROWS))
		{
			cout << "Playing with Fire - 9:20" << endl;
		}
	}

	//exit operation
	cout << endl << "Would you like to return to the menu (M) or exit (E)? ";
	cin >> leaveChoice;

	if (leaveChoice == 'e' || leaveChoice == 'E')
	{
		cout << "Exiting program!";
		exit(0);
	}
}