#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>
#include "blockchain.h"

// Compiles internal block attributes into a unique SHA-256 string
void calculate_hash(int index, long timestamp, const char* data, const char* prev_hash, char* output) {
    char input[1024];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    
    sprintf(input, "%d%ld%s%s", index, timestamp, data, prev_hash);
    SHA256((unsigned char*)input, strlen(input), hash);
    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[64] = '\0';
}

// Allocates memory heap for a node and hashes it into the chain
Block* create_block(int index, const char* data, const char* prev_hash) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    if (new_block == NULL) {
        fprintf(stderr, "Fatal: Memory allocation failed.\n");
        exit(1);
    }
    
    new_block->index = index;
    new_block->timestamp = (long)time(NULL);
    strncpy(new_block->data, data, sizeof(new_block->data) - 1);
    strncpy(new_block->prev_hash, prev_hash, sizeof(new_block->prev_hash) - 1);
    new_block->next = NULL;
    
    calculate_hash(new_block->index, new_block->timestamp, new_block->data, new_block->prev_hash, new_block->current_hash);
    
    return new_block;
}

// Iterates through the singly linked list checking pointers and states
int is_chain_valid(Block* head) {
    Block* current = head;
    char recompiled_hash[65];
    
    while (current != NULL && current->next != NULL) {
        Block* next_block = current->next;
        
        if (strcmp(current->current_hash, next_block->prev_hash) != 0) {
            return 0; // Hash link broken
        }
        
        calculate_hash(current->index, current->timestamp, current->data, current->prev_hash, recompiled_hash);
        if (strcmp(current->current_hash, recompiled_hash) != 0) {
            return 0; // Content data modified
        }
        
        current = current->next;
    }
    return 1;
}

// Recursively walks the ledger to free heap elements safely
void free_blockchain(Block* head) {
    Block* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
