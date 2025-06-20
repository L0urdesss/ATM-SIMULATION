# 🏧 ATM-SIMULATION

**Application of ADT LIST Operations**

A C++ program that simulates an ATM system using ADT List operations, with support for registration and transaction modules. It uses a flash drive as an ATM card and stores encrypted PIN codes for security.

---

## 📌 Requirements

- Use **ADT LIST Operations** in **array** or **linked list** (C or C++)
- 2 Modules:
  - **Registration Module** – Opening new ATM account
  - **Transaction Module**:
    - Balance Inquiry
    - Withdraw
    - Deposit
    - Fund Transfer (enrolled accounts only)
    - Change PIN Code
    - Other transactions (optional)

- Use **Flash Drive as ATM Card**
- PIN code is **encrypted** and stored:
  - In the flash drive (`pin.code`)
  - In the internal list (for validation)

---

## 🧠 Features

- Encrypted PIN code support
- Flash drive detection and validation
- Registration and full transaction processing
- Cross-checking of PIN between flash and list
- List stores full account info

---

## 📋 Account Information Stored

- 5-digit Account Number  
- Account Name  
- Birthday  
- Contact Number  
- Initial Deposit (min. ₱5000)  
- PIN Code (Encrypted)  

---

## 🔐 PIN Code Rules

- 4 to 6 digits  
- Must press **ENTER** to confirm input  
- Stored in both flash drive and list  

---

## 💳 Flash Drive ATM Card

- Program checks for `pin.code` file in flash drive
- If not found:  
  `Please insert card.`

---

## 🛠 Technologies Used

- C++ (OOP or Procedural)
- ADT List (Array or Linked List)
- File I/O for card detection and data storage
- Basic encryption for PIN codes

---

## ▶️ How to Run

1. Insert flash drive with a valid or empty `pin.code` file  
2. Compile:

