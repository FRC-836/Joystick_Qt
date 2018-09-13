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
bool Joystick::setXVal(double newX)
{
}
bool Joystick::setYVal(double newY)
{
}
void Joystick::setXDeadband(double newXDeadband)
{
}
void Joystick::setyDeadband(double newXDeadband)
{
}
void Joystick::setDotColor(const QColor& newColor)
{
}
void Joystick::setDotColor(int r, int g, int b)
{
}
void Joystick::setCircleColor(const QColor& newColor)
{
}
void Joystick::setCircleColor(int r, int g, int b)
{
}
void Joystick::setDeadbandColor(const QColor& newColor)
{
}
void Joystick::setDeadbandColor(int r, int g, int b)
{
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
