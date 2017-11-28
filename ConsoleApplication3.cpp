// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int ROW_WIDTH = 30;
const int COLUMN_HEIGHT = 15;
double prices[COLUMN_HEIGHT];
int ticketsSold = 0;
double profits = 0;
char seats[ROW_WIDTH][COLUMN_HEIGHT];




bool isSeatTaken(int x, int y); 
void setupPrice();
void displaySeats();  
void buySeat(); 
void refundSeat(); 
int EmptySeatsInRow(int y); 
void displaySales(); 




int main(int i)
{
	setupPrice(); 
	for (int x = 0; x < ROW_WIDTH; x++){
		for (int y = 0; y < COLUMN_HEIGHT; y++){
			seats [x][y]=  '*'; 
		}
	}

	while (true)
	{
		int userChoice; 
		cout << "Please enter your choice below" << endl; 
		cout << "Enter 1 to see empty seats" << endl;
		cout << "Enter 2 to purchase a seat" << endl;
		cout << "Enter 3 to refund a seat" << endl;
		cout << "Enter 4 to view tickets sold and profits" << endl; 
		cout << "Enter 0 to close program" << endl;
		cin >> userChoice; 
		switch (userChoice)
		{
		case 0: 
			return(0); 
		case 1:
			displaySeats(); 
			break; 
		case 2: 
			buySeat(); 
			break; 
		case 3:
			refundSeat(); 
			break;
		case 4:
			displaySales(); 
			break; 
		}
				
	} 
	return 0;
}
void displaySales() {
	 cout << "tickets sold : " << ticketsSold << endl;
	cout << "total profit : $" << profits << endl; 

}


int EmptySeatsInRow(int y)
{
	int emptySeats = 0;
	for (int x = 0; x < ROW_WIDTH; x++) {
		if (seats[x][y] == '*') emptySeats++;



	}

	return emptySeats;


}
int EmptySeatsInTheater() {
	int emptySeats = 0;
	for (int y = 0; y < COLUMN_HEIGHT; y++) {
		emptySeats = emptySeats + EmptySeatsInRow(y);

	}
	return emptySeats;

}

void displaySeats()
{
	cout << "Seats:1    2    3    4    5    6    7    8    9    10   11   12   13   14   15" << endl;
	for (int x = 0; x < ROW_WIDTH; x++)
	{
		if (x<9)
		{
			cout << " ";
		}
		cout << x + 1;
		for (int y = 0; y < COLUMN_HEIGHT; y++)
		{
			cout << "    " << seats[x][y];
		}
		cout << endl;
	}
}

bool checkSeatTaken(int x, int y)
{
	return true;
}

void setupPrice()
{
	for (int i = 0; i < COLUMN_HEIGHT; i++)
	{
		prices[i] = 8 + i;
	}
}

double getPrice(int y)
{
	return prices[y];
}

bool checkSeatTaken()
{
	int x;
	int y;

	cout << "Please Enter Row Number\n";
	cin >> y;
	cout << "Please Enter Seat Number\n";
	cin >> x;

	return isSeatTaken(x, y);
}

bool isSeatTaken(int x, int y) {

	return (seats[x][y] == '#');
}

void buySeat()
{
	int x = 0;
	int y = 0;
	while (x < 1 || x > 30)
	{
		cout << "Please Enter Row Number from 1-30 \n";
		cin >> x;
	}
	while ( y < 1 || y > 15) 
	{
		cout << "Please Enter Seat Number from 1-15 \n";
		cin >> y;
	}
	y = y - 1;
	x = x - 1;

	if (isSeatTaken(x, y))
	{
		cout << "Seat is Taken \n";
	}
	else
	{
		char choice;
		double seatPrice = getPrice(y);
		cout << "The ticket costs  $" << seatPrice << endl;
		cout << "Do you want to buy the seat y" << endl;
		cin >> choice;
		cout << endl; 
		if (choice == 'y') 
		{
			ticketsSold = ticketsSold + 1;
			profits = profits + seatPrice;
			seats[x][y] = '#';
			cout << "Transaction Successful" << endl; 

		}

	}


}

void refundSeat()
{
	int x = 0;
	int y = 0;
	while (x < 1 || x > 30)
	{
		cout << "Please Enter Row Number from 1-30 \n";
		cin >> x;
	}
	while ( y < 1 || y > 15) 
	{
		cout << "Please Enter Seat Number from 1-15 \n";
		cin >> y;
	}

	x = x -  1;
	y = y - 1;
	if (!isSeatTaken(x, y))
	{
		cout << "Cannot Refund Seat is Empty \n";
	}
	else
	{
		char choice;
		double seatPrice = getPrice(y);
		cout << "The ticket costs $" << seatPrice << endl;
		cout << " Do you want to refund the seat y\n" << endl;
		cin >> choice;
		cout << endl; 
		if (choice == 'y')
		{
			ticketsSold = ticketsSold - 1;
			profits = profits - seatPrice;
			seats[x][y] = '*';
			cout << "Refund Successful" << endl; 
		}

	}

}
