#ifndef MASKEDEFFECT_H
#define MASKEDEFFECT_H

#include <QGraphicsEffect>

class QPainter;

class MaskedEffect : public QGraphicsEffect
{
    Q_OBJECT

    Q_PROPERTY(QPixmap mask READ mask WRITE setMask)
    Q_PROPERTY(QSize size READ size WRITE setSize)

public:
    MaskedEffect(QObject *parent = 0);

    void draw(QPainter *painter);

    void setMask(const QPixmap &mask);
    QPixmap mask() const;

    void setSize(const QSize &);
    QSize size() const;

private:
    QPixmap m_mask;
    QSize m_size;

};

#endif // MASKEDEFFECT_H
