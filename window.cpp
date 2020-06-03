#include "window.h"
#include <QPainter>


Window::Window()
{
    setWindowTitle(tr("Simplest 2D Painting"));
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(16, 16, 96));
    circlePen = QPen(Qt::yellow);
    circlePen.setWidth(3);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}


void
Window::paintEvent(QPaintEvent* event) {
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), background);

    painter.translate(event->rect().width()/2, event->rect().height()/2);

    painter.setPen(circlePen);
    qreal radius = 100.0;
    painter.drawEllipse(QRectF(-radius,
                               -radius,
                               radius * 2,
                               radius * 2));
    painter.setPen(textPen);
    painter.setFont(textFont);
    painter.drawText(QRect(-100, -50, 200, 100), Qt::AlignCenter, QStringLiteral("disleyxa"));
    QWidget::update();
}
