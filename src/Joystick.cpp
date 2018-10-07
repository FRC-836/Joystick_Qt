#include "Joystick.h"

//defaults
const QColor Joystick::DEFAULT_DOT_COLOR = QColor(0, 0, 255);
const QColor Joystick::DEFAULT_CIRCLE_COLOR = QColor(109, 109, 109);
const QColor Joystick::DEFAULT_DEADBAND_COLOR = QColor(153, 12, 141);

//constants
const double Joystick::DIFF_TO_FORCE_REDRAW = 0.0000000001;

//private functions
void Joystick::init(double xVal, double yVal, double xDeadband, double yDeadband,
                    const QColor& dotColor, const QColor& circleColor,
                    const QColor& deadbandColor)
{
  setXVal(xVal);
  setYVal(yVal);
  setXDeadband(xDeadband);
  setYDeadband(yDeadband);
  setDotColor(dotColor);
  setCircleColor(circleColor);
  setDeadbandColor(deadbandColor);

  m_dotScale = 0.05;
}

//event handlers
void Joystick::paintEvent(QPaintEvent* e)
{
  //generate the circle representing total range of motion of the joystick
  QPainterPath circlePath;
  circlePath.addEllipse(rect());

  auto widgetCenterX = width() / 2;
  auto widgetCenterY = height() / 2;

  //generate circle representing deadband
  QPainterPath deadbandPath;
  auto deadbandWidth = width() * m_xDeadband;
  auto deadbandHeight = height() * m_yDeadband;
  auto deadbandX = widgetCenterX - (deadbandWidth / 2);
  auto deadbandY = widgetCenterY - (deadbandHeight / 2);
  deadbandPath.addEllipse(deadbandX, deadbandY, deadbandWidth, deadbandHeight);

  //generate circle representing the joystick position
  QPainterPath dotPath;
  auto dotWidth = width() * m_dotScale;
  auto dotHeight = height() * m_dotScale;
  auto dotX = (widgetCenterX - (dotWidth / 2)) + (width() * (m_xVal / 2));
  auto dotY = (widgetCenterY - (dotHeight / 2)) + (height() * (m_yVal / 2));

  //check if the joystick is in the deadzone, if it is, zero the values used to paint
  if (abs(m_xVal) < m_xDeadband)
  {
    dotX = widgetCenterX;
  } //end  if (abs(dotX) < m_xDeadband || abs(dotY) < m_yDeadband))
  if (abs(m_yVal) < m_yDeadband)
  {
    dotY = widgetCenterY;
  } //end  if (abs(dotX) < m_xDeadband || abs(dotY) < m_yDeadband))

  dotPath.addEllipse(dotX, dotY, dotWidth, dotHeight);

  QPainter painter(this);

  //draw circle
  painter.setPen(QPen(m_circleColor));
  painter.setBrush(QBrush(m_circleColor));
  painter.drawPath(circlePath);

  //draw deadband
  painter.setPen(QPen(m_deadbandColor));
  painter.setBrush(QBrush(m_deadbandColor));
  painter.drawPath(deadbandPath);

  //draw dot
  painter.setPen(QPen(m_dotColor));
  painter.setBrush(QBrush(m_dotColor));
  painter.drawPath(dotPath);
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
double Joystick::scale() const
{
  return m_dotScale;
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
  if (std::abs(m_xVal - newX) >= DIFF_TO_FORCE_REDRAW)
  {
    //store current x for the signal
    auto oldX = m_xVal;

    newX = (newX > 1.0) ? 1.0 : newX;
    newX = (newX < -1.0) ? -1.0 : newX;
    m_xVal = newX;

    emit xChanged(oldX, newX);

    repaint();
  } //end  if (std::abs(m_xVal - newX) >= DIFF_TO_FORCE_REDRAW)
}
void Joystick::setYVal(double newY)
{
  if (std::abs(m_yVal - newY) >= DIFF_TO_FORCE_REDRAW)
  {
    //store current y for the signal
    auto oldY = m_yVal;

    newY = (newY > 1.0) ? 1.0 : newY;
    newY = (newY < -1.0) ? -1.0 : newY;
    m_yVal = newY;

    emit yChanged(oldY, newY);

    repaint();
  } //end  if (std::abs(m_yVal - newY) >= DIFF_TO_FORCE_REDRAW)
}
void Joystick::setScale(double newScale)
{
  newScale = (newScale < 0) ? 0 : newScale;
  newScale = (newScale > 1.0) ? 1.0 : newScale;
  m_dotScale = newScale;
}
void Joystick::setXDeadband(double newXDeadband)
{
  if (std::abs(m_xDeadband - newXDeadband) >= DIFF_TO_FORCE_REDRAW)
  {
    newXDeadband = (newXDeadband < 0) ? 0 : newXDeadband;
    newXDeadband = (newXDeadband > 1.0) ? 1.0 : newXDeadband;
    m_xDeadband = newXDeadband;

    repaint();
  } //end  if (std::abs(m_xDeadband - newXDeadband) >= DIFF_TO_FORCE_REDRAW)
}
void Joystick::setYDeadband(double newYDeadband)
{
  if (std::abs(m_yDeadband - newYDeadband) >= DIFF_TO_FORCE_REDRAW)
  {
    newYDeadband = (newYDeadband < 0) ? 0 : newYDeadband;
    newYDeadband = (newYDeadband > 1.0) ? 1.0 : newYDeadband;
    m_yDeadband = newYDeadband;

    repaint();
  } //end  if (std::abs(m_yDeadband - newYDeadband) >= DIFF_TO_FORCE_REDRAW)
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
