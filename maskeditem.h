#ifndef MASKEDITEM_H
#define MASKEDITEM_H

#include "maskedeffect.h"
#include <QDeclarativeItem>

class QPixmap;

class MaskedItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl maskSource READ maskSource WRITE setMaskSource NOTIFY maskSourceChanged)

public:
    MaskedItem(QDeclarativeItem *parent = 0);
    ~MaskedItem();

    QUrl maskSource() const;
    void setMaskSource(const QUrl &value);

    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
    QRectF boundingRect() const;

signals:
    void maskSourceChanged();

private:
    QUrl m_maskSource;
    QPixmap m_mask;
    MaskedEffect *m_maskedEffect;
    QRectF m_geometry;

    QString urlToLocalFileOrQrc(const QUrl &url);
};

#endif // MASKEDITEM_H
