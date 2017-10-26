#include <string>
#include <vector>

enum class CpuInstruction;

enum class SyntaxTokenType { 
  Address,
  Comment,
  Instruction, 
  Label,
  Value
};

struct SyntaxToken {
  static SyntaxToken AsInstruction(CpuInstruction instruction);
  static SyntaxToken AsMemoryAddress(uint16_t address);
  static SyntaxToken AsValue(uint16_t value);
  
  const SyntaxTokenType Type; 
  /* If Type == Address */
  const uint16_t Address;
  /* If Type == Instruction  */
  const CpuInstruction Instruction;
  /* if Type == Value */
  const uint16_t Value;
};

class Lexer {
public:  
  static std::vector<SyntaxToken> Lex(const std::string &sourceText);
};