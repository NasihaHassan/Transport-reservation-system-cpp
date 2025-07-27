#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Global variables for bus data
vector<int> busNumbers;
vector<string> driverNames;
vector<string> departureTimes;
vector<string> arrivalTimes;
vector<string> fromLocations;
vector<string> toLocations;
vector<int> totalSeats;
vector<int> availableSeats;
vector<vector<bool>> seatStatus;

// Global variables for reservations
vector<int> reservationBusNumbers;
vector<string> passengerNames;
vector<int> seatNumbers;
vector<string> travelDates;

// File names
const string BUS_FILE = "buses.txt";
const string RESERVATION_FILE = "reservations.txt";

// Utility functions
string boolVectorToString(const vector<bool>& vec) {
    string result;
    for (bool b : vec) {
        result += b ? '1' : '0';
    }
    return result;
}

vector<bool> stringToBoolVector(const string& str, int size) {
    vector<bool> result(size, false);
    for (int i = 0; i < min((int)str.size(), size); i++) {
        result[i] = (str[i] == '1');
    }
    return result;
}

// File handling functions
void saveBusesToFile() {
    ofstream outFile(BUS_FILE);
    if (!outFile) {
        cerr << "Error opening file for writing: " << BUS_FILE << endl;
        return;
    }
    
    outFile << "Bus Number,Driver Name,Departure Time,Arrival Time,From,To,Total Seats,Available Seats,Seat Status\n";
    
    for (size_t i = 0; i < busNumbers.size(); i++) {
        outFile << busNumbers[i] << ","
                << driverNames[i] << ","
                << departureTimes[i] << ","
                << arrivalTimes[i] << ","
                << fromLocations[i] << ","
                << toLocations[i] << ","
                << totalSeats[i] << ","
                << availableSeats[i] << ","
                << boolVectorToString(seatStatus[i]) << "\n";
    }
    
    outFile.close();
}

void loadBusesFromFile() {
    ifstream inFile(BUS_FILE);
    if (!inFile) {
        return;
    }
    
    string header;
    getline(inFile, header);
    
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 9) {
            busNumbers.push_back(stoi(tokens[0]));
            driverNames.push_back(tokens[1]);
            departureTimes.push_back(tokens[2]);
            arrivalTimes.push_back(tokens[3]);
            fromLocations.push_back(tokens[4]);
            toLocations.push_back(tokens[5]);
            totalSeats.push_back(stoi(tokens[6]));
            availableSeats.push_back(stoi(tokens[7]));
            
            int seats = stoi(tokens[6]);
            vector<bool> seatsVec = stringToBoolVector(tokens[8], seats);
            seatStatus.push_back(seatsVec);
        }
    }
    
    inFile.close();
}

void saveReservationsToFile() {
    ofstream outFile(RESERVATION_FILE);
    if (!outFile) {
        cerr << "Error opening file for writing: " << RESERVATION_FILE << endl;
        return;
    }
    
    outFile << "Bus Number,Passenger Name,Seat Number,Travel Date\n";
    
    for (size_t i = 0; i < reservationBusNumbers.size(); i++) {
        outFile << reservationBusNumbers[i] << ","
                << passengerNames[i] << ","
                << seatNumbers[i] << ","
                << travelDates[i] << "\n";
    }
    
    outFile.close();
}

void loadReservationsFromFile() {
    ifstream inFile(RESERVATION_FILE);
    if (!inFile) {
        return;
    }
    
    string header;
    getline(inFile, header);
    
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 4) {
            reservationBusNumbers.push_back(stoi(tokens[0]));
            passengerNames.push_back(tokens[1]);
            seatNumbers.push_back(stoi(tokens[2]));
            travelDates.push_back(tokens[3]);
        }
    }

    inFile.close();
}

void saveDataToFiles() {
    saveBusesToFile();
    saveReservationsToFile();
}

void loadDataFromFiles() {
    loadBusesFromFile();
    loadReservationsFromFile();
}

// Bus management functions
int findBusIndex(int busNumber) {
    for(int i = 0; i < busNumbers.size(); i++) {
        if(busNumbers[i] == busNumber) {
            return i;
        }
    }
    return -1;
}

