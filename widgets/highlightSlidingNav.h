#ifndef HIGHLIGHTSLIDINGNAVIGATIONMENUWIDGET_H
#define HIGHLIGHTSLIDINGNAVIGATIONMENUWIDGET_H
 
#include <QWidget>
 
class HighlightSlidingNavigationMenuWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QRect sliderRect READ getSliderRect WRITE setSliderRect MEMBER sliderRect)
public:
    HighlightSlidingNavigationMenuWidget(QWidget *parent = nullptr);
    ~HighlightSlidingNavigationMenuWidget();
    void setTitle(const QStringList & list);
 
    const QRect &getSliderRect() const;
    void setSliderRect(const QRect &newSliderRect);
 
signals:
    void currIndexChange(int index);
 
protected:
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
 
private:
    void updateEachArea();
 
    QStringList titleList;
    QList<int> widthOfEachAreaList;
    int currIndex{0};
    QList<QRect> eachAreaList;
    QRect sliderRect;//»¬¿éµÄÎ»ÖÃ
};
#endif // HIGHLIGHTSLIDINGNAVIGATIONMENUWIDGET_H
