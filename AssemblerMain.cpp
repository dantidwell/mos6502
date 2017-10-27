#include <fstream>

#include "SourceText.h"

int main(int argc, char ** argv) { 
  if(argc < 2) {
    fprintf(stderr, "No input file specified."); 
    return 1;
  }

  argv++;
  std::fstream inputFileStream(argv[0], std::fstream::in);

  if(!inputFileStream.is_open()) { 
    fprintf(stderr, "Unable to open input file at location %s", argv[0]);
    return 1;
  }

  auto source = SourceText::FromString(
    R"(
    LDA #$01
    STA $0200
    LDA #$05
    STA $0201
    LDA #$08
    STA $0202
    )"
  );

  while(!source->IsAtEnd()) { 
    printf("Char: %c\n", source->Next());
  }

  return 0;
}