void displayBusDetails(int index) {
    cout << "\nBus Details:\n";
    cout << "----------------------------------------\n";
    cout << "Bus Number: " << busNumbers[index] << "\n";
    cout << "Driver: " << driverNames[index] << "\n";
    cout << "Departure Time: " << departureTimes[index] << "\n";
    cout << "Arrival Time: " << arrivalTimes[index] << "\n";
    cout << "From: " << fromLocations[index] << "\n";
    cout << "To: " << toLocations[index] << "\n";
    cout << "Total Seats: " << totalSeats[index] << "\n";
    cout << "Available Seats: " << availableSeats[index] << "\n";
    cout << "----------------------------------------\n";
}

void displayMainMenu() {
    system("cls");
    cout << "====================================\n";
    cout << "   TRANSPORT RESERVATION SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Add New Bus\n";
    cout << "2. View All Buses\n";
    cout << "3. Make Reservation\n";
    cout << "4. View Reservations\n";
    cout << "5. Cancel Reservation\n";
    cout << "6. Search Bus\n";
    cout << "7. Exit\n";
    cout << "====================================\n";
}

void addBus() {
    int busNumber;
    string driverName, departureTime, arrivalTime, from, to;
    int seats;
    
    cout << "\nEnter Bus Number: ";
    cin >> busNumber;
    
    for(int i = 0; i < busNumbers.size(); i++) {
        if(busNumbers[i] == busNumber) {
            cout << "Bus with this number already exists!\n";
            return;
        }
    }
    
    cin.ignore();
    cout << "Enter Driver Name: ";
    getline(cin, driverName);
    
    cout << "Enter Departure Time: ";
    getline(cin, departureTime);
    
    cout << "Enter Arrival Time: ";
    getline(cin, arrivalTime);
    
    cout << "Enter Departure From: ";
    getline(cin, from);
    
    cout << "Enter Destination: ";
    getline(cin, to);
    
    cout << "Enter Total Seats: ";
    cin >> seats;
    
    busNumbers.push_back(busNumber);
    driverNames.push_back(driverName);
    departureTimes.push_back(departureTime);
    arrivalTimes.push_back(arrivalTime);
    fromLocations.push_back(from);
    toLocations.push_back(to);
    totalSeats.push_back(seats);
    availableSeats.push_back(seats);
    
    vector<bool> seatsStatus(seats, false);
    seatStatus.push_back(seatsStatus);
    
    saveDataToFiles(); // Save after adding
    cout << "\nBus added successfully!\n";
}

void viewAllBuses() {
    if(busNumbers.empty()) {
        cout << "\nNo buses available!\n";
        return;
    }
    
    cout << "\nList of All Buses:\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    cout << left << setw(12) << "Bus No." << setw(20) << "Driver" << setw(12) << "Departure" 
         << setw(12) << "Arrival" << setw(15) << "From" << setw(15) << "To" 
         << setw(10) << "Seats" << setw(10) << "Available\n";
    cout << "-------------------------------------------------------------------------------------------------\n";
    
    for(int i = 0; i < busNumbers.size(); i++) {
        cout << left << setw(12) << busNumbers[i] << setw(20) << driverNames[i] 
             << setw(12) << departureTimes[i] << setw(12) << arrivalTimes[i] 
             << setw(15) << fromLocations[i] << setw(15) << toLocations[i] 
             << setw(10) << totalSeats[i] << setw(10) << availableSeats[i] << "\n";
    }
}

void makeReservation() {
    if(busNumbers.empty()) {
        cout << "\nNo buses available for reservation!\n";
        return;
    }
    
    int busNumber;
    cout << "\nEnter Bus Number: ";
    cin >> busNumber;
    
    int busIndex = findBusIndex(busNumber);
    if(busIndex == -1) {
        cout << "Bus not found!\n";
        return;
    }
    
    if(availableSeats[busIndex] == 0) {
        cout << "Sorry, no seats available on this bus!\n";
        return;
    }
    
    cout << "\nAvailable Seats for Bus " << busNumber << ":\n";
    for(int i = 0; i < totalSeats[busIndex]; i++) {
        if(!seatStatus[busIndex][i]) {
            cout << "Seat " << (i+1) << " ";
        }
    }
    cout << "\n";
    
    int seatNumber;
    cout << "Enter Seat Number: ";
    cin >> seatNumber;
    
    if(seatNumber < 1 || seatNumber > totalSeats[busIndex]) {
        cout << "Invalid seat number!\n";
        return;
    }
    
    if(seatStatus[busIndex][seatNumber-1]) {
        cout << "Seat already booked!\n";
        return;
    }
    
    cin.ignore();
    string passengerName;
    cout << "Enter Passenger Name: ";
    getline(cin, passengerName);
    
    string date;
    cout << "Enter Date of Travel (DD/MM/YYYY): ";
    getline(cin, date);
    
    seatStatus[busIndex][seatNumber-1] = true;
    availableSeats[busIndex]--;
    
    reservationBusNumbers.push_back(busNumber);
    passengerNames.push_back(passengerName);
    seatNumbers.push_back(seatNumber);
    travelDates.push_back(date);
    
    saveDataToFiles(); // Save after reservation
    cout << "\nReservation successful!\n";
    cout << "Reservation Details:\n";
    cout << "Bus Number: " << busNumber << "\n";
    cout << "Passenger: " << passengerName << "\n";
    cout << "Seat Number: " << seatNumber << "\n";
    cout << "Travel Date: " << date << "\n";
}

