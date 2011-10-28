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

void MaskedEffect::setSize(const QSize &newSize)
{
    if (m_size != newSize) {
        m_size = newSize;

        sourceChanged(QGraphicsEffect::SourceInvalidated);
    }
}

QSize MaskedEffect::size() const
{
    return m_size;
}

void MaskedEffect::draw(QPainter *painter)
{
    QPoint offset;

    QPixmap sourceItem = sourcePixmap(Qt::LogicalCoordinates, &offset);
    QPixmap mask = (m_mask.size() == size()) ? m_mask : m_mask.scaled(size());

    QPixmap pixmap(size());
    pixmap.fill(Qt::transparent);

    QPainter itemPainter(&pixmap);
    itemPainter.drawPixmap(offset, sourceItem);
    itemPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    itemPainter.drawPixmap(0,0, mask);
    painter->drawPixmap(0,0, pixmap);
}
