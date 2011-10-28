#ifndef MASKEDITEM_H
#define MASKEDITEM_H

#include <QDeclarativeItem>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>

#include <QGraphicsScene>
#include <QGraphicsObject>

#include <QPixmap>
#include <QPainter>

#include "maskedeffect.h"

#include <QDebug>

class MaskedItem : public QDeclarativeItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl maskSource READ maskSource WRITE setMaskSource NOTIFY maskSourceChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QDeclarativeComponent* sourceComponent READ sourceComponent WRITE setSourceComponent NOTIFY sourceComponentChanged)

//    Q_PROPERTY(QGraphicsObject* item READ item NOTIFY itemChanged)

public:
    MaskedItem(QDeclarativeItem *parent = 0);

    QUrl maskSource() const;
    void setMaskSource(const QUrl &value);

    QUrl source() const;
    void setSource(const QUrl &value);

    QDeclarativeComponent *sourceComponent() const;
    void setSourceComponent (QDeclarativeComponent *sourceComponent);

//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

//    QGraphicsObject *item();


signals:
    void maskSourceChanged();
    void sourceChanged();
    void sourceComponentChanged();
    void itemChanged();

public slots:

private:
    QUrl m_maskSource;
    QUrl m_source;
    QDeclarativeComponent *m_sourceComponent;

    QDeclarativeItem *m_sourceItem;
    QDeclarativeItem *m_item;
    QPixmap m_image;
    QPixmap m_mask;

//    void composeItem();
};

#endif // MASKEDITEM_H
