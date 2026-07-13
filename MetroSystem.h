#ifndef METROSYSTEM_H
#define METROSYSTEM_H

#include <iostream>
#include <string>

using namespace std;

//  Developer B: 

class Vechicle {
public:
    string vechicleId;
    string driverName;
    int capacity;
    bool isAvailable;

    Vechicle(string v, string d, int c, bool i) {
        vechicleId = v;
        driverName = d;
        capacity = c;
        isAvailable = i;
    }

    virtual ~Vechicle() {}

    virtual void display() const {
        cout << "The Id of teh Vechicel:" << vechicleId << endl;
        cout << "Teh name of the driver is " << driverName << endl;
        cout << "The capcity of the Vechicle is: " << capacity << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No");
    }
};

class Bus : public Vechicle {
public:
    string routeName;
    int currentPassengers;
    float speed;
    bool isInService;

    Bus(string v, string d, int c, bool i, string r, int c1, float s, bool ii)
        : Vechicle(v, d, c, i) {
        routeName = r;
        currentPassengers = c1;
        speed = s;
        isInService = ii;
    }

    void display() const override {
        cout << "The route Name is " << routeName << endl;
        cout << "The Current Passenger in teh Bus :" << currentPassengers << endl;
        cout << "The speed of teh bus is " << speed << endl;
        cout << "In Service: " << (isInService ? "Yes" : "No") << endl;
    }
};

// (Developer A)
class RegularMetroBus : public Bus {
public:
    string stop[15];
    float farePerstop[15];
    int stopcount;

    RegularMetroBus(string v, string d, int c, bool avail, string r, int currPass, float s,
                    bool inServ, string st[], float fare[], int n)
        : Bus(v, d, c, avail, r, currPass, s, inServ) {
        stopcount = n;
        for (int i = 0; i < n && i < 15; i++) {
            stop[i] = st[i];
            farePerstop[i] = fare[i];
        }
    }

 void display() const override {
        for (int i = 0; i < stopcount; i++) {
            cout << i + 1 << ". " << stop[i] << " | Fare: Rs " << farePerstop[i] << endl;
        }
    }
};

class Express : public Bus {
public:
    int limitedStops;
    bool hasWifi;
    float expressFare;

    Express(string v, string d, int c, bool avail, string r, int currPass, float s, bool inServ,
            int l, bool h, float e)
        : Bus(v, d, c, avail, r, currPass, s, inServ) {
        limitedStops = l;
        hasWifi = h;
        expressFare = e;
    }

    void display() const override {
        cout << "The Limited stops is :" << limitedStops << endl;
        cout << "The bus Wifif : " << hasWifi << endl;
        cout << "The expressFare is the " << expressFare << endl;
        cout << "WiFi: " << (hasWifi ? "Yes" : "No") << endl;
    }
};

class Maintenance : public Vechicle {
public:
    string maintainencetype;
    bool isRepairing;

    Maintenance(string v, string d, int c, bool i, string m, bool is) : Vechicle(v, d, c, i) {
        maintainencetype = m;
        isRepairing = is;
    }

    void display() const override {
        Vechicle::display();
        cout << "Maintainence Type" << maintainencetype << endl;
        cout << "Currently Repairing" << (isRepairing ? "yes" : "No") << endl;
    }
};

class Emergency : public Bus {
public:
    string emergencyType;
    bool isActive;

    Emergency(string v, string d, int c, bool i, string r, int c1, float s, bool ii, string type,
              bool active)
        : Bus(v, d, c, i, r, c1, s, ii) {
        emergencyType = type;
        isActive = active;
    }

    virtual void display() const override {
        Bus::display();
        cout << "The Emergency type is " << emergencyType << endl;
    }
};

class Medical : public Emergency {
public:
    int patientcapacity;
    string hositalname;

    Medical(string v, string d, int c, bool avail, string r, int currPass, float s, bool inServ,
            bool active, int pc, string hosp)
        : Emergency(v, d, c, avail, r, currPass, s, inServ, "Medical", active) {
        patientcapacity = pc;
        hositalname = hosp;
    }

