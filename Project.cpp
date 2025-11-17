#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
#include <iostream>
#include <fstream>
using namespace std;
int showMainMenu(){
    cout << "--------------------------------------------------------------\n";
    cout << "                           MAIN MENU                          \n";
    cout << "--------------------------------------------------------------\n\n";

    cout << " 1. Car Management\n";
    cout << " 2. Customer Management\n";
    cout << " 3. New Booking\n";
    cout << " 4. Return / Checkout\n";
    cout << " 5. View Bookings\n";
    cout << " 6. Reports & Revenue\n";
    cout << " 7. Settings\n";
    cout << " 0. Exit\n";

    cout << "\n--------------------------------------------------------------\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    return choice;
}
//--------------------Related to Car Management------------------------
class Car {
public:
    int id;
    char model[50];
    char type[20];
    int seats;
    float rent;

    void input() {
        cout << "Enter Car ID: ";
        cin >> id;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Type (SUV/Sedan): ";
        cin >> type;
        cout << "Enter Seats: ";
        cin >> seats;
        cout << "Enter Rent per Day: ";
        cin >> rent;
    }

    void display() {
        cout << id << "\t" << model << "\t" << type << "\t" 
             << seats << "\t" << rent << endl;
    }
};

Car carArr[50];       // ARRAY of objects  
int carCount = 0;     // how many cars stored

// ---------------- FILE SAVE ----------------
void saveToFile() {
    ofstream fout("cars.txt");
    for (int i = 0; i < carCount; i++) {
        fout << carArr[i].id << " "
             << carArr[i].model << " "
             << carArr[i].type << " "
             << carArr[i].seats << " "
             << carArr[i].rent << "\n";
    }
    fout.close();
}

// ---------------- FILE LOAD ----------------
void loadFromFile() {
    ifstream fin("cars.txt");
    carCount = 0;
    while (fin >> carArr[carCount].id 
               >> carArr[carCount].model
               >> carArr[carCount].type
               >> carArr[carCount].seats
               >> carArr[carCount].rent) 
    {
        carCount++;
    }
    fin.close();
}

// ------------ ADD CAR ---------------
void addCar() {
    cout << "\n--- Add New Car ---\n";
    carArr[carCount].input();
    carCount++;
    saveToFile();
    cout << "Car Added Successfully!\n";
}

// ------------ DISPLAY CARS ----------
void displayCars() {
    cout << "\nID\tModel\tType\tSeats\tRent\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < carCount; i++) {
        carArr[i].display();
    }
}

// ------------ SEARCH CAR ------------
void searchCar() {
    int cid;
    cout << "Enter Car ID to search: ";
    cin >> cid;

    for (int i = 0; i < carCount; i++) {
        if (carArr[i].id == cid) {
            cout << "Car Found:\n";
            carArr[i].display();
            return;
        }
    }
    cout << "Car Not Found!\n";
}

// ------------ UPDATE CAR ------------
void updateCar() {
    int cid;
    cout << "Enter Car ID to update: ";
    cin >> cid;

    for (int i = 0; i < carCount; i++) {
        if (carArr[i].id == cid) {
            cout << "Enter new details:\n";
            carArr[i].input();
            saveToFile();
            cout << "Car Updated!\n";
            return;
        }
    }
    cout << "Car Not Found!\n";
}

// ------------ DELETE CAR ------------
void deleteCar() {
    int cid;
    cout << "Enter Car ID to delete: ";
    cin >> cid;

    for (int i = 0; i < carCount; i++) {
        if (carArr[i].id == cid) {
            
            // shift array left
            for (int j = i; j < carCount - 1; j++) {
                carArr[j] = carArr[j + 1];
            }

            carCount--;
            saveToFile();
            cout << "Car Deleted!\n";
            return;
        }
    }
    cout << "Car Not Found!\n";
}

//------------Related to Customer Management-----------------
class Customer {
public:
    int id;
    char name[50];
    char phone[20];

    void input() {
        cout << "Enter Customer ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone: ";
        cin >> phone;
    }

    void display() {
        cout << id << "\t" << name << "\t" << phone << endl;
    }
};

Customer custArr[50];
int custCount = 0;
//Save Customer to File
void saveCustomerToFile() {
    ofstream fout("customers.txt");
    for (int i = 0; i < custCount; i++) {
        fout << custArr[i].id << " "
             << custArr[i].name << " "
             << custArr[i].phone << "\n";
    }
    fout.close();
}
//Load Customer File
void loadCustomerFromFile() {
    ifstream fin("customers.txt");
    custCount = 0;

    while (fin >> custArr[custCount].id
               >> custArr[custCount].name
               >> custArr[custCount].phone)
    {
        custCount++;
    }

    fin.close();
}
//Add Customer
void addCustomer() {
    cout << "\n--- Add New Customer ---\n";
    custArr[custCount].input();
    custCount++;
    saveCustomerToFile();
    cout << "Customer Added Successfully!\n";
}

