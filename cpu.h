#include <stdint.h>

enum class CpuInstruction { 
  NOOP, 
  LDA, /* load a value into the accumulator */
  STA /* store from the accumulator */
};

static uint8_t *Memory; 

struct Cpu { 
  uint8_t A; // A (Accumulator) register 
  uint8_t B; // B (General purpose) register
  uint8_t X; // X (General purpose) register
  uint8_t S; // Stack pointer 
  uint8_t P; // Processor status flags 
};





