#include <mylib/hoge/hoge_test.hxx>
#include <mylib/hoge/TestDir/hoge_test2.hxx>
#include <mylib/fuga/fuga_test.hxx>
#include <mylib/config.h>
#include <iostream>

int main(void)
{
#ifdef USE_TEST
  std::cout << "used" << std::endl;
#elif
  std::cout << "not used" << std::endl;
#endif
  std::cout << "progmra 2" << std::endl;
  hoge_test();
  hoge_test2();
  fuga_test();
  return 0;
}