    void display() const override {
        Bus::display();
        cout << "--- Medical Emergency ---" << endl;
        cout << "Type: " << Emergency::emergencyType << endl;
        cout << "Active: " << (isActive ? "YES" : "No") << endl;
        cout << "Patient Capacity: " << patientcapacity << endl;
        cout << "Hospital: " << hositalname << endl;
    }
};

class BreakDown : public Emergency {
public:
    string equiment;
    int crewMember;

    BreakDown(string v, string d, int c, bool avail, string r, int currPass, float s, bool inServ,
              bool active, string equip, int crew)
        : Emergency(v, d, c, avail, r, currPass, s, inServ, "Breakdown", active) {
        equiment = equip;
        crewMember = crew;
    }

    void display() const override {
        Bus::display();
        cout << "Type is " << Emergency::emergencyType << endl;
        cout << "The Active is " << (isActive ? "YES" : "No") << endl;
        cout << "Equipment " << equiment << endl;
        cout << "Crew Memebers " << crewMember << endl;
    }
};

class Fire : public Emergency {
public:
    int waterCapacity;
    int hoseCount;

    Fire(string v, string d, int c, bool avail, string r, int currPass, float s, bool inServ,
         bool active, int water, int hoses)
        : Emergency(v, d, c, avail, r, currPass, s, inServ, "Fire", active) {
        waterCapacity = water;
        hoseCount = hoses;
    }

    void display() const override {
        Bus::display();
        cout << "Type is " << Emergency::emergencyType << endl;
        cout << "The Active is " << (isActive ? "YES" : "No") << endl;
        cout << "The water Capcity is" << waterCapacity << endl;
        cout << "the Hose Count: " << hoseCount << endl;
    }
};

class FareSystem {
public:
    virtual ~FareSystem() {}
    virtual float calculateFare(float baseFare) = 0;
};

class Regularfare : public FareSystem {
public:
    static const int NEW_PASSENGER = 100;

    Regularfare() {}

    float calculateFare(float baseFare) override { return baseFare; }

    float calculateNewPassenger(float baseFare) { return baseFare - NEW_PASSENGER; }
};

class RushHour : public FareSystem {
public:
    float surcharge;

    RushHour(float sur) { surcharge = sur; }

    float calculateFare(float baseFare) override {
        return baseFare + (baseFare * surcharge / 100.0f);
    }
};

//  Developer A: 

class Route;
class Schedule;

class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) {
        name = n;
        id = i;
    }

    virtual void displayInfo() = 0;

    void displayinfo() { cout << "My Name is: " << name << " My ID is: " << id << endl; }

    virtual string getRole() { return "Person"; }

    void role() { cout << getRole() << endl; }
};

class Route {
private:
    string stops[9];

public:
    Route() {
        stops[0] = "Chamkani";
        stops[1] = "Sardar Garhi";
        stops[2] = "Lahore Adda";
        stops[3] = "Hashtnagri";
        stops[4] = "Khyber Bazar";
        stops[5] = "Saddar Bazar";
        stops[6] = "University of Peshawar";
        stops[7] = "Mall of Hayatabad";
        stops[8] = "Karkhano Market";
    }

    void showRouteDetails() {
        cout << " ! BUS STOPS ROUTE ! " << endl;
        for (int i = 0; i < 9; i++) {
            cout << "Stop " << i + 1 << ": " << stops[i] << endl;
        }
    }

    void viewschedule() { showRouteDetails(); }
};

class Schedule {
private:
    string busTimes[12];

public:
    Schedule() {
        busTimes[0] = "06:00 AM";
        busTimes[1] = "07:00 AM";
        busTimes[2] = "08:00 AM";
        busTimes[3] = "09:00 AM";
        busTimes[4] = "10:00 AM";
        busTimes[5] = "11:00 AM";
        busTimes[6] = "12:00 PM";
        busTimes[7] = "01:00 PM";
        busTimes[8] = "02:00 PM";
        busTimes[9] = "03:00 PM";
        busTimes[10] = "04:00 PM";
        busTimes[11] = "05:00 PM";
    }

