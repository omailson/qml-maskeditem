#include "maskeditem.h"

MaskedItem::MaskedItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
  , m_maskedEffect(new MaskedEffect)
{
    setFlag(QDeclarativeItem::ItemHasNoContents, false);
    setFlag(QDeclarativeItem::ItemClipsToShape, true);

    setGraphicsEffect(m_maskedEffect);
}

QUrl MaskedItem::maskSource() const
{
    return m_maskSource;
}

void MaskedItem::setMaskSource(const QUrl &value)
{
    if (m_maskSource != value) {
        m_maskSource = value;
        m_mask = QPixmap(value.toLocalFile());
        update();

        setImplicitWidth(m_mask.width());
        setImplicitHeight(m_mask.height());

        m_maskedEffect->setMask(m_mask);

        emit maskSourceChanged();
    }
}

void MaskedItem::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QDeclarativeItem::geometryChanged(newGeometry, oldGeometry);

    m_geometry = newGeometry;
    m_maskedEffect->setSize(newGeometry.size().toSize());
}

QRectF MaskedItem::boundingRect() const
{
    return m_geometry;
}