//Display Customer
void displayCustomers() {
    cout << "\nID\tName\tPhone\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < custCount; i++) {
        custArr[i].display();
    }
}
//Search Customer
void searchCustomer() {
    int cid;
    cout << "Enter Customer ID to search: ";
    cin >> cid;

    for (int i = 0; i < custCount; i++) {
        if (custArr[i].id == cid) {
            cout << "Customer Found:\n";
            custArr[i].display();
            return;
        }
    }

    cout << "Customer Not Found!\n";
}
//Update Customer
void updateCustomer() {
    int cid;
    cout << "Enter Customer ID to update: ";
    cin >> cid;

    for (int i = 0; i < custCount; i++) {
        if (custArr[i].id == cid) {
            cout << "Enter new details:\n";
            custArr[i].input();
            saveCustomerToFile();
            cout << "Customer Updated!\n";
            return;
        }
    }

    cout << "Customer Not Found!\n";
}
//Delete Customer
void deleteCustomer() {
    int cid;
    cout << "Enter Customer ID to delete: ";
    cin >> cid;

    for (int i = 0; i < custCount; i++) {
        if (custArr[i].id == cid) {

            for (int j = i; j < custCount - 1; j++) {
                custArr[j] = custArr[j + 1];
            }

            custCount--;
            saveCustomerToFile();
            cout << "Customer Deleted!\n";
            return;
        }
    }

    cout << "Customer Not Found!\n";
}


// ------------ CAR MANAGEMENT MENU ------------
void carManagementMenu() {
    int choice;

    do {
        cout << "\n===== CAR MANAGEMENT =====\n";
        cout << "1. Add Car\n";
        cout << "2. Display Cars\n";
        cout << "3. Search Car\n";
        cout << "4. Update Car\n";
        cout << "5. Delete Car\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addCar(); break;
        case 2: displayCars(); break;
        case 3: searchCar(); break;
        case 4: updateCar(); break;
        case 5: deleteCar(); break;
        case 0: cout << "Returning...\n"; showMainMenu() ;break;
        default: cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}
//-----------Customer Mangement Menu-------------
void customerManagementMenu() {
    int choice;

    do {
        cout << "\n===== CUSTOMER MANAGEMENT =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Display Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Update Customer\n";
        cout << "5. Delete Customer\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addCustomer(); break;
        case 2: displayCustomers(); break;
        case 3: searchCustomer(); break;
        case 4: updateCustomer(); break;
        case 5: deleteCustomer(); break;
        case 0: cout << "Returning...\n";showMainMenu() ; break;
        default: cout << "Invalid Choice!\n";
        }

    } while (choice != 0);
}
// ----------------- BOOKING MODULE-----------------------------
class Booking {
public:
    int id;         // booking id
    int carId;      // car id booked
    int custId;     // customer id who booked
    int days;       // number of days
    float total;    // total rent = days * car.rent

    void input() {
        cout << "Enter Booking ID: ";
        cin >> id;
        cout << "Enter Car ID: ";
        cin >> carId;
        cout << "Enter Customer ID: ";
        cin >> custId;
        cout << "Enter Number of Days: ";
        cin >> days;
        // total will be calculated outside after verifying car exists
    }

    void display() const {
        cout << id << "\t" << carId << "\t" << custId << "\t" << days << "\t" << fixed << setprecision(2) << total << endl;
    }
};

const int MAX_BOOKINGS = 100;
Booking bookingArr[MAX_BOOKINGS];
int bookingCount = 0;
const char *BOOKING_FILE = "bookings.txt";

// Save bookings to file (space-separated simple format)
void saveBookingsToFile() {
    ofstream fout(BOOKING_FILE);
    for (int i = 0; i < bookingCount; ++i) {
        fout << bookingArr[i].id << " "
             << bookingArr[i].carId << " "
             << bookingArr[i].custId << " "
             << bookingArr[i].days << " "
             << bookingArr[i].total << "\n";
    }
    fout.close();
}

// Load bookings from file
void loadBookingsFromFile() {
    ifstream fin(BOOKING_FILE);
    bookingCount = 0;
    while (fin >> bookingArr[bookingCount].id
               >> bookingArr[bookingCount].carId
               >> bookingArr[bookingCount].custId
               >> bookingArr[bookingCount].days
               >> bookingArr[bookingCount].total)
    {
        bookingCount++;
    }
    fin.close();
}

// helper: find car index by id (-1 if not found)
int findCarIndexById(int cid) {
    for (int i = 0; i < carCount; ++i) {
        if (carArr[i].id == cid) return i;
    }
    return -1;
}

// helper: find customer index by id (-1 if not found)
int findCustomerIndexById(int cid) {
    for (int i = 0; i < custCount; ++i) {
        if (custArr[i].id == cid) return i;
    }
    return -1;
}

