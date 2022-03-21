#include <iostream>
#include "foo.h"
#include "shape.h"
int main()
{
  std::cout<<"HELLO CMAKE"<<std::endl;
  foo();
  std::cout<<"Rec"<<std::endl;

  shape::Rectangle r(3,3);

  std::cout<<r.GetSize()<<std::endl;
  std::cout<<"END"<<std::endl;
  return 0;
}
