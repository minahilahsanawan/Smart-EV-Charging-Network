# Smart EV Charging Network

A city-scale intelligent EV charging ecosystem simulator developed in C++ using Object-Oriented Programming (OOP) principles. The system models realistic EV charging infrastructure with distributed charging stations, multiple dock types, renewable-aware energy allocation, smart booking workflows, dynamic billing, load optimization, analytics reporting, and digital invoice generation.

---

## Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
- [System Capabilities](#system-capabilities)
- [Object-Oriented Design](#object-oriented-design)
- [Main Classes and Responsibilities](#main-classes-and-responsibilities)
- [System Architecture](#system-architecture)
- [Booking Workflow](#booking-workflow)
- [Dock Assignment](#dock-assignment)
- [Load Optimization](#load-optimization)
- [Renewable-Aware Energy Selection](#renewable-aware-energy-selection)
- [Dynamic Pricing and Billing Model](#dynamic-pricing-and-billing-model)
- [Digital Invoice Generation](#digital-invoice-generation)
- [Analytics and Reporting](#analytics-and-reporting)
- [Input Validation Strategy](#input-validation-strategy)
- [Data Persistence](#data-persistence)
- [Technologies Used](#technologies-used)
- [Requirements](#requirements)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [Repository Structure](#repository-structure)
- [Assumptions](#assumptions)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Authors](#authors)

---

## Overview

The **Smart EV Charging Network** is a menu-driven C++ application that simulates the operation of an intelligent electric vehicle charging ecosystem. The project models how users, vehicles, charging stations, charging docks, bookings, energy sources, invoices, notifications, and analytics can interact inside one complete software system.

The application is designed to represent a realistic EV charging network where charging decisions are not made randomly. Instead, the system considers vehicle battery state, connector compatibility, user priority, dock availability, station capacity, renewable energy availability, charging speed, peak-hour demand, and pricing factors before completing a charging session.

This project is more than a basic record-management program. It is a structured engineering simulation that combines object-oriented programming, resource allocation, load management, dynamic billing, renewable energy preference, and operational reporting.

---

## Key Features

### User Management

- Register users with unique IDs.
- Store user names, membership levels, and priority levels.
- Link one or more EVs to each user.
- Maintain user-specific notifications.
- Support different service levels through membership categories.

### Electric Vehicle Management

- Register EVs under specific users.
- Store EV model, vehicle type, battery capacity, current SOC, maximum charging rate, and connector type.
- Calculate energy required to reach full charge.
- Update SOC after charging completion.
- Include future-ready V2G support fields.

### Charging Station Management

- Create and manage multiple charging stations.
- Store station name, location, grid capacity, current active load, docks, and energy sources.
- Display station status, dock availability, and energy source information.
- Support scalable station-level infrastructure modeling.

### Charging Dock Management

- Add slow, medium, and fast charging docks.
- Store dock power rating and connector type.
- Track dock status as available or occupied.
- Assign and release EVs from docks.
- Prevent incompatible dock assignments.

### Booking Management

- Create charging bookings for registered users and EVs.
- Store requested start hour, duration, station, requested energy, and booking status.
- Process pending and deferred bookings.
- Support active, completed, deferred, and cancelled booking states.
- Apply cancellation penalties where needed.

### Smart Dock Allocation

The system does not simply assign the first free dock. It uses a scoring-based selection strategy that considers:

- EV state of charge
- User priority
- Vehicle type
- Maximum charging rate
- Connector compatibility
- Dock power rating
- Dock availability

### Load Optimization

The system monitors station load and prevents overload by checking the current active load against station grid capacity. If a preferred dock causes overload, the system handles the situation based on urgency:

- Urgent users may be assigned to a lower-power compatible safe dock.
- Non-urgent users may be deferred to an off-peak hour.

### Renewable-Aware Energy Selection

The system supports different energy sources:

- Grid Power
- Solar Power
- Wind Power

When possible, the system prioritizes renewable energy sources before falling back to other available sources.

### Dynamic Pricing

The billing engine calculates a final rate using multiple pricing factors:

- Source cost
- Peak or off-peak timing
- Charging speed
- Renewable or grid source
- Membership level

### Digital Invoice Generation

The system generates a detailed invoice after a charging session is completed. Each invoice includes:

- Invoice ID
- Booking ID
- Energy consumed
- Session duration
- Energy source
- Rate per kWh
- Pricing factor breakdown
- Total amount

Invoices are also saved to a file for record keeping.

### Analytics and Reporting

The analytics engine provides operational insights such as:

- Total dock utilization
- Occupied and available docks
- Renewable energy usage
- Grid energy usage
- Energy mix ratio
- Peak vs off-peak demand
- Completed sessions
- Deferred bookings
- Cancelled bookings
- Revenue generation
- Estimated CO2 savings

---

## System Capabilities

The system can perform the following operations:

1. Register a new user.
2. Register a new EV and link it to a user.
3. Add a new charging station.
4. Add docks to a charging station.
5. Add energy sources to a station.
6. Display registered users and vehicles.
7. Display charging station details.
8. Create a charging booking.
9. Process bookings based on station capacity and dock availability.
10. Complete charging sessions.
11. Generate digital invoices.
12. Cancel bookings.
13. Show user notifications.
14. Generate analytics reports.
15. Save invoice records to a text file.

---

## Object-Oriented Design

The project is built using object-oriented programming principles. Each class has a clear responsibility, and the overall design avoids placing all logic inside a single function.

### Encapsulation

Class data is kept private or protected where appropriate. The system uses controlled access through getter functions and update methods. This protects internal object state and makes the program easier to maintain.

Examples include:

```cpp
getId()
getCurrentSOC()
updateSOC()
setDockAndPower()
setEnergySource()
addLoad()
removeLoad()
```

### Inheritance

The energy source system uses inheritance. A common base class represents general energy source behavior, while derived classes represent specific source types.

```text
EnergySource
+-- GridPower
+-- SolarPower
`-- WindPower
```

### Polymorphism

The program uses polymorphism through base-class pointers:

```cpp
shared_ptr<EnergySource>
```

This allows charging stations to store and process different energy source types through one common interface.

### Modularity

Each class handles a specific part of the system. For example:

- `EV` handles vehicle data.
- `User` handles user data and notifications.
- `ChargingDock` handles dock state.
- `ChargingStation` handles dock selection and source selection.
- `Booking` handles session workflow state.
- `Invoice` handles billing output.
- `SmartEVChargingNetwork` coordinates the complete application.

---

## Main Classes and Responsibilities

| Class | Responsibility |
|---|---|
| `InputHelper` | Handles safe and validated input reading. |
| `EV` | Stores electric vehicle details and charging-related data. |
| `User` | Stores user profile, membership, priority, owned EVs, and notifications. |
| `EnergySource` | Base class for all energy sources. |
| `GridPower` | Represents non-renewable grid energy. |
| `SolarPower` | Represents renewable solar energy. |
| `WindPower` | Represents renewable wind energy. |
| `ChargingDock` | Stores dock type, power rating, connector, and availability status. |
| `ChargingStation` | Manages station docks, energy sources, load checking, and dock/source selection. |
| `Booking` | Stores booking details and booking status. |
| `Invoice` | Stores billing information and generates invoice output. |
| `SmartEVChargingNetwork` | Main controller that manages users, EVs, stations, bookings, invoices, analytics, and menu operations. |

---

## System Architecture

The system follows a controller-based architecture. The main controller class manages collections of users, vehicles, stations, bookings, and invoices.

```text
SmartEVChargingNetwork
|
+-- Users
|   `-- Electric Vehicles
|
+-- Charging Stations
|   +-- Charging Docks
|   `-- Energy Sources
|       +-- Grid Power
|       +-- Solar Power
|       `-- Wind Power
|
+-- Bookings
|   +-- Pending
|   +-- Active
|   +-- Deferred
|   +-- Completed
|   `-- Cancelled
|
+-- Invoices
+-- Notifications
`-- Analytics Reports
```

---

## Booking Workflow

A typical booking moves through the following workflow:

```text
Create Booking
      ↓
Validate User, EV, and Station
      ↓
Find Compatible Dock
      ↓
Check Station Load Capacity
      ↓
Select Energy Source
      ↓
Activate Booking
      ↓
Complete Charging Session
      ↓
Generate Invoice
      ↓
Update EV SOC, Energy Source, Station Load, and Analytics
```

### Booking States

```text
Pending → Active → Completed
Pending → Deferred
Pending → Cancelled
Deferred → Active → Completed
Deferred → Cancelled
```

---

## Dock Assignment

The dock assignment algorithm is one of the most important parts of the system.

The system first determines the desired charging power based on:

- User priority
- EV state of charge
- EV maximum charging rate

Then the system checks each dock and rejects docks that are:

- Already occupied
- Incompatible with the EV connector
- Not suitable for the vehicle type

After filtering, the system calculates a score for each available compatible dock. The dock with the lowest score is selected.

### Assignment Considerations

- High-priority users are treated as more urgent.
- Low-SOC vehicles are treated as more urgent.
- Bikes are discouraged from using unnecessarily high-power docks.
- Vans are discouraged from using very slow docks.
- Buses are directed toward fast docks when available.
- Low-priority users with high SOC are discouraged from occupying fast chargers.

This improves fairness, safety, and charging efficiency.

---

## Load Optimization

Before a booking becomes active, the system checks whether the station can safely accept the additional load.

```text
Current Station Load + Dock Power <= Station Grid Capacity
```

If the station can accept the load, the booking becomes active.

If not, the system applies a decision strategy:

### Urgent Booking

For urgent cases, the system attempts to find a compatible lower-power dock that does not overload the station.

### Non-Urgent Booking

For non-urgent cases, the booking is deferred to an off-peak hour.

This approach protects the station from overload while still trying to serve urgent users.

---

## Renewable-Aware Energy Selection

Each charging station can have multiple energy sources. The system selects an energy source using a preference-based method.

Selection priority:

1. Use renewable energy if preferred and sufficient.
2. Use any available source with enough energy.
3. Use any partially available source if no complete source is available.
4. Defer the booking if no energy source is available.

This supports sustainable charging behavior and encourages renewable energy usage.

---

## Dynamic Pricing and Billing Model

The billing system uses a multi-factor pricing model instead of a fixed rate.

### Final Rate Formula

```text
Final Rate per kWh = Source Cost × Time Factor × Speed Factor × Source Factor × Membership Factor
```

### Total Amount Formula

```text
Total Amount = Energy Consumed × Final Rate per kWh
```

### Time Factor

| Condition | Factor |
|---|---:|
| Peak hour | 1.50 |
| Off-peak hour | 1.00 |

### Speed Factor

| Charging Type | Factor |
|---|---:|
| Fast | 1.40 |
| Medium | 1.20 |
| Slow | 1.00 |

### Source Factor

| Source Type | Factor |
|---|---:|
| Renewable | 0.90 |
| Grid | 1.00 |

### Membership Factor

| Membership | Factor |
|---|---:|
| VIP | 0.80 |
| Premium | 0.90 |
| Regular | 1.00 |

---

## Digital Invoice Generation

After a charging session is completed, the system generates a digital invoice. The invoice includes a complete billing breakdown so that the user can understand how the final amount was calculated.

Example invoice fields:

```text
Invoice ID
Booking ID
Energy Consumed
Session Duration
Energy Source
Rate Per kWh
Time Factor
Speed Factor
Source Factor
Membership Factor
Total Amount
```

The invoice is printed on screen and saved to:

```text
invoices.txt
```

---

## Analytics and Reporting

The analytics module helps evaluate the performance of the charging network.

It can report:

- Total docks
- Occupied docks
- Station utilization percentage
- Average session duration
- Renewable energy used
- Grid energy used
- Energy source mix
- Peak-hour demand count
- Off-peak demand count
- Total completed bookings
- Total deferred bookings
- Total cancelled bookings
- Total revenue
- Estimated CO2 savings

### CO2 Savings Estimate

```text
Estimated CO2 Savings = Total Renewable Energy Used × 0.50
```

This provides a simple sustainability indicator for the network.

---

## Input Validation Strategy

The project includes an `InputHelper` class that centralizes safe input handling.

It validates:

- Empty text input
- Integer ranges
- Decimal ranges
- Membership values
- Connector types
- Dock types
- Yes/no responses

This improves program reliability and prevents invalid data from breaking the workflow.

---

## Data Persistence

The system writes generated invoice records to a text file using file handling.

Current output file:

```text
invoices.txt
```

The file is opened in append mode, which means previous invoices are preserved when new invoices are generated.

---

## Technologies Used

- C++
- Object-Oriented Programming
- STL `vector`
- `shared_ptr`
- File handling with `fstream`
- Console-based menu system
- Input validation
- Modular class architecture

---

## Requirements

To compile and run this project, you need:

- C++ compiler supporting C++11 or higher
- GCC/G++ or any standard C++ IDE
- Terminal, command prompt, or integrated IDE console

Recommended compiler:

```text
g++ 9.0 or higher
```

---

## How to Compile

### Linux / macOS

```bash
g++ final.cpp -o smart_ev_charging_network
```

### Windows using MinGW

```bash
g++ final.cpp -o smart_ev_charging_network.exe
```

### With C++11 Standard Flag

```bash
g++ -std=c++11 final.cpp -o smart_ev_charging_network
```

---

## How to Run

### Linux / macOS

```bash
./smart_ev_charging_network
```

### Windows

```bash
smart_ev_charging_network.exe
```

---

## Repository Structure

```text
Smart-EV-Charging-Network/
|
+-- final.cpp
+-- README.md
+-- invoices.txt
`-- screenshots/
    +-- main-menu.png
    +-- station-details.png
    +-- booking-processing.png
    +-- invoice-output.png
    `-- analytics-report.png
```

### File Descriptions

| File / Folder | Description |
|---|---|
| `final.cpp` | Main C++ source code for the complete system. |
| `README.md` | Complete GitHub documentation for the project. |
| `invoices.txt` | Output file generated after invoice creation. |
| `screenshots/` | Optional folder for program output screenshots. |

---

## Assumptions

The simulation is based on the following assumptions:

- Charging stations are managed through a console-based operator interface.
- Energy source availability is manually configured or initialized in the program.
- Peak hours are predefined in the system logic.
- Pricing factors are fixed in the current version.
- Charging sessions are completed through user/menu interaction rather than real-time hardware signals.
- CO2 savings are estimated using a simplified factor.
- V2G and external API integration are represented as future-ready placeholders.

---

## Limitations

Current limitations include:

- Console-based interface only
- No graphical user interface
- No real-time cloud connectivity
- No database backend
- No live GPS or map integration
- No real payment gateway
- No real IoT charger communication
- No real-time weather-based renewable forecasting
- Simplified load and pricing model
- Text-file invoice storage only

---

## Future Improvements

The project can be extended in several professional directions:

- Add a graphical user interface.
- Integrate a database such as MySQL, SQLite, or PostgreSQL.
- Add real-time station monitoring.
- Add map-based nearest station search.
- Implement AI-based demand prediction.
- Connect renewable forecasting APIs.
- Add payment gateway support.
- Add user login and authentication.
- Add admin and customer dashboards.
- Implement cloud-based data synchronization.
- Add real IoT charger integration.
- Expand V2G support.
- Add mobile application support.
- Add detailed carbon footprint reporting.
- Add advanced scheduling optimization.

---

## Authors

- Minahil Ahsan Awan
- Saleha Wasim
- Bushra Ushaq