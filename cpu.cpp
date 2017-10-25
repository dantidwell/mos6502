#include <stdio.h>
#include <memory>
#include <vector>

enum class SyntaxTokenType { 
  Address,
  Comment,
  Instruction, 
  Label,
  Value
};

enum class CpuInstruction { 
  NOOP, 
  LDA, /* load a value into the accumulator */
  STA /* store from the accumulator */
};

class Text { 
public:
  static std::unique_ptr<Text> FromStandardInput() { 
    return Text::FromStream(stdin);
  }
  static std::unique_ptr<Text> FromStream(FILE *stream) { 
    return std::make_unique<Text>(Text(stream));
  }

  bool End() const { 
    return _current == EOF;
  }
  char Current() const { 
    return _current; 
  }
  bool CurrentIsFormatting() { 
    return _current == '\0' || _current == ' ' || _current == '\n';
  }
  void AdvanceToNext() {
    if(End()) { 
      return;
    }
    _current = getc(_stream);
  }   
  void AdvanceToNextNonFormatting() { 
    if(End()) { 
      return;
    }
    do {  
      _current = getc(_stream);
    } while(_current == '\0' || _current == ' ' || _current == '\n'); 
  }
private: 
  Text(FILE *stream) : _current('\0'), _stream(stream) { }
  char _current; 
  FILE *_stream;
};

struct SyntaxToken {
  static SyntaxToken AsInstruction(CpuInstruction instruction) { 
    return SyntaxToken { 
      SyntaxTokenType::Instruction, 
      0, 
      instruction, 
      0
    };
  } 
  static SyntaxToken AsMemoryAddress(uint16_t address) { 
    return SyntaxToken { 
      SyntaxTokenType::Address, 
      address, 
      CpuInstruction::NOOP, 
      0
    };
  } 
  static SyntaxToken AsValue(uint16_t value) { 
    return SyntaxToken { 
      SyntaxTokenType::Value, 
      0, 
      CpuInstruction::NOOP, 
      value
    };
  } 

  const SyntaxTokenType Type; 
  
  /* If Type == Address */
  const uint16_t Address;

  /* If Type == Instruction  */
  const CpuInstruction Instruction;

  /* if Type == Value */
  const uint16_t Value;          
};

SyntaxToken ReadInstructionOrLabel(Text &text) {
  auto bufferIndex = 0;
  const auto bufferSize = 16;
  
  char buffer[bufferSize];
  while(!text.CurrentIsFormatting() && bufferIndex <= bufferSize-1) { 
    buffer[bufferIndex++] = text.Current();
    text.AdvanceToNext();
  }
  buffer[bufferIndex] = '\0';

  if(strcmp(buffer, "LDA") == 0) { 
    return SyntaxToken::AsInstruction(CpuInstruction::LDA);
  } else if(strcmp(buffer, "STA") == 0) { 
    return SyntaxToken::AsInstruction(CpuInstruction::STA);
  } else { 
    return SyntaxToken::AsInstruction(CpuInstruction::NOOP);
  }
}

SyntaxToken ReadMemoryAddress(Text &text) {
  auto bufferIndex = 0;
  const auto bufferSize = 16;
  
  char buffer[bufferSize];
  while(!text.CurrentIsFormatting() && bufferIndex <= bufferSize-1) { 
    buffer[bufferIndex++] = text.Current();
    text.AdvanceToNext();
  }
  buffer[bufferIndex] = '\0';
  return SyntaxToken::AsMemoryAddress(0xBEEF);  
}
  
SyntaxToken ReadValue(Text &text) {
  auto bufferIndex = 0;
  const auto bufferSize = 16;
  
  char buffer[bufferSize];
  while(!text.CurrentIsFormatting() && bufferIndex <= bufferSize-1) { 
    buffer[bufferIndex++] = text.Current();
    text.AdvanceToNext(); 
  }
  buffer[bufferIndex] = '\0'; 
  return SyntaxToken::AsMemoryAddress(0xDEAD);
}

SyntaxToken Lex(Text &text) { 
  if(text.CurrentIsFormatting()) { 
    text.AdvanceToNextNonFormatting();
  }
  auto character = text.Current();
  switch(character) {
    case ';': 
      break; /* this is a comment */
    case '$': 
      return ReadValue(text);
    case '#': 
      return ReadMemoryAddress(text);
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
      return ReadInstructionOrLabel(text);
    default: 
      break;
  }
  return SyntaxToken::AsValue(1);
}

int main() {
  FILE *textStream = []() { 
    return fopen("./test/file.asm", "r");
  }();

  if(textStream == nullptr) { 
    printf("Error: Unable to open file for reading.");
    return 1;
  }

  std::vector<SyntaxToken> lexedTokens; 
  auto sourceText = Text::FromStream(textStream);
  while(!sourceText->End()) { 
er
    lexedTokens.push_back(Lex(*sourceText));
  }
  return 0;
}