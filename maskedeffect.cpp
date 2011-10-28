#include "maskedeffect.h"

MaskedEffect::MaskedEffect(QObject *parent) :
    QGraphicsEffect(parent)
{
}

void MaskedEffect::setMask(const QPixmap &mask)
{
    m_mask = mask;
}

QPixmap MaskedEffect::mask() const
{
    return m_mask;
}

void MaskedEffect::draw(QPainter *painter)
{
    QPoint offset;
    const QPixmap pixmapp = sourcePixmap(Qt::LogicalCoordinates, &offset);

    QPixmap pixmap(m_mask.size());
    pixmap.fill(Qt::transparent);
    QPainter itemPainter(&pixmap);
    itemPainter.drawPixmap(0,0, pixmapp);

    itemPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    itemPainter.drawPixmap(0,0, m_mask);
    painter->drawPixmap(0,0, pixmap);
}
