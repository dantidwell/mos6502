#include <iostream>
#include <memory>
#include <string_view>

class SourceText {
public:
  static std::unique_ptr<SourceText> FromString(const std::string &text);
  static std::unique_ptr<SourceText> FromStream(std::istream &stream);

  SourceText(const std::string &text);
  
  inline void Advance() { 
    _cursor++; 
  };

  inline const std::string GrabLexeme() { 
    return std::string(_lexemeStart, _cursor); 
  };
  
  inline bool IsAtEnd() {
    return _cursor == _end;
  };
  
  inline char Peek() { 
    return *_cursor; 
  };

  inline char Next() { 
    auto c = *_cursor;
    _cursor++;
    return c;
  }
  
  inline void Start() { 
    _lexemeStart = _cursor;
  };
private: 
  const std::string _text;
  std::string::const_iterator _lexemeStart;
  std::string::const_iterator _cursor;
  std::string::const_iterator _end;
};