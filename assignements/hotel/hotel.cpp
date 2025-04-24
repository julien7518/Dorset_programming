#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> split(string str, string delimiter){
    vector<string> result;
    size_t start = 0;
    size_t end = 0;
    while ((end = str.find(delimiter, start)) != string::npos){
        string part = str.substr(start, end - start);
        result.push_back(part);
        start = end + delimiter.length();
    }
    if (start < str.length()) {
        result.push_back(str.substr(start));
    }

    return result;
}

int getSerial(){
    fstream serialMemory;
    int serialNumber = 1000;
    string formerNumber;

    serialMemory.open("serial.txt", ios::in);
    if (getline(serialMemory, formerNumber)) {
        serialNumber = stoi(formerNumber);
        serialNumber++;
    }
    serialMemory.close();

    serialMemory.open("serial.txt", ios::out | ios::trunc);
    serialMemory << serialNumber;
    serialMemory.close();

    return serialNumber;
}

void showRooms(bool onlyAvailable = true){
    string rooms;
    ifstream roomData ("room.txt");
    int numberOfLine = 0;

    cout << endl;
    if (onlyAvailable) {
        cout << "  List of available rooms" << endl;
        cout << "  -----------------------" << endl;
    }
    else{
        cout << "  List of rooms" << endl;
        cout << "  -------------" << endl;
    }

    while (getline (roomData, rooms)) {
        vector<string> roomInfo = split(rooms, " ");
        if (onlyAvailable && roomInfo[2] != "Available"){
            continue;
        }
        numberOfLine ++;
        cout << numberOfLine << ". " << roomInfo[1] << (roomInfo[1] != "Dormitory" ? "   " : "") << " n°" << roomInfo[0] << ((!onlyAvailable && roomInfo[2] == "Available") ? " Available" : "") << endl;
    }
    roomData.close();

    cout << endl;
}

bool isNumber(const string& s) {
    return (!s.empty() && all_of(s.begin(), s.end(), ::isdigit));
}

bool isValidDateFormat(const string& date) {
    if (date.length() != 10 || date[2] != '-' || date[5] != '-'){
        return false;
    }

    string day = date.substr(0, 2);
    string month = date.substr(3, 2);
    string year = date.substr(6, 4);

    if (!isNumber(day) || !isNumber(month) || !isNumber(year)){
        return false;
    }

    int d = stoi(day);
    int m = stoi(month);
    int y = stoi(year);

    return (d >= 1 && d <= 31) && (m >= 1 && m <= 12) && (y >= 2025 && y <= 2027);
}

void bookRoom(){
    string rooms;
    fstream roomData;
    vector<array<int, 2>> availableRoomNumber;
    vector<string> lines;
    string roomType;
    int numberOfLine = 0;

    roomData.open("room.txt", ios::in);
    while (getline(roomData, rooms)) {
        lines.push_back(rooms);
        vector<string> roomInfo = split(rooms, " ");
        numberOfLine ++;
        if (roomInfo[2] == "Available"){
            availableRoomNumber.push_back({stoi(roomInfo[0]), numberOfLine});
            roomType = roomInfo[1];
        }
    }
    roomData.close();
    numberOfLine = 0;

    showRooms();

    int userRoom;
    int changingLine = -1;

    userInput:
        cout << "Type the number of room you want to book : ";
        cin >> userRoom;

        if (userRoom == 0){
            return;
        }

        for (array<int, 2> info : availableRoomNumber){
            if (info[0] == userRoom){
                changingLine = info[1];
            }
        }

        if (cin.fail() || changingLine == -1){
            cout << "This room don't exist or is not available" <<endl;
            cin.clear();
            cin.ignore();
            goto userInput;
        }

        string firstName;
        cout << "Enter your first name : ";
        cin >> firstName;

        string lastName;
        cout << "Enter your last name : ";
        cin >> lastName;

        string adress;
        cout << "Enter your adress : ";
        cin >> adress;

        string phoneNumber;
        cout << "Enter your phone number: ";
        cin >> phoneNumber;
        while (!isNumber(phoneNumber)) {
            cout << "Invalid phone number. Digits only: ";
            cin >> phoneNumber;
        }

        string checkIn;
        cout << "Enter the check in date (DD-MM-YYYY): ";
        cin >> checkIn;

        while (!isValidDateFormat(checkIn)) {
            cout << "Invalid date format. Try again (DD-MM-YYYY): ";
            cin >> checkIn;
        }

        string checkOut;
        cout << "Enter the check in date (DD-MM-YYYY): ";
        cin >> checkOut;

        while (!isValidDateFormat(checkOut)) {
            cout << "Invalid date format. Try again (DD-MM-YYYY): ";
            cin >> checkOut;
        }

        string bid = "BID" + to_string(userRoom) + to_string(getSerial());
        string newLine = to_string(userRoom) + " " + roomType + " NotAvailable " + bid + " " + firstName + lastName + " " + adress + " " + phoneNumber + " " + checkIn + " " + checkOut;

        lines[changingLine - 1] = newLine;

        roomData.open("room.txt", ios::out | ios::trunc);
        for (const string& line : lines) {
            roomData << line << endl;
        }
        roomData.close();

        cout << endl;
        cout << "+-----------------------+" << endl;
        cout << "| Your booking is saved |" << endl;
        cout << "+-----------------------+" << endl;
        cout << endl;
}

void menu(){
    int userChoice;
    bool running = true;
    while (running) {
        cout <<  "Welcome at Dorset Hotel" << endl;
        cout << "1. See all rooms" << endl;
        cout << "2. See only available rooms" << endl;
        cout << "3. Make a booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Please select an action : ";

        cin >> userChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }

        switch (userChoice) {
            case 1:
                showRooms(false);
                break;
            case 2:
                showRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                cout << endl;
                cout << "+--------------------------+" << endl;
                cout << "| Thank you for your visit |" << endl;
                cout << "+--------------------------+" << endl;
                cout << endl;
                running = false;
                break;
            default:
                cout << "Enter a number between 1 and 4" << endl;
                cout << endl;
                break;
        }
    }
}

int main(){
    menu();
    return 0;
}