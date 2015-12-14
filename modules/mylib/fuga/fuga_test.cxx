#include <iostream>
#include "fuga_test.hxx"
#include "../hoge/hoge_test.hxx"

void fuga_test(void)
{
  std::cout << "Hello FUGA" << std::endl;
  hoge_test();
}