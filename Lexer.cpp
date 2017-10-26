#include "Cpu.h"
#include "Lexer.h"

SyntaxToken SyntaxToken::AsInstruction(CpuInstruction instruction) { 
  return SyntaxToken { 
    SyntaxTokenType::Instruction, 
    0, 
    instruction, 
    0
  };
} 
SyntaxToken SyntaxToken::AsMemoryAddress(uint16_t address) { 
  return SyntaxToken { 
    SyntaxTokenType::Address, 
    address, 
    CpuInstruction::NOOP, 
    0
  };
} 
SyntaxToken SyntaxToken::AsValue(uint16_t value) { 
  return SyntaxToken { 
    SyntaxTokenType::Value, 
    0, 
    CpuInstruction::NOOP, 
    value
  };
} 

std::vector<SyntaxToken> Lexer::Lex(const std::string &sourceText) { 
  return std::vector<SyntaxToken>();
}

// SyntaxToken Lex(Text &text) { 
//   if(text.CurrentIsFormatting()) { 
//     text.AdvanceToNextNonFormatting();
//   }
//   auto character = text.Current();
//   switch(character) {
//     case ';': 
//       break; /* this is a comment */
//     case '$': 
//       return ReadValue(text);
//     case '#': 
//       return ReadMemoryAddress(text);
//     case 'a': 
//     case 'b': 
//     case 'c': 
//     case 'd': 
//     case 'e': 
//     case 'f': 
//     case 'g': 
//     case 'h': 
//     case 'i': 
//     case 'j':
//     case 'k':
//     case 'l':
//     case 'm':
//     case 'n':
//     case 'o':
//     case 'p':
//     case 'q':
//     case 'r':
//     case 's':
//     case 't':
//     case 'u':
//     case 'v':
//     case 'w':
//     case 'x':
//     case 'y':
//     case 'z':
//     case 'A': 
//     case 'B': 
//     case 'C': 
//     case 'D': 
//     case 'E': 
//     case 'F': 
//     case 'G': 
//     case 'H': 
//     case 'I': 
//     case 'J':
//     case 'K':
//     case 'L':
//     case 'M':
//     case 'N':
//     case 'O':
//     case 'P':
//     case 'Q':
//     case 'R':
//     case 'S':
//     case 'T':
//     case 'U':
//     case 'V':
//     case 'W':
//     case 'X':
//     case 'Y':
//     case 'Z':
//       return ReadInstructionOrLabel(text);
//     default: 
//       break;
//   }
//   return SyntaxToken::AsValue(1);
// }

