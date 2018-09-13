#include "Joystick.h"

//defaults
const QColor Joystick::DEFAULT_DOT_COLOR = QColor(255, 0, 0);
const QColor Joystick::DEFAULT_CIRCLE_COLOR = QColor(109, 109, 109);
const QColor Joystick::DEFAULT_DEADBAND_COLOR = QColor(153, 12, 141);


//private functions
void Joystick::init(double xVal, double yVal, double xDeadband, double yDeadband,
                    const QColor& dotColor, const QColor& circleColor,
                    const QColor& deadbandColor)
{
  setXVal(xVal);
  setYVal(yVal);
  setXDeadband(xDeadband);
  setyDeadband(yDeadband);
  setDotColor(dotColor);
  setCircleColor(circleColor);
  setDeadbandColor(deadbandColor);
}

//event handlers
void Joystick::paintEvent(QPaintEvent* e)
{
}

//constructors
Joystick::Joystick(QWidget* parent) :
  QWidget(parent)
{
  init(0.0, 0.0, 0.0, 0.0, DEFAULT_DOT_COLOR, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, 0.0, 0.0, DEFAULT_DOT_COLOR, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(const QColor& dotColor, QWidget* parent) :
  QWidget(parent)
{
  init(0.0, 0.0, 0.0, 0.0, dotColor, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(const QColor& dotColor, const QColor& circleColor, QWidget* parent) :
  QWidget(parent)
{
  init(0.0, 0.0, 0.0, 0.0, dotColor, circleColor, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(const QColor& dotColor, const QColor& circleColor, const QColor& deadbandColor,
                   QWidget* parent) :
  QWidget(parent)
{
  init(0.0, 0.0, 0.0, 0.0, dotColor, circleColor, deadbandColor);
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, 0.0, 0.0, dotColor, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
                   QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, 0.0, 0.0, dotColor, circleColor, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
                   const QColor& deadbandColor, QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, 0.0, 0.0, dotColor, circleColor, deadbandColor);
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, xDeadband, ydeadBand, DEFAULT_DOT_COLOR, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor, QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, xDeadband, ydeadBand, dotColor, DEFAULT_CIRCLE_COLOR, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor, const QColor& circleColor, QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, xDeadband, ydeadBand, dotColor, circleColor, DEFAULT_DEADBAND_COLOR);
}
Joystick::Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
                   const QColor& dotColor, const QColor& circleColor, const QColor& deadbandColor,
                   QWidget* parent) :
  QWidget(parent)
{
  init(xVal, yVal, xDeadband, ydeadBand, dotColor, circleColor, deadbandColor);
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
  //store current x for the signal
  auto oldX = m_xVal;

  newX = (newX > 1.0) ? 1.0 : newX;
  newX = (newX < -1.0) ? -1.0 : newX;
  m_xVal = newX;

  emit xChanged(oldX, newX);
}
void Joystick::setYVal(double newY)
{
  //store current y for the signal
  auto oldY = m_yVal;

  newY = (newY > 1.0) ? 1.0 : newY;
  newY = (newY < -1.0) ? -1.0 : newY;
  m_yVal = newY;

  emit yChanged(oldY, newY);
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

//public slots
void Joystick::updateX(double newX)
{
  setXVal(newX);
}
void Joystick::updateY(double newY)
{
  setYVal(newY);
}
