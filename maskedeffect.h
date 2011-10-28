#ifndef MASKEDEFFECT_H
#define MASKEDEFFECT_H

#include <QGraphicsEffect>
#include <QGraphicsItem>
#include <QPainter>

class MaskedEffect : public QGraphicsEffect
{
public:
    explicit MaskedEffect(QObject *parent = 0);

    void draw(QPainter *painter);

    void setMask(const QPixmap &mask);
    QPixmap mask() const;

signals:

public slots:

private:
    QPixmap m_mask;

};

#endif // MASKEDEFFECT_H