void viewReservations() {
    if(reservationBusNumbers.empty()) {
        cout << "\nNo reservations found!\n";
        return;
    }
    
    cout << "\nAll Reservations:\n";
    cout << "--------------------------------------------------------------------\n";
    cout << left << setw(12) << "Bus No." << setw(20) << "Passenger" 
         << setw(10) << "Seat No." << setw(15) << "Travel Date\n";
    cout << "--------------------------------------------------------------------\n";
    
    for(int i = 0; i < reservationBusNumbers.size(); i++) {
        cout << left << setw(12) << reservationBusNumbers[i] << setw(20) << passengerNames[i] 
             << setw(10) << seatNumbers[i] << setw(15) << travelDates[i] << "\n";
    }
}

void cancelReservation() {
    if(reservationBusNumbers.empty()) {
        cout << "\nNo reservations to cancel!\n";
        return;
    }
    
    int busNumber, seatNumber;
    cout << "\nEnter Bus Number: ";
    cin >> busNumber;
    cout << "Enter Seat Number: ";
    cin >> seatNumber;
    
    bool found = false;
    for(int i = 0; i < reservationBusNumbers.size(); i++) {
        if(reservationBusNumbers[i] == busNumber && seatNumbers[i] == seatNumber) {
            int busIndex = findBusIndex(busNumber);
            if(busIndex != -1) {
                seatStatus[busIndex][seatNumber-1] = false;
                availableSeats[busIndex]++;
            }
            
            reservationBusNumbers.erase(reservationBusNumbers.begin() + i);
            passengerNames.erase(passengerNames.begin() + i);
            seatNumbers.erase(seatNumbers.begin() + i);
            travelDates.erase(travelDates.begin() + i);
            
            found = true;
            break;
        }
    }
    
    if(found) {
        saveDataToFiles(); // Save after cancellation
        cout << "Reservation canceled successfully!\n";
    } else {
        cout << "Reservation not found!\n";
    }
}

void searchBus() {
    if(busNumbers.empty()) {
        cout << "\nNo buses available!\n";
        return;
    }
    
    int choice;
    cout << "\nSearch Buses By:\n";
    cout << "1. Bus Number\n";
    cout << "2. Route (From-To)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    cin.ignore();
    
    if(choice == 1) {
        int busNumber;
        cout << "Enter Bus Number: ";
        cin >> busNumber;
        
        int busIndex = findBusIndex(busNumber);
        if(busIndex == -1) {
            cout << "Bus not found!\n";
        } else {
            displayBusDetails(busIndex);
        }
    } else if(choice == 2) {
        string from, to;
        cout << "Enter Departure From: ";
        getline(cin, from);
        cout << "Enter Destination: ";
        getline(cin, to);
        
        bool found = false;
        for(int i = 0; i < busNumbers.size(); i++) {
            if(fromLocations[i] == from && toLocations[i] == to) {
                displayBusDetails(i);
                found = true;
            }
        }
        
        if(!found) {
            cout << "No buses found for this route!\n";
        }
    } else {
        cout << "Invalid choice!\n";
    }
}

int main() {
    loadDataFromFiles();
    
    int choice;
    
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                addBus();
                break;
            case 2:
                viewAllBuses();
                break;
            case 3:
                makeReservation();
                break;
            case 4:
                viewReservations();
                break;
            case 5:
                cancelReservation();
                break;
            case 6:
                searchBus();
                break;
            case 7:
                cout << "Thank you for using Transport Reservation System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nPress Enter to continue...";
        cin.get();
        
    } while(choice != 7);
    
    saveDataToFiles();
    return 0;
}