#include <iostream>

#include <qapplication.h>

#include "Joystick.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Joystick j(0.5, 0.0, 0.2, 0.2);
  j.show();

  return app.exec();
}