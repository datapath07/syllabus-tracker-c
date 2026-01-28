# Syllabus Tracker (C Project)

This is my first C project built using file handling and structures.  
It helps track syllabus topics and their completion status (not started, ongoing, completed).

The program stores data in a binary file and allows the user to:
- View syllabus
- Check the status of a particular topic
- Update uncovered topics with start and end dates

---

## Features
- View complete syllabus unit-wise  
- Check status of a particular topic  
- Update uncovered topics  
- Stores data persistently using a binary file (`PROJECT.bin`)  

---

## Technologies Used
- C Language  
- File Handling  
- Structures  
- Arrays  

---

## Project Files
- `MAINPROJECT.c` → Main program  
- `fileopen.h` → File handling function  
- `init.c` → Initializes and creates `PROJECT.bin`  
- `PROJECT.bin` → Binary file that stores syllabus data  

---

## How to Run

### Step 1: Clone the repository
```bash
git clone <your-repo-link>
cd <your-repo-folder>
