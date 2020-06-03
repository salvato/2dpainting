#ifndef WINDOW_H
#define WINDOW_H


#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPaintEvent>


class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    void paintEvent(QPaintEvent* event);

    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
};

#endif