    void showDailySchedule() {
        cout << "  ! DAILY BUS SCHEDULE !" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "Bus No " << i + 1 << " departs at: " << busTimes[i] << endl;
        }
    }
};

class Passenger : public Person {
protected:
    int money;
    Route r1;

public:
    Passenger(string n, int i) : Person(n, i) { money = 100; }

    void displayInfo() override {
        cout << "Passenger " << name << "  ID: " << id << "  Money: " << money << " PKR" << endl;
    }

    string getRole() override { return "PASSENGER"; }

    void checkin() {
        int fare = 70;
        if (money < fare) {
            cout << "Sorry you can not Aboard the Bus due to insufficient Balance" << endl;
        } else {
            cout << "Checked in!" << endl;
        }
    }

   void calculatefare(int start, int end) {
        if (start < 1 || start > 9 || end < 1 || end > 9) {
            cout << "Invalid stop number. Please enter a stop between 1 and 9."<< endl;
            return;
        }
        int distance = end - start;
        if (distance <= 0) {
            cout << "End stop must be after start stop." << endl;
            return;
        }
        if (distance <= 2) {
            money -= 30;
        } else if (distance <= 5) {
            money -= 60;
        } else {
            money -= 70;
        }
    }

    void viewschedule() { r1.viewschedule(); }
};

// RegularMetroBus (Developer B)
class RegularPassenger : public Passenger {
protected:
    string gender;

public:
    RegularPassenger(string n, int i, string g) : Passenger(n, i) { gender = g; }

    void displaypassinfo() {
        cout << "Passenger " << name << "  ID: " << id << "  Gender: " << gender << endl;
    }

    void displayInfo() override { displaypassinfo(); }
};

class Disabled : public RegularPassenger {
public:
    Disabled(string n, int i) : RegularPassenger(n, i, "Not Specified") {}

    void displayInfo() override {
        cout << "Disabled Passenger: " << name << "  Balance: " << money << "  Needs: Wheel Chair"
             << endl;
    }
};

class VIP : public Passenger {
    bool isVIP;

public:
    VIP(string n, int i) : Passenger(n, i) { isVIP = true; }

    void displayInfo() override {
        cout << "[VIP Passenger] " << name << " Balance: " << money << "  Benefit: Front Seat"
             << endl;
    }

    void discount() {
        if (isVIP) {
            money = static_cast<int>(money - (money * 0.20));
            cout << name << " is a VIP figure" << endl;
            cout << "Discounted Amount: " << money << endl;
        } else {
            cout << name << " is not a VIP Customer" << endl;
        }
    }
};

class Driver : public Person {
public:
    Driver(string n, int i) : Person(n, i) {}

    string getRole() override { return "DRIVER"; }

    void displayInfo() override { cout << "Driver " << name << "  ID: " << id << endl; }
};

class RegularDriver : public Driver {
public:
    RegularDriver(string n, int i) : Driver(n, i) {}
};

class DriverBusSystem {
protected:
    string driver[12];
    string buses[12];

public:
    DriverBusSystem() {
        driver[0] = "TALHA";
        driver[1] = "HANZALA";
        driver[2] = "ALI";
        driver[3] = "HAMID";
        driver[4] = "SAMEER";
        driver[5] = "FASEEH";
        driver[6] = "WAQAS";
        driver[7] = "AWAIS";
        driver[8] = "NOUMAN";
        driver[9] = "HASEEB";
        driver[10] = "WALEED";
        driver[11] = "ANONYMOUS";

        buses[0] = "BUS-01";
        buses[1] = "BUS-02";
        buses[2] = "BUS-03";
        buses[3] = "BUS-04";
        buses[4] = "BUS-05";
        buses[5] = "BUS-06";
        buses[6] = "BUS-07";
        buses[7] = "BUS-08";
        buses[8] = "BUS-09";
        buses[9] = "BUS-10";
        buses[10] = "BUS-11";
        buses[11] = "BUS-12";
    }

    void allocation() {
        cout << " Driver and Buses Allocation " << endl;
        for (int i = 0; i < 12; i++) {
            cout << "DRIVER: " << driver[i] << "  ASSIGNED BUS: " << buses[i] << endl;
        }
    }
};

#endif
