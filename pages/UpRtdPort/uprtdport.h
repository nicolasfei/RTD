#ifndef UPRTDPORT_H
#define UPRTDPORT_H

#include <QWidget>

namespace Ui {
class uprtdport;
}

class uprtdport : public QWidget
{
    Q_OBJECT

public:
    explicit uprtdport(QWidget *parent = nullptr);
    ~uprtdport();

private:
    Ui::uprtdport *ui;
};

#endif // UPRTDPORT_H
