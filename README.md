# Operating-Systems-Assignment-2
This is my submission for Assignment #2 for Operating Systems

Here is the summary of the instructions:
 
Banker’s Algorithm for deadlock avoidance.

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:

 <img width="468" alt="Picture1" src="https://github.com/user-attachments/assets/3aa721dd-5411-423f-bd1a-783e0f765e95" />

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

# Compilation Instructions
In order to run this code, please clone this repository and input these instructions:
```
g++ -o banker banker.cpp
./banker
```

# Example output
The output should look something like this:
```
Allocation:
P0: [0, 1, 0]
P1: [2, 0, 0]
P2: [3, 0, 2]
P3: [2, 1, 1]
P4: [0, 0, 2]
Max:
P0: [7, 5, 3]
P1: [3, 2, 2]
P2: [9, 0, 2]
P3: [2, 2, 2]
P4: [4, 3, 3]
Available: [3, 3, 2]
The system is in a safe state, the safe sequence is: P1, P3, P0, P2, P4
```
