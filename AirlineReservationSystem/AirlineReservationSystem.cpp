// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "AirlineDB.h"

using namespace AirlineReservationSystem;
using namespace std;

const int NUM_ROWS = 60; // number of rows of seats in an airline
const int NUM_COLS = 5; // number of seats in each row.
const char EMPTY = '#'; // display symbol for empty seat.
const char TAKEN = '*'; // display sysmbol for taken seat.

int displayAirlineSchedule();
int displayMenu();
void displaySeatingChart(char seats[NUM_ROWS + 1][NUM_COLS + 1]);
bool isValid(int row, int seat);// is the seat at(row, seat) empty?
void doReserve(AirlineDB& db);
void doCancel(AirlineDB& db);
void displayAirline(AirlineDB& db);
void doReservedFirstClass(AirlineDB& db);
void doReservedEconomyClass(AirlineDB& db);

int main()
{
	AirlineDB airlineReservationDB;	

	while (true) 

	break;
		{
		int selection = displayMenu();
		switch (selection) {
		case 0: //EXIT
			return 0;
		case 1:
			doReserve(airlineReservationDB);

			break;
		case 2:
			airlineReservationDB.displayAll();
			break;
		case 3:
			/*airlineReservationDB.displayAirlineSchedule();*/
			displayAirlineSchedule();
			break;
		case 4:
			//VIEW AND PRINT TICKET
			break;
		case 5:
			//VIEW FLIGHT DETAILS
			break;
		case 6:
			airlineReservationDB.displayPassengerInfo();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayAirlineSchedule()
{
	int availableAirlines;

	cout << endl;
	cout << "Available Airline schedules" << endl;
	cout << "===================================================================================================" << endl;
	cout << "Airline " << setw(10) << "Departure " << setw(10) << "DepartureDate " << setw(10) << "DepartureTime " << setw(10)
		<< "Arrival " << setw(10) << "ArrivalDate " << setw(10) << "ArrivalTime " << setw(10) << endl;
	cout << "====================================================================================================" << endl;
	cout << "1. Alaska" << setw(12) << "Seattle " << setw(10) << "09/20/2018 " << setw(10) << "11 AM " << setw(15)
		<< "Phoenix " << setw(16) << "09/20/2018 " << setw(10) << "8 PM " << endl;
	cout << "2. United" << setw(12) << "Detroit " << setw(10) << "09/20/2018 " << setw(10) << "10 AM " << setw(15)
		<< "Phoenix " << setw(16) << "09/20/2018 " << setw(10) << "6 PM " << endl;
	cout << "3. Spirit" << setw(12) << "Seattle " << setw(10) << "09/20/2018 " << setw(10) << "9 AM " << setw(15)
		<< "Chicago " << setw(16) << "09/20/2018 " << setw(10) << "8 PM " << endl;
	cout << "4. Delta" << setw(13) << "Chicago " << setw(10) << "09/20/2018 " << setw(10) << "11 AM " << setw(15)
		<< "Phoenix " << setw(16) << "09/20/2018 " << setw(10) << "5 PM " << endl;
	cout << "5. American" << setw(10) << "Houston " << setw(10) << "09/20/2018 " << setw(10) << "10 AM " << setw(15)
		<< "Seattle " << setw(16) << "09/20/2018 " << setw(10) << "8 PM " << endl;
	cout << "6. JetBlue" << setw(11) << "Seattle " << setw(10) << "09/20/2018 " << setw(10) << "9 AM " << setw(20)
		<< "Indianapolis " << setw(12) << "09/20/2018 " << setw(10) << "10 PM " << setw(10) << endl;
	cout << "Which Airline would You like for your travel? " << endl;
	cin >> availableAirlines;

	return availableAirlines;
}

void displaySeatingChart(char seats[NUM_ROWS + 1][NUM_COLS + 1]) {
	cout << "\tSeats" << endl;
	cout << "\t"
		<< setw(2) << 'L'
		<< setw(1) << 'S'
		<< setw(3) << 'R' << endl;
	cout << "\t";
	for (size_t i{ 1 }; i <= NUM_COLS; ++i) {
		cout << i % 5;
	}
	cout << endl;

	for (size_t i{ 1 }; i <= NUM_ROWS; ++i) {
		cout << "Row " << i << "\t";
		for (size_t j{ 1 }; j <= NUM_COLS; ++j) {
			cout << seats[i][j];
		}
		cout << endl;

	}
}

bool isValid(int row, int seat) {
	return 1 <= row && row <= NUM_ROWS
		&& 1 <= seat && seat <= NUM_COLS;
}

int displayMenu()
{
	int selection;
	
		cout << endl;
		cout << "Airline Reservation System" << endl;
		cout << "___________________________" << endl;
		cout << "1. Book A Flight" << endl;
		cout << "2. View Booking Information" << endl;
		cout << "3. View Flight Schedule" << endl;
		cout << "4. View and Print Ticket" << endl;
		cout << "5. View Flight Details" << endl;
		cout << "6. View Passenger Info" << endl;
		cout << "0. Exit" << endl;
		cout << "____________________________" << endl;
		cin >> selection;

		return selection;
	
}

void doReserve(AirlineDB& db) {
	
	vector<int> rowsWanted;
	vector<int> seatsWanted;
	string firstName;
	string lastName;
	string dateOfBirth;
	string passportNo;
	string gender;
	string nationality;

	bool isValid(int row, int seat);// is the seat at(row, seat) empty?
	char seats[NUM_ROWS + 1][NUM_COLS + 1];
	for (size_t row{ 1 }; row < NUM_ROWS + 1; ++row) {
		for (size_t col{ 1 }; col < NUM_COLS + 1; ++col) {
			seats[row][col] = EMPTY;
		}
	}
	displaySeatingChart(seats);
	int row = 0;
	int seat = 0;
	char anotherSeat = 'y';
	vector<int> wantedRows;
	vector<int> wantedSeats;
	while (anotherSeat == 'y') {

		cout << "What seat would you like? (row 1-15, seat A-E) ";

		cin >> row >> seat;

		if (!isValid(row, seat)) {
			cout << "Please enter: row 1-60, seat A-E " << endl;
		}
		else if (seats[row][seat] == EMPTY) {
			rowsWanted.push_back(row);
			seatsWanted.push_back(seat);
			cout << row << ", " << seat << endl;
			seats[row][seat] = TAKEN;
			cout << "Another seat? (y/n): ";
			cin >> anotherSeat;
		}
		else {
			cout << "That seat is taken, try another seat." << endl;
			row = 0;
			seat = 0;
		}
	}
	displaySeatingChart(seats);

	displayAirlineSchedule();
	
	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;
	cout << "Date of Birth? ";
	cin >> dateOfBirth;
	cout << "Passport Number? ";
	cin >> passportNo;
	cout << "Gender? ";
	cin >> gender;
	cout << "Nationality? ";
	cin >> nationality;

	db.addPassenger(firstName, lastName, dateOfBirth, passportNo, gender, nationality);
}
void doCancel(AirlineDB& db) {
	int bookingNumber;

	cout << "Booking number? ";
	cin >> bookingNumber;

	try {
		Airline& passenger = db.getPassenger(bookingNumber);
		passenger.reserve();
		cout << "Reservation " << bookingNumber << " canceled." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancel booking: " << exception.what() << endl;
	}

}
void displayAirline(AirlineDB& db) {
	
}
void doReservedFirstClass(AirlineDB& db) {

}
void doReservedEconomyClass(AirlineDB& db) {

}

