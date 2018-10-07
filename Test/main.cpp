#include <iostream>

#include <qapplication.h>
#include <qslider.h>
#include <qtimer.h>

#include "Joystick.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  Joystick j(0.25, 0.0, 0.4, 0.2);
  j.resize(400, 400);
  j.setScale(0.02);
  j.show();

  QSlider xSlider(Qt::Orientation::Horizontal);
  xSlider.setMinimum(-100);
  xSlider.setMaximum(100);
  qApp->connect(&xSlider, &QSlider::valueChanged, [&](int newVal)
  {
    j.setXVal(newVal / 100.0);
  });
  xSlider.show();

  QSlider ySlider(Qt::Orientation::Vertical);
  ySlider.setMinimum(-100);
  ySlider.setMaximum(100);
  qApp->connect(&ySlider, &QSlider::valueChanged, [&](int newVal)
  {
    j.setYVal(newVal / 100.0);
  });
  ySlider.show();

  QSlider deadbandXSlider(Qt::Orientation::Horizontal);
  deadbandXSlider.setMinimum(0);
  deadbandXSlider.setMaximum(100);
  qApp->connect(&deadbandXSlider, &QSlider::valueChanged, [&](int newVal)
  {
    j.setXDeadband(newVal / 100.0);
  });
  deadbandXSlider.show();

  QSlider deadbandYSlider(Qt::Orientation::Vertical);
  deadbandYSlider.setMinimum(0);
  deadbandYSlider.setMaximum(100);
  qApp->connect(&deadbandYSlider, &QSlider::valueChanged, [&](int newVal)
  {
    j.setYDeadband(newVal / 100.0);
  });
  deadbandYSlider.show();

  QTimer timer;
  timer.setInterval(500);
  qApp->connect(&timer, &QTimer::timeout, [&] ()
  {
    std::cout << "Test: timer tick, updating x and y value" << std::endl;
    j.setYVal(j.yVal());
    j.setXVal(j.xVal());
  });
  timer.start();

  return app.exec();
}