// AirlineReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "AirlineDB.h"

using namespace AirlineReservationSystem;
using namespace std;

int displayFlightSchedule();
int displayMenu();
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

