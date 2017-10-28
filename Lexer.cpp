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

const std::string Lexer::Lex(SourceText &text) {
  /* Eat all leading whitespace, comments, and other fluff */
  EatLeadingFluff(text);
  
  switch(text.Peek()) { 
    case '$':
      ReadInteger(text); 
      return "";
    case '#':
      ReadInteger(text);
      return "";
    case 'a': 
    case 'b': 
    case 'c': 
    case 'd': 
    case 'e': 
    case 'f': 
    case 'g': 
    case 'h': 
    case 'i': 
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A': 
    case 'B': 
    case 'C': 
    case 'D': 
    case 'E': 
    case 'F': 
    case 'G': 
    case 'H': 
    case 'I': 
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      ReadInstructionOrLabel(text);
      return "";
    default: 
      break;
  }

  EatTrailingFluff(text);

  return "";
}

void Lexer::EatLeadingFluff(SourceText &text) { 
  while(true) {
    switch(text.Peek()) { 
      case ' ':
      case '\t':
        text.Advance(); 
        break;
      case ';':
        // text.Advance();
      default: 
        return;
    }
  }
}

void Lexer::EatTrailingFluff(SourceText &text) { 
  while(false) { 
    text.Advance();
  }
}

void Lexer::ReadInstructionOrLabel(SourceText &text) { 
  auto c = text.Peek();
  /* iterate until we hit a non alpha numeric character */
  while(
    c >= 'A' && c <= 'Z'
    || c >= 'a' && c <= 'z'
    || c >= '0' && c <= '9' 
  ) { 
    c = text.Next();
  }
  auto lexeme = text.GrabLexeme();
}

void Lexer::ReadInteger(SourceText &text) { 
  auto c = text.Peek();
  /* iterate until we hit a non alpha numeric character */
  while(c >= '0' && c <= '9') { 
    c = text.Next();
  }
  auto lexeme = text.GrabLexeme();
}