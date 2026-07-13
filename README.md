# Smart Metro Bus Management System

A C++ OOP console application that simulates a combined metro bus network across two cities
(Peshawar and Rawalpindi), including passenger management, driver/bus allocation, fare
calculation, emergency vehicle handling, inter-city ticket booking, and a system-wide
analytics dashboard.

Originally built as a semester OOP project; this repository demonstrates a professional
Git/GitHub workflow applied on top of that codebase.

## Features

- **Peshawar Smart Metro**: route/schedule viewing, driver-bus allocation, passenger check-in
  (regular, VIP, disabled), role checking.
- **Rawalpindi Metro Bus System**: fleet display (metro/emergency/maintenance), send-to-maintenance,
  emergency dispatch (medical/fire/breakdown), fare calculation (regular/new passenger/rush hour).
- **Inter-City Trip Booking**: unified fare calculation across both cities with a discount.
- **Analytics Dashboard**: system-wide stats across both networks.

## Technology

- Language: C++ (single translation unit `main.cpp` + header `MetroSystem.h`)
- No external dependencies — standard library only (`<iostream>`, `<string>`)

## Project structure

```
.
├── main.cpp          # Entry point, menus, and city-specific logic
├── MetroSystem.h      # All class definitions (Vehicle, Bus, Passenger, Driver, Fare hierarchy, etc.)
├── .github/           # Issue templates, PR template, CI workflow
├── docs/              # Assignment notes
├── CHANGELOG.md
└── CONTRIBUTING.md
```

## How to build and run

### Windows (g++ / MinGW)
```bash
g++ -std=c++17 -o metro_system.exe main.cpp
./metro_system.exe
```

### Windows (Code::Blocks / Visual Studio)
Open the project and build normally; `main.cpp` is the entry point.

## How to validate

There is no automated test suite (console-driven OOP project). Validation is manual:
1. Build with no compiler errors or warnings.
2. Run the executable and walk through each menu option (1–5 in main menu).
3. Confirm passenger fare deduction, bus search, and analytics numbers are correct.

See `docs/assignment.md` for the specific checklist used during this assignment.

## Class overview

| Class | Role |
|---|---|
| `Vechicle` | Abstract base for all vehicles |
| `Bus`, `RegularMetroBus`, `Express` | Bus hierarchy |
| `Maintenance`, `Emergency`, `Medical`, `BreakDown`, `Fire` | Non-passenger service vehicles |
| `FareSystem`, `Regularfare`, `RushHour` | Fare calculation strategies |
| `Person`, `Passenger`, `RegularPassenger`, `Disabled`, `VIP`, `Driver`, `RegularDriver` | People hierarchy |
| `Route`, `Schedule`, `DriverBusSystem` | Supporting data/service classes |

## License

Personal academic project — for learning purposes.
Maintained by: Sameer (A)
