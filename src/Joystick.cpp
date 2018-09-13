#include "Joystick.h"

//private functions
void Joystick::init(double xVal, double yVal, double xDeadband, double yDeadband,
                    const QColor& dotColor, const QColor& circleColor,
                    const QColor& deadbandColor)
{
}

//event handlers
void Joystick::paintEvent(QPaintEvent* e)
{
}

//constructors
Joystick::Joystick(QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, QWidget* parent)
{
}
Joystick::Joystick(const QColor& dotColor, QWidget* parent)
{
}
Joystick::Joystick(const QColor& dotColor, const QColor& circleColor, QWidget* parent)
{
}
Joystick::Joystick(const QColor& dotColor, const QColor& circleColor, const QColor& deadbandColor,
                   QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
                   QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
                   const QColor& deadbandColor, QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor,
                   QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor,
                   const QColor& circleColor,
                   QWidget* parent)
{
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor,
                   const QColor& circleColor,
                   const QColor& deadbandColor,
                   QWidget* parent)
{
}
Joystick::~Joystick()
{
}

//public functions

//getters
double Joystick::xVal() const
{
  return m_xVal;
}
double Joystick::yVal() const
{
  return m_yVal;
}
double Joystick::xDeadband() const
{
  return m_xDeadband;
}
double Joystick::yDeadband() const
{
  return m_yDeadband;
}
QColor Joystick::dotColor() const
{
  return m_dotColor;
}
QColor Joystick::circleColor() const
{
  return m_circleColor;
}
QColor Joystick::deadbandColor() const
{
  return m_deadbandColor;
}

//setters
void Joystick::setXVal(double newX)
{
  newX = (newX > 1.0) ? 1.0 : newX;
  newX = (newX < -1.0) ? -1.0 : newX;
  m_xVal = newX;
}
void Joystick::setYVal(double newY)
{
  newY = (newY > 1.0) ? 1.0 : newY;
  newY = (newY < -1.0) ? -1.0 : newY;
  m_yVal = newY;
}
void Joystick::setXDeadband(double newXDeadband)
{
  newXDeadband = (newXDeadband < -1.0) ? -1.0 : newXDeadband;
  newXDeadband = (newXDeadband > 1.0) ? 1.0 : newXDeadband;
  m_xDeadband = newXDeadband;
}
void Joystick::setyDeadband(double newYDeadband)
{
  newYDeadband = (newYDeadband < -1.0) ? -1.0 : newYDeadband;
  newYDeadband = (newYDeadband > 1.0) ? 1.0 : newYDeadband;
  m_yDeadband = newYDeadband;
}
void Joystick::setDotColor(const QColor& newColor)
{
  m_dotColor = newColor;
}
void Joystick::setDotColor(int r, int g, int b)
{
  setDotColor(QColor(r, g, b));
}
void Joystick::setCircleColor(const QColor& newColor)
{
  m_circleColor = newColor;
}
void Joystick::setCircleColor(int r, int g, int b)
{
  setCircleColor(QColor(r, g, b));
}
void Joystick::setDeadbandColor(const QColor& newColor)
{
  m_deadbandColor = newColor;
}
void Joystick::setDeadbandColor(int r, int g, int b)
{
  setCircleColor(QColor(r, g, b));
}

//signals
void Joystick::xChanged(double oldX, double newX)
{
}
void Joystick::yChanged(double oldY, double newY)
{
}

//public slots
void Joystick::updateX(double newX)
{
}
void Joystick::updateY(double newY)
{
}
