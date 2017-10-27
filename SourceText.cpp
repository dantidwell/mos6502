#include "SourceText.h"

std::unique_ptr<SourceText> SourceText::FromStream(std::istream &stream) { 
  return std::make_unique<SourceText>(SourceText(
    std::string(std::istreambuf_iterator<char>(stream), {})
  ));
}

std::unique_ptr<SourceText> SourceText::FromString(const std::string &text) { 
  return std::make_unique<SourceText>(text);
}

SourceText::SourceText(const std::string &text) : 
_text(text)
{
  _lexemeStart = _text.begin();
  _cursor = _text.begin(); 
  _end = _text.end();
}

