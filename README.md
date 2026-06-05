# BitCore-Ledger-C

A deep-dive into the foundational data structures of blockchain technology using the C programming language. This project strips away high-level abstractions to implement a strict cryptographic linked list, complete with dynamic memory management.

## 🚀 Key Features
* **Manual Memory Management:** Efficient allocation and deallocation of blocks using `malloc` and `free` to prevent leaks.
* **Cryptographic Linked List:** Each node structurally points to the hash of the preceding node.
* **Data Integrity Checks:** Embedded validation function to trace and verify the ledger's entire state.

## 🛠️ Tech Stack & Concepts
* **Language:** Pure C (C99 Standard)
* **Concepts:** Pointers, Dynamic Memory Allocation, Singly Linked Lists, Data Serialization.

## 📦 How to Run
Compile all modules using GCC and link the OpenSSL crypto library:
```bash
gcc main.c blockchain.c -o bitcore_ledger -lcrypto
./bitcore_ledger
