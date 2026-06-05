#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

// Block Data Structure
typedef struct Block {
    int index;
    long timestamp;
    char data[256];
    char prev_hash[65];
    char current_hash[65];
    struct Block* next;
} Block;

// Function Prototypes
void calculate_hash(int index, long timestamp, const char* data, const char* prev_hash, char* output);
Block* create_block(int index, const char* data, const char* prev_hash);
int is_chain_valid(Block* head);
void free_blockchain(Block* head);

#endif // BLOCKCHAIN_H
