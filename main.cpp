#include "MetroSystem.h"

static Vechicle *RawalpindiMetroFleet[10] = {nullptr};
static Vechicle *RawalpindiEmergencyFleet[3] = {nullptr};
static bool rwpFleetsInitialized = false;

static Maintenance *sendToMaintinence(Bus *b)
{
    b->isAvailable = false;
    return new Maintenance(b->vechicleId, b->driverName, b->capacity, false, "General Repair", true);
}

static void initMetroFleet(Vechicle *Metro[])
{
    Metro[0] = new Bus("B001", "Ali", 50, true, "26-Number", 30, 60.5f, true);
    Metro[1] = new Bus("B002", "Mohsine", 50, true, "raja-Baxar", 30, 70.5f, true);
    Metro[2] = new Bus("B003", "Al", 50, true, "khoi-noor_MILL", 30, 80.5f, true);
    Metro[3] = new Bus("B004", "Hamid", 50, true, "Golra-Mor", 30, 60.5f, true);
    Metro[4] = new Bus("B005", "Fasih", 50, true, "Saddar", 30, 60.5f, true);
    Metro[5] = new Bus("B006", "Uzair", 50, true, "chandiniChock", 30, 60.5f, true);
    Metro[6] = new Bus("B007", "Auzair", 50, true, "pindi-Stadium", 30, 60.5f, true);
    Metro[7] = new Bus("B008", "Fas", 50, true, "Faizabad", 30, 60.5f, true);
    Metro[8] = new Bus("B009", "Hamdan", 50, true, "Mall-road", 30, 60.5f, true);
    Metro[9] = new Bus("B010", "usman", 50, true, "G-10", 30, 60.5f, true);
}

static void initEmergencyFleet(Vechicle *Emergency[])
{
    Emergency[0] =
        new Medical("E001", "Babar", 50, true, "Emergency call", 12, 0.0f, true, true, 5, "PIMS");
    Emergency[1] =
        new Fire("F002", "yaseen", 40, true, "Emergency call", 0, 0.0f, true, true, 5000, 5);
    Emergency[2] =
        new BreakDown("B003", "yas", 40, true, "Emergency call", 12, 0.0f, true, true, "HMC", 5);
}

static void ensureRawalpindiFleets()
{
    if (!rwpFleetsInitialized)
    {
        initMetroFleet(RawalpindiMetroFleet);
        initEmergencyFleet(RawalpindiEmergencyFleet);
        rwpFleetsInitialized = true;
    }
}

static void cleanupRawalpindiFleets()
{
    if (rwpFleetsInitialized)
    {
        for (int i = 0; i < 10; i++)
        {
            delete RawalpindiMetroFleet[i];
            RawalpindiMetroFleet[i] = nullptr;
        }
        for (int i = 0; i < 3; i++)
        {
            delete RawalpindiEmergencyFleet[i];
            RawalpindiEmergencyFleet[i] = nullptr;
        }
        rwpFleetsInitialized = false;
    }
}

static void showPeshawarMenu()
{
    cout << "     SMART METRO BUS MANAGEMENT SYSTEM     " << endl;
    cout << "1. Show Route" << endl;
    cout << "2. Show Daily Schedule" << endl;
    cout << "3. Show Driver & Bus Allocation" << endl;
    cout << "4. Add Regular Passenger" << endl;
    cout << "5. Add VIP Passenger" << endl;
    cout << "6. Add Disabled Passenger" << endl;
    cout << "7. Add Driver" << endl;
    cout << "8. Check Role" << endl;
    cout << "9. Back to main menu" << endl;
    cout << "Enter your choice: ";
}

