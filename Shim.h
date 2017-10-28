#ifndef __SHIM_H__
#define __SHIM_H__

#include <memory>

namespace Mos6502 { namespace Shim {
  template<typename T, typename ...Args>
  std::unique_ptr<T> make_unique( Args&& ...args )
  {
      return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
  }
}}

#endif