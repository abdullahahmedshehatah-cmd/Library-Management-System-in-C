# 📚 Library Management System

A modular **Library Management System** developed in **C** that demonstrates core programming concepts including modular design, file handling, structures, and menu-driven applications.

The system enables administrators and users to efficiently manage library operations through a simple command-line interface while persisting data using local storage.

---

## 📖 Overview

This project was developed as a practical implementation of fundamental Computer Science concepts in the C programming language. It follows a modular architecture where each component is responsible for a specific functionality, making the project easy to understand, maintain, and extend.

---

## ✨ Features

### 👨‍💼 Administrator

- Add new books
- Update book information
- Delete books
- Search books
- View complete inventory

### 👤 User

- Browse available books
- Search by title
- Borrow books
- Return books

### 💾 Data Management

- Persistent storage using file handling
- Automatic data loading on startup
- Automatic data saving after modifications

---

## 🏗️ Project Structure

```
Library-Management-System/
│
├── main.c
├── admin.c
├── admin.h
├── user.c
├── user.h
├── book.c
├── book.h
├── data_handler.c
├── data_handler.h
├── README.md
└── data/
```

---

## 🛠️ Technologies Used

- C Programming Language
- GCC Compiler
- Standard C Library
- File Handling
- Modular Programming

---

## 🚀 Getting Started

### Prerequisites

Before running the project, make sure you have:

- GCC Compiler
- Visual Studio Code (Recommended)
- Code::Blocks (Optional)
- MinGW-w64 (Windows)

---

## 📥 Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/Library-Management-System.git
```

Navigate to the project directory:

```bash
cd Library-Management-System
```

---

## ⚙️ Build

Compile all source files using GCC:

```bash
gcc *.c -o LibrarySystem
```

Or compile explicitly:

```bash
gcc main.c admin.c user.c book.c data_handler.c -o LibrarySystem
```

---

## ▶️ Run

### Windows

```bash
LibrarySystem.exe
```

or

```bash
.\LibrarySystem.exe
```

### Linux / macOS

```bash
./LibrarySystem
```

---

## 📷 Application Workflow

```
Start Program
      │
      ▼
 Main Menu
      │
 ┌────┴────┐
 │         │
 ▼         ▼
Admin     User
 │         │
 ▼         ▼
Manage   Borrow
Books    Return
 │         │
 └────┬────┘
      ▼
 Save Data
      │
      ▼
 Exit
```

---

## 📚 Programming Concepts Demonstrated

- Structures (`struct`)
- Functions
- Header Files
- Modular Programming
- File Handling
- Arrays
- Conditional Statements
- Loops
- Menu-Driven Applications

---

## 📈 Future Improvements

- User Authentication
- Password Encryption
- Book Categories
- Due Date Tracking
- Fine Calculation
- Search by Author
- ISBN Management
- Database Integration (MySQL/SQLite)
- Graphical User Interface (GUI)

---

## 🤝 Contributing

Contributions are welcome!

If you'd like to improve the project:

1. Fork the repository
2. Create a feature branch

```bash
git checkout -b feature/new-feature
```

3. Commit your changes

```bash
git commit -m "Add new feature"
```

4. Push your branch

```bash
git push origin feature/new-feature
```

5. Open a Pull Request

---

## 📄 License

This project is released under the MIT License.

Feel free to use, modify, and distribute it for educational purposes.

---

## 👨‍💻 Author

**Abdullah Ahmed**

Computer Science Student

- 💼 Interested in Software Development
- 📱 Mobile Device Repair & Embedded Systems
- 🌐 Open Source Contributor

---

## ⭐ Support

If you found this project useful, consider giving it a **⭐ Star** on GitHub.

It helps others discover the project and motivates future development.

---

## 📬 Contact

Feel free to connect or open an issue if you have any questions or suggestions.