static void runPeshawarMetro()
{
    int choice = 0;
    do
    {
        showPeshawarMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "\n  -- ROUTE SYSTEM --" << endl;
            Route R1;
            R1.showRouteDetails();
        }
        else if (choice == 2)
        {
            cout << "\n  -- DAILY SCHEDULE --" << endl;
            Schedule s1;
            s1.showDailySchedule();
        }
        else if (choice == 3)
        {
            cout << "\n  -- DRIVER AND BUS ALLOCATION --" << endl;
            DriverBusSystem dbs;
            dbs.allocation();
        }
        else if (choice == 4)
        {
            cout << "\n  -- ADD REGULAR PASSENGER --" << endl;
            string name, gender;
            int id, start, end;

            cout << "Enter Passenger Name: ";
            getline(cin, name);
            cout << "Enter Passenger ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Gender: ";
            getline(cin, gender);
            cout << "Enter Start Stop (1-9): ";
            cin >> start;
            cin.ignore();
            cout << "Enter End Stop (1-9): ";
            cin >> end;
            cin.ignore();

            RegularPassenger p(name, id, gender);
            p.displayInfo();
            p.checkin();
            p.calculatefare(start, end);
            cout << "After Fare Deduction:" << endl;
            p.displayInfo();
        }
        else if (choice == 5)
        {
            cout << "\n  -- ADD VIP PASSENGER --" << endl;
            string name;
            int id;

            cout << "Enter VIP Passenger Name: ";
            getline(cin, name);
            cout << "Enter Passenger ID: ";
            cin >> id;
            cin.ignore();

            VIP p(name, id);
            p.displayInfo();
            p.discount();
        }
        else if (choice == 6)
        {
            cout << "\n  -- ADD DISABLED PASSENGER --" << endl;
            string name;
            int id;

            cout << "Enter Passenger Name: ";
            getline(cin, name);
            cout << "Enter Passenger ID: ";
            cin >> id;
            cin.ignore();

            Disabled p(name, id);
            p.displayInfo();
        }
        else if (choice == 7)
        {
            cout << "\n  -- ADD DRIVER --" << endl;
            string name;
            int id;

            cout << "Enter Driver Name: ";
            getline(cin, name);
            cout << "Enter Driver ID: ";
            cin >> id;
            cin.ignore();

            RegularDriver d(name, id);
            d.displayInfo();
            d.role();
        }
        else if (choice == 8)
        {
            cout << "\n  -- ROLE CHECKING --" << endl;
            cout << "Check role of:" << endl;
            cout << "1. Passenger" << endl;
            cout << "2. Driver" << endl;
            int r;
            cout << "Enter choice: ";
            cin >> r;
            cin.ignore();

            string name;
            int id;
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            if (r == 1)
            {
                RegularPassenger p(name, id, "Not Specified");
                p.role();
            }
            else if (r == 2)
            {
                RegularDriver d(name, id);
                d.role();
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
        else if (choice == 9)
        {
            cout << "\nReturning to combined metro menu." << endl;
        }
        else
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 9);
}

static void showRawalpindiMenu()
{
    cout << "===========================================================" << endl;
    cout << "             RAWALPINDI  METRO BUS SYSTEM " << endl;
    cout << "===========================================================" << endl;
    cout << "ALL Busses: 10   |  Active On route: 10 | Emergency Buses : 3" << endl;
    cout << "===========================================================" << endl;
    cout << "1. See All the Buses Details" << endl;
    cout << "2. Send Bus to the Maintainence" << endl;
    cout << "3. Emergency Alert Call Emergency Bus" << endl;
    cout << "4. Calculate Fare" << endl;
    cout << "5. Search Bus by ID" << endl;
    cout << "6. Back to main menu" << endl;
    cout << "Enter your choice: ";
}

static void runRawalpindiMetro()
{
    ensureRawalpindiFleets();

    int choice = 0;
    do
    {
        showRawalpindiMenu();
        cin >> choice;

        if (choice == 1)
        {
            int subChoice;
            cout << "1. Metro all buses" << endl;
            cout << "2. Emergency buses" << endl;
            cout << "3. Maintainence Buses" << endl;
            cout << "Enter yours Choice" << endl;
            cin >> subChoice;
            if (subChoice == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (RawalpindiMetroFleet[i])
                        RawalpindiMetroFleet[i]->display();
                }
            }
            else if (subChoice == 2)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (RawalpindiEmergencyFleet[i])
                        RawalpindiEmergencyFleet[i]->display();
                }
            }
            else if (subChoice == 3)
            {
                Vechicle *Maint[2];
                Maint[0] = new Maintenance("M001", "Jabbar", 13, true, "RENEW Tyre", false);
                Maint[1] = new Maintenance("M002", "Itabbar", 13, true, "Petrol jak renew", false);

                for (int i = 0; i < 2; i++)
                {
                    Maint[i]->display();
                }
                for (int i = 0; i < 2; i++)
                {
                    delete Maint[i];
                }
            }
            else
            {
                cout << "invalid Input" << endl;
            }
        }
        else if (choice == 2)
        {
            string busId;
            cout << "Enter the bus ID that we have to send to Maintainence: " << endl;
            cin.ignore();
            getline(cin, busId);
            bool found = false;
            for (int i = 0; i < 10; i++)
            {
                Bus *b = static_cast<Bus *>(RawalpindiMetroFleet[i]);
                if (b && b->vechicleId == busId)
                {
                    Maintenance *m = sendToMaintinence(b);
                    m->display();
                    delete m;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Bus ID not found." << endl;
            }
        }
        else if (choice == 3)
        {
            int emChoice;
            cout << "1. Medical " << endl;
            cout << "2. Fire" << endl;
            cout << "3. BreakDown" << endl;
            cout << "Enter your choice" << endl;
            cin >> emChoice;
            if (emChoice == 1)
            {
                if (RawalpindiEmergencyFleet[0])
                    RawalpindiEmergencyFleet[0]->display();
            }
            else if (emChoice == 2)
            {
                if (RawalpindiEmergencyFleet[1])
                    RawalpindiEmergencyFleet[1]->display();
            }
            else if (emChoice == 3)
            {
                if (RawalpindiEmergencyFleet[2])
                    RawalpindiEmergencyFleet[2]->display();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
        else if (choice == 4)
        {
            int fareChoice;
            cout << "1. Normal Passenger" << endl;
            cout << "2. New Passenger" << endl;
            cout << "3. Rush Hour" << endl;
            cout << "Enter your Fare of the Buses" << endl;
            cin >> fareChoice;
            float baseFare;
            cout << "Enter base fare: ";
            cin >> baseFare;

            if (fareChoice >= 1 && fareChoice <= 3)
            {
                if (fareChoice == 1 || fareChoice == 2)
                {
                    Regularfare rf;
                    cout << "Fare : " << (fareChoice == 1 ? rf.calculateFare(baseFare) : rf.calculateNewPassenger(baseFare)) << endl;
                }
                else if (fareChoice == 3)
                {
                    RushHour rh(20.0f); // 20% charge
                    cout << "Fare :  " << rh.calculateFare(baseFare) << endl;
                }
            }
            else
            {
                cout << "Invalid Choice" << endl;
            }
        }
       else if (choice == 5)
        {
            string searchId;
            cout << "Enter the Bus ID to search: ";
            cin.ignore();
            getline(cin, searchId);
            bool found = false;
            for (int i = 0; i < 10; i++)
            {
                Bus *b = static_cast<Bus *>(RawalpindiMetroFleet[i]);
                if (b && b->vechicleId == searchId)
                {
                    b->display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Bus ID not found." << endl;
            }
        }
        else if (choice == 6)
        {
            cout << "Returning to combined metro menu." << endl;
        }
}

static void runInterCityTripBooking()
{
    cout << "\n========== INTER-CITY TRIP BOOKING ==========" << endl;
    cout << "Book a unified ticket from Peshawar to Rawalpindi" << endl;

    string name;
    int pId, startStopPeshawar, endStopPeshawar;
    float basePindiFare;

    cin.ignore();
    cout << "Enter Passenger Name: ";
    getline(cin, name);
    cout << "Enter Passenger ID: ";
    cin >> pId;

    cout << "\n--- Peshawar Leg ---" << endl;
    Route r;
    r.showRouteDetails();
    cout << "Enter Departure Stop (1-9): ";
    cin >> startStopPeshawar;
    cout << "Enter Connection Stop (1-9): ";
    cin >> endStopPeshawar;

    RegularPassenger p(name, pId, "N/A");
    p.calculatefare(startStopPeshawar, endStopPeshawar);
    int peshawarFare = 100 - 100;
    int dist = abs(endStopPeshawar - startStopPeshawar);
    int pFare = (dist <= 2) ? 30 : (dist <= 5 ? 60 : 70);

    cout << "\n--- Rawalpindi Leg ---" << endl;
    cout << "Enter the base fare for Rawalpindi terminal journey (e.g. 50): ";
    cin >> basePindiFare;
    Regularfare rf;
    float rFare = rf.calculateFare(basePindiFare);

    float totalFare = pFare + rFare;
    float discountFare = totalFare * 0.90f; // 10% Inter-City Discount

    cout << "\n*** Inter-City Ticket Confirmed ***" << endl;
    cout << "Passenger: " << name << " (ID: " << pId << ")" << endl;
    cout << "Peshawar Fare: Rs " << pFare << endl;
    cout << "Rawalpindi Fare: Rs " << rFare << endl;
    cout << "Total Fare: Rs " << totalFare << endl;
    cout << "Discounted Inter-City Fare: Rs " << discountFare << endl;
    cout << "Have a safe journey!" << endl;
}

static void runAnalyticsDashboard()
{
    ensureRawalpindiFleets();

    cout << "\n========== SYSTEM-WIDE ANALYTICS DASHBOARD ==========" << endl;

    cout << "[Peshawar Smart Metro System]" << endl;
    DriverBusSystem pDbs;
    cout << " - Total Registered Routes: 1 (9 Stops)" << endl;
    cout << " - Total Active Buses: 12" << endl;
    cout << " - Total Active Drivers: 12" << endl;

    cout << "\n[Rawalpindi Metro Bus System]" << endl;
    int rwpActive = 0, rwpCapacity = 0;
    for (int i = 0; i < 10; i++)
    {
        if (RawalpindiMetroFleet[i])
        {
            rwpActive++;
            rwpCapacity += RawalpindiMetroFleet[i]->capacity;
        }
    }
    cout << " - Total Active Buses: " << rwpActive << endl;
    cout << " - Total Passenger Capacity: " << rwpCapacity << endl;
    cout << " - Emergency Vehicles on Standby: 3" << endl;

    cout << "=====================================================" << endl;
}

int main()
{
    int sys = 0;
    do
    {
        cout << "\n========== COMBINED METRO SYSTEM ==========" << endl;
        cout << "1. Peshawar Smart Metro Bus Management" << endl;
        cout << "2. Rawalpindi Metro Bus System" << endl;
        cout << "3. Inter-City Trip Booking (NEW)" << endl;
        cout << "4. Analytics Dashboard (NEW)" << endl;
        cout << "5. Exit" << endl;
        cout << "Select system: ";
        cin >> sys;

        if (sys == 1)
        {
            runPeshawarMetro();
        }
        else if (sys == 2)
        {
            runRawalpindiMetro();
        }
        else if (sys == 3)
        {
            runInterCityTripBooking();
        }
        else if (sys == 4)
        {
            runAnalyticsDashboard();
        }
        else if (sys == 5)
        {
            cout << "Cleaning up resources..." << endl;
            cleanupRawalpindiFleets();
            cout << "Thank you. Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    } while (sys != 5);

    return 0;
}
