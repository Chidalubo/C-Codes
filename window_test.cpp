
#include <iostream>
#include <fstream>
#include "AsciiWindow.h"
#include "Textbox.h"
#include "Image.h"
#include "BaseWindow.h"
#include "Coordinate.h"
#include "Widget.h"
#include "gtest/gtest.h"

TEST(TestWindow, Window){
  {
    EXPECT_EQ(100, getWidth());
    EXPECT_EQ(100, getHeigth());


  }
}
