Description

This project is a simple Patient Priority Queue program written in C.

The program decides which patient should be treated next based on their priority number.

Priority Rules

- Priority 1 = Emergency
- Priority 2 = Urgent
- Priority 3 = Routine

A smaller priority number means higher priority. Therefore, an Emergency patient is always treated before an Urgent or Routine patient.

Features

The program has two main functions:

1. Add Patient
   
   - Adds a patient to the queue.
   - Stores the patient's name and priority number.

2. Treat Next Patient
   
   - Finds the patient with the highest priority.
   - Displays the patient being treated.
   - Removes the patient from the queue.

Test Case 1

The following patients are added:

Patient| Priority
P1| 3
P2| 1
P3| 2
P4| 1
P5| 3
P6| 2

Treatment Order

P2 → P4 → P3 → P6 → P1 → P5

The Emergency patients (priority 1) are treated first, followed by Urgent patients (priority 2), and then Routine patients (priority 3).

Test Case 2

After treating the first three patients:

P2 → P4 → P3

The remaining patients are:

P6 → Priority 2
P1 → Priority 3
P5 → Priority 3

A new Emergency patient is then added:

P7 → Priority 1

New Treatment Order

P7 → P6 → P1 → P5

This confirms that the new Emergency patient P7 moves ahead of the patients who were already waiting.

Concepts Used

- Structures in C
- Arrays
- Functions
- Priority Queue
- Searching
- Removing an element from an array
- "if" conditions
- "for" loops
