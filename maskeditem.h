#ifndef MASKEDITEM_H
#define MASKEDITEM_H

#include <QDeclarativeItem>
#include <QPixmap>

#include "maskedeffect.h"

class MaskedItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl maskSource READ maskSource WRITE setMaskSource NOTIFY maskSourceChanged)

public:
    MaskedItem(QDeclarativeItem *parent = 0);

    QUrl maskSource() const;
    void setMaskSource(const QUrl &value);

    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
    QRectF boundingRect() const;

signals:
    void maskSourceChanged();

public slots:

private:
    QUrl m_maskSource;

    QPixmap m_mask;
    MaskedEffect *m_maskedEffect;

    QRectF m_geometry;
};

#endif // MASKEDITEM_H
