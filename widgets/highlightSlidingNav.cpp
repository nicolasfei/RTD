#include "highlightSlidingNav.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPropertyAnimation>
 
HighlightSlidingNavigationMenuWidget::HighlightSlidingNavigationMenuWidget(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
 
    auto font = this->font();
    font.setPixelSize(22);
    font.setBold(true);
    setFont(font);
 
    setTitle(QStringList() << "Home" << "Blog" << "More About My Portfolio" << "Contact");
}
 
HighlightSlidingNavigationMenuWidget::~HighlightSlidingNavigationMenuWidget()
{
}
 
void HighlightSlidingNavigationMenuWidget::setTitle(const QStringList &list)
{
    if(list.isEmpty())
        return;
 
    titleList = list;
    widthOfEachAreaList.clear();
    auto fontMetics = this->fontMetrics();
    int width{0};
    for(const auto & title : titleList)
    {
        width += (fontMetics.size(Qt::AlignCenter,title).width() + 60);
        widthOfEachAreaList << width;
    }
    updateEachArea();
    update();
}
 
void HighlightSlidingNavigationMenuWidget::paintEvent(QPaintEvent *event)
{
    const auto drawRect = event->rect();
    const auto drawHeight = drawRect.height();
    QPainter painter(this);
    painter.fillRect(drawRect.adjusted(0,10,0,-10),QColor(0x292929));
    painter.setRenderHint(QPainter::Antialiasing,true);
 
    painter.setPen(QPen(QColor(0x444444),2));
    for(int i = 0;i < widthOfEachAreaList.size();++i)
    {
        painter.drawLine(QPoint(widthOfEachAreaList.at(i),12),QPoint(widthOfEachAreaList.at(i),drawHeight - 12));
    }
 
    QLinearGradient linearGradient(sliderRect.topLeft(),sliderRect.bottomLeft());
    linearGradient.setColorAt(0.0,QColor(0x0b2b62));
    linearGradient.setColorAt(1.0,QColor(0x1153bf));
    painter.setBrush(linearGradient);
    painter.drawRoundedRect(sliderRect,6,6);
 
    painter.setFont(this->font());
    painter.setPen(Qt::white);
    for(int i = 0;i < eachAreaList.size();++i)
    {
        painter.drawText(eachAreaList.at(i),Qt::AlignCenter,titleList.at(i));
    }
}
 
QSize HighlightSlidingNavigationMenuWidget::sizeHint() const
{
    auto fontMetics = this->fontMetrics();
    int width{0};
    for(const auto & title : titleList)
    {
        width += (fontMetics.size(Qt::AlignCenter,title).width() + 60);
    }
    return QSize(width,100);
}
 
void HighlightSlidingNavigationMenuWidget::resizeEvent(QResizeEvent *event)
{
    updateEachArea();
    QWidget::resizeEvent(event);
}
 
void HighlightSlidingNavigationMenuWidget::mouseMoveEvent(QMouseEvent *event)
{
    auto nowPos = event->pos();
    int lastIndex = currIndex;
    for(int i = 0;i < widthOfEachAreaList.size();++i)
    {
        if(eachAreaList.at(i).contains(nowPos))
        {
            currIndex = i;
            break;
        }
    }
    if(lastIndex != currIndex)
    {
        auto animationSliderRect = new QPropertyAnimation(this, "sliderRect");
        animationSliderRect->setStartValue(sliderRect);
        animationSliderRect->setEndValue(eachAreaList.at(currIndex));
        animationSliderRect->setDuration(200);
        emit currIndexChange(currIndex);
        connect(animationSliderRect,&QPropertyAnimation::valueChanged,this,QOverload<>::of(&QWidget::update));
        animationSliderRect->start(QAbstractAnimation::DeleteWhenStopped);
    }
    QWidget::mouseMoveEvent(event);
}
 
void HighlightSlidingNavigationMenuWidget::updateEachArea()
{
    eachAreaList.clear();
    auto height = this->height();
    for(int i = 0;i < widthOfEachAreaList.size();++i)
    {
        QRect rect{i == 0 ? 0 : widthOfEachAreaList.at(i - 1),
                   0,
                   i == 0 ? widthOfEachAreaList.at(i) : widthOfEachAreaList.at(i) - widthOfEachAreaList.at(i - 1),
                   height};
        eachAreaList << rect;
    }
    sliderRect = eachAreaList.first();
    currIndex = 0;
    emit currIndexChange(currIndex);
}
 
const QRect &HighlightSlidingNavigationMenuWidget::getSliderRect() const
{
    return sliderRect;
}
 
void HighlightSlidingNavigationMenuWidget::setSliderRect(const QRect &newSliderRect)
{
    sliderRect = newSliderRect;
}

