#include <stdio.h>
#include "blockchain.h"

int main() {
    printf("🛠️  Initializing Modular BitCore-Ledger-C Ecosystem...\n\n");
    
    // 1. Instantiating Genesis Node
    Block* genesis = create_block(0, "Genesis Data Payload", "0000000000000000000000000000000000000000000000000000000000000000");
    printf("📦 Block [0] Deployed | Hash: %s\n", genesis->current_hash);
    
    // 2. Appending Block 1
    genesis->next = create_block(1, "Payload: IoT Gateway Node verified.", genesis->current_hash);
    printf("📦 Block [1] Deployed | Hash: %s\n", genesis->next->current_hash);
    
    // 3. Appending Block 2
    genesis->next->next = create_block(2, "Payload: Cloud sync checklist state: OK.", genesis->next->current_hash);
    printf("📦 Block [2] Deployed | Hash: %s\n", genesis->next->next->current_hash);
    
    // 4. Verifying Security Integrity Matrix
    printf("\n🔍 Running security auditing algorithms across nodes...");
    if (is_chain_valid(genesis)) {
        printf("\n✅ Cryptographic Integrity Verified: Ledger is secure and unaltered.\n");
    } else {
        printf("\n❌ Security Alert: Local chain validation failed!\n");
    }
    
    // 5. Cleanup memory allocations
    free_blockchain(genesis);
    printf("\n🧹 Cleaned up allocated memory components. Process finished successfully.\n");
    
    return 0;
}
