# 🚍 Transport-reservation-system-cpp
A C++ console-based transport reservation system that allows users to add buses, make and cancel reservations, and view booking details with file handling. Designed for Programming Fundamentals project.

---

## 📝 Project Introduction

### 🧭 Background / Need of the Project

The **Transport Reservation System** offers numerous benefits for both passengers and transport companies.  
By enabling passengers to book and manage their bus tickets, the system provides a convenient and hassle-free experience.

This not only saves time for passengers but also streamlines the ticketing process and improves efficiency for transport companies.  
Additionally, it provides valuable data related to buses, passengers, routes, and schedules.

---

## 🎯 Goals & Objectives

- To create a comprehensive transport management system.
- To provide a convenient, efficient, and accurate way for passengers to:
  - Book and manage transport tickets
  - Search for available buses
  - View schedules and seat availability
  - Receive booking confirmation
- To streamline the ticketing process through automation
- To provide accurate arrival and departure times

---

## 📌 Scope of the Project

This system will allow users to:
- Search for available buses
- View bus schedules, departure and arrival times
- Select seats
- Receive booking confirmations

---

## 👥 Target Users

The system is designed for anyone involved in the transportation system, including:
- Passengers
- Transport companies
- Administrators
- Customer service representatives

It aims to provide a smooth and seamless experience for all types of users.

---

## 💬 Key Features (Discussion)

- 🚌 **Add Transport Record**: Add ride number, ride name, total seats, and driver name
- 📋 **View Transport Details**: View single ride or all rides
- ✏️ **Update Transport Record**: Modify ride details (name, number, driver, seats)
- ❌ **Delete Transport Record**: Remove a ride by its ID
- 🌍 **View Routes**: Show predefined routes with arrival and departure times
- 🎫 **Book Ticket**: Collect booking number, ride number, passenger info, and seat count
- 🔁 **Cancel Booking**: Cancel a reservation using booking number

---



---

## 📊 System Algorithm

Below is the step-by-step logic of the **Transport Reservation System** implemented in C++ with file handling and vectors.

---

### 🧠 Main Flow (in `main()` function)

1. Load bus and reservation data from files
2. Continuously show the main menu until the user exits
3. Take user choice and call the respective function:
   - Add New Bus
   - View All Buses
   - Make Reservation
   - View Reservations
   - Cancel Reservation
   - Search Bus
   - Exit
4. On exit, save data back to files

---

### 📋 Menu Options and Their Algorithms

### 🔹 Add New Bus
- Input: Bus number, driver name, departure & arrival time, locations, total seats
- Validate if bus number is unique
- Add data to vectors
- Initialize seat status vector with `false` values (unbooked)
- Save data to `buses.txt`

---

### 🔹 View All Buses
- If no buses: Display message
- Else: Display all bus details in a table format

---

### 🔹 Make Reservation
- Input: Bus number
- If valid and has available seats:
  - Display all unbooked seats
  - Input seat number and validate
  - Input passenger name and travel date
  - Mark seat as booked (`true`)
  - Decrease available seat count
  - Add passenger info to reservation vectors
  - Save to `reservations.txt`

---

### 🔹 View Reservations
- If no data: Show message
- Else: Display bus number, passenger name, seat number, travel date

---

### 🔹 Cancel Reservation
- Input: Bus number and seat number
- If matching record found:
  - Mark seat as unbooked (`false`)
  - Increase available seat count
  - Remove reservation from vectors
  - Save data
- Else: Show "not found" message

---

### 🔹 Search Bus
- Two options:
  1. By **Bus Number** → Display full bus details if found
  2. By **Route** (From → To) → Display all matching buses

---

## 💾 File Handling

### ✅ Files Used
- `buses.txt` — Stores all bus data
- `reservations.txt` — Stores all booking/reservation data

### 🔁 When Data is Loaded/Saved
- **Load**: When program starts (`main()`)
- **Save**: After any change (add, book, cancel)

---

## 📚 Data Structures Used

| Vector Name | Purpose |
|-------------|---------|
| `busNumbers` | Stores bus numbers |
| `driverNames` | Stores driver names |
| `departureTimes`, `arrivalTimes` | Stores schedule |
| `fromLocations`, `toLocations` | Stores route info |
| `totalSeats`, `availableSeats` | Tracks capacity |
| `seatStatus` | Tracks if each seat is booked |
| `reservationBusNumbers`, `passengerNames`, `seatNumbers`, `travelDates` | Stores reservation details |

---


## ⚠️ Limitations

2. Uses text files for data storage (not scalable)
3. No transaction management — not safe for concurrent users
4. Command-line interface (no GUI)
5. May not perform well under high data load
6. Code is not modular, making future updates harder

---

## 🚀 Future Work

To improve the Transport Reservation System, we plan to:

- 💬 Add a **feedback and rating system** for passengers
- 📞 Implement a **customer support system** for queries and complaints
- 🚗 Expand support for various ride types:
  - Tour Buses
  - Taxis
  - Flights
  - Trains
  - Inter-city Buses
 
  ---

## 🙋‍♀️ About the Developer

**👩‍💻 Name:** Nasiha Mehmood-ul-Hassan 
**🎓 Role:** BSCS Student, Govt College University Faisalabad (Chiniot Campus)  
**🔗 LinkedIn:** Nasiha Mehmood-ul-Hassan(https://www.linkedin.com/in/nasiha-hassan/))  
**📧 Email:** nasihamehmood206@gmail.com  

