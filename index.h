#ifndef INDEX_H
#define INDEX_H

#include "pes.h"

#define MAX_INDEX_ENTRIES 10000

typedef struct {
    uint32_t mode;          // File mode (100644, etc.)
    ObjectID hash;          // SHA-256 hash of blob
    uint64_t mtime_sec;     // Last modified time
    uint32_t size;          // File size
    char path[512];         // File path
} IndexEntry;

typedef struct {
    IndexEntry entries[MAX_INDEX_ENTRIES];
    int count;
} Index;

// Load index from .pes/index
int index_load(Index *index);

// Save index to .pes/index
int index_save(const Index *index);

// Add file to index
int index_add(Index *index, const char *path);

// Remove file from index
int index_remove(Index *index, const char *path);

// Find entry
IndexEntry* index_find(Index *index, const char *path);

// Status display
int index_status(const Index *index);

#endif
