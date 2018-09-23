// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "AirlineDB.h"

using namespace AirlineReservationSystem;
using namespace std;

void justDisplayAirlineSchedule();
int displayMenu();
void doReserve(AirlineDB& db);
void doCancel(AirlineDB& db);


int main()
{
	AirlineDB airlineReservationDB;	

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0: //EXIT
			return 0;
		case 1:
			doReserve(airlineReservationDB);

			break;
		case 2:
			airlineReservationDB.displayBookingInfo();
			break;
		case 3:
			justDisplayAirlineSchedule();
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

void justDisplayAirlineSchedule()
{
	cout << "Airline Schedule" << endl;
	cout << "==================================================================================================" << endl;
	for (int i = 0; i < 1; i++) {
		cout << HEADING[i] << endl;
	}
	cout << "==================================================================================================" << endl;
	for (int i = 0; i < 6; i++) {
		cout << AIRLINE_NUMBER[i] << AIRLINE_DETAILS[i] << endl;
	}
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
	string firstName;
	string lastName;
	string dateOfBirth;
	string passportNo;
	string gender;
	string nationality;
	string airline;

	justDisplayAirlineSchedule();
	
	cout << "Which line No. would you like to book? ";
	cin >> airline;
	
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
	

	db.addPassenger(firstName, lastName, dateOfBirth, passportNo, gender, nationality, airline);
}
void doCancel(AirlineDB& db) {
	int bookingNumber;
	int seatNumber;

	cout << "Booking number? ";
	cin >> bookingNumber >> seatNumber;

	try {
		AirlinePassenger& passenger = db.getPassenger(bookingNumber, seatNumber);
		passenger.reserve();
		cout << "Reservation " << bookingNumber << seatNumber << " canceled." << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to cancel booking: " << exception.what() << endl;
	}

}