// Add new booking 
// Modified addBooking() with "offer to add customer" flow
void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        cout << "Booking storage full. Cannot add more bookings.\n";
        return;
    }

    Booking b;
    // auto id
    b.id = bookingCount + 1;
    cout << "\n--- New Booking ---\n";
    cout << "Assigned Booking ID: " << b.id << "\n";

    cout << "Enter Car ID to book: ";
    cin >> b.carId;

    int carIdx = findCarIndexById(b.carId);
    if (carIdx == -1) {
        cout << "Car ID not found. Please add or choose a valid car first.\n";
        return;
    }

    cout << "Enter Customer ID: ";
    cin >> b.custId;
    int custIdx = findCustomerIndexById(b.custId);
    if (custIdx == -1) {
        cout << "Customer ID not found.\n";
        cout << "Do you want to add this customer now? (1 = Yes, 0 = No): ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            // Open the customer management menu so user can add a customer
            // (user can choose Add Customer option there)
            customerManagementMenu();

            // After returning, reload customers from file in case they were added
            loadCustomerFromFile();

            // try to find customer again
            custIdx = findCustomerIndexById(b.custId);
            if (custIdx == -1) {
                cout << "Customer still not found. Booking cancelled.\n";
                return;
            } else {
                cout << "Customer found. Continuing booking...\n";
            }
        } else {
            cout << "Booking cancelled. Please add customer first.\n";
            return;
        }
    }

    cout << "Enter Number of Days: ";
    cin >> b.days;
    if (b.days <= 0) {
        cout << "Invalid number of days.\n";
        return;
    }

    // compute total using car rent
    b.total = b.days * carArr[carIdx].rent;

    // save booking
    bookingArr[bookingCount] = b;
    bookingCount++;
    saveBookingsToFile();

    cout << "Booking successful! Booking details:\n";
    cout << "ID\tCarID\tCustID\tDays\tTotal\n";
    b.display();
}
void displayBookings() {
    if (bookingCount == 0) {
        cout << "No bookings available.\n";
        return;
    }
    cout << "\nID\tCarID\tCustID\tDays\tTotal\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < bookingCount; ++i) {
        bookingArr[i].display();
    }
}
// Search booking by booking id
void searchBooking() {
    if (bookingCount == 0) { cout << "No bookings to search.\n"; return; }
    int bid; cout << "Enter Booking ID to search: "; cin >> bid;
    for (int i = 0; i < bookingCount; ++i) {
        if (bookingArr[i].id == bid) {
            cout << "Booking Found:\nID\tCarID\tCustID\tDays\tTotal\n";
            bookingArr[i].display();
            return;
        }
    }
    cout << "Booking Not Found!\n";
}

// Delete booking
void deleteBooking() {
    if (bookingCount == 0) { cout << "No bookings to delete.\n"; return; }
    int bid; cout << "Enter Booking ID to delete: "; cin >> bid;
    for (int i = 0; i < bookingCount; ++i) {
        if (bookingArr[i].id == bid) {
            for (int j = i; j < bookingCount - 1; ++j) bookingArr[j] = bookingArr[j+1];
            bookingCount--;
            saveBookingsToFile();
            cout << "Booking Deleted!\n";
            return;
        }
    }
    cout << "Booking Not Found!\n";
}

//---------------------Booking menu------------------------------------
void bookingMenu() {
    int choice;
    do {
        cout << "\n===== BOOKING MENU =====\n";
        cout << "1. New Booking\n";
        cout << "2. Display Bookings\n";
        cout << "3. Search Booking\n";
        cout << "4. Delete Booking\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBooking(); break;
            case 2: displayBookings(); break;
            case 3: searchBooking(); break;
            case 4: deleteBooking(); break;
            case 0: cout << "Returning to Main Menu...\n"; showMainMenu(); break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 0);
}




void showHomeScreen() {
    //clearScreen();

    cout << "==============================================================\n";
    cout << "                   CAR RENTAL ARENA PROJECT                   \n";
    cout << "==============================================================\n\n";

    cout << "                     Prepared By: Akancha Rani\n";
    cout << "                     Version : 1.0 (2025)\n\n";

    cout << "                    *** Welcome to System ***\n\n";
}

int main() {
    showHomeScreen();
    int ch = showMainMenu();

   // clearScreen();
    cout << "You selected option: " << ch << "\n\n";

    switch (ch) {
        case 1: cout << "Opening Car Management...\n";
                loadFromFile();
                carManagementMenu(); break;
        case 2: cout << "Opening Customer Management...\n"; 
                loadCustomerFromFile();
                customerManagementMenu();break;
        case 3: cout << "Starting New Booking...\n";
                loadFromFile();         // ensure cars are loaded
                loadCustomerFromFile(); // ensure customers are loaded (if you named it loadCustomerFromFile)
                loadBookingsFromFile();
                bookingMenu(); break;
        case 4: cout << "Opening Return/Checkout...\n"; break;
        case 5: cout << "Showing All Bookings...\n"; break;
        case 6: cout << "Generating Reports...\n"; break;
        case 7: cout << "Opening Settings...\n"; break;
        case 0: cout << "Exiting program...\n"; break;
        default: cout << "Invalid Choice!\n"; break;
    }

    return 0;
}
