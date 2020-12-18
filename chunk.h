#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_NEGATE,
  OP_RETURN, // return from the current function.
} OpCode;

typedef struct {
  int count; // # of elements
  int capacity; // # of available
  uint8_t* code;
  int *lines;
  ValueArray constants;
} Chunk;


void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
int addConstant(Chunk *chunk, Value value);
void writeChunk(Chunk* chunk, uint8_t byte, int line);

#endif
