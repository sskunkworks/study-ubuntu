#include "shape.h"
#include <iostream>
#include <thread>
namespace shape{

  Rectangle::Rectangle(int width, int height) : width_(width), height_(height) {}

  int Rectangle::GetSize() const{
    std::thread t([this](){std::cout<<"Calculte..."<<std::endl;});
    t.join();
    return width_ * height_;
  }



} // namespace shape
