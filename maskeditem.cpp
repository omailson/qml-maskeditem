#include "maskeditem.h"

MaskedItem::MaskedItem(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    setFlag(QDeclarativeItem::ItemHasNoContents, false);
    setFlag(QDeclarativeItem::ItemClipsToShape, true);
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

        emit maskSourceChanged();

        MaskedEffect *meffect = new MaskedEffect();
        meffect->setMask(m_mask);
        setGraphicsEffect(meffect);
    }
}

QUrl MaskedItem::source() const
{
    return m_source;
}

void MaskedItem::setSource(const QUrl &value)
{
    if (m_source != value) {
        m_source = value;
        m_image = QPixmap(value.toLocalFile());
        update();

        emit sourceChanged();
    }
}

QDeclarativeComponent * MaskedItem::sourceComponent() const
{
    return m_sourceComponent;
}

void MaskedItem::setSourceComponent(QDeclarativeComponent *sourceComponent)
{
    m_sourceComponent = sourceComponent;

    QDeclarativeContext *ctxt = new QDeclarativeContext(qmlContext(this));
    QObject *nobj = sourceComponent->beginCreate(ctxt);
    sourceComponent->completeCreate();
    m_sourceItem = qobject_cast<QDeclarativeItem *>(nobj);
    m_sourceItem->update();

    if (!m_mask.isNull()) {
        MaskedEffect *meffect = new MaskedEffect();
        meffect->setMask(m_mask);
        m_sourceItem->setGraphicsEffect(meffect);
    }
    m_sourceItem->setParentItem(this);

    update();

    emit sourceComponentChanged();
}

/*
QGraphicsObject * MaskedItem::item()
{
    return m_item;
}
//*/

/*
void MaskedItem::composeItem()
{
    if (m_mask.isNull())
        return;

    qDebug()<<"a";
    m_item = new QDeclarativeItem(this);
//    m_item->setImplicitWidth(m_mask.width());
//    m_item->setImplicitHeight(m_mask.height());

    qDebug()<<"b";
    QPixmap pixmap(m_mask.size());
    pixmap.fill(Qt::transparent);

    QPainter itemPainter(&pixmap);
    m_sourceItem->paint(&itemPainter, 0, 0);
    itemPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    itemPainter.drawPixmap(0, 0, m_mask);
qDebug()<<"c";

qDebug()<<"d";
    m_item->setParentItem(this);


    emit itemChanged();
}
//*/

/*
void MaskedItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    Q_UNUSED(option)
//    Q_UNUSED(widget)

    if (!m_image.isNull()) {
        painter->drawPixmap(0, 0, m_image);
    } else {
        QPixmap pixmap(m_mask.size());
//        pixmap.fill(Qt::transparent);

        QPainter itemPainter(&pixmap);
        m_sourceItem->paint(painter, option, widget);
//        itemPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
//        itemPainter.drawPixmap(0, 0, m_mask);

//        painter->drawPixmap(0, 0, pixmap);
    }
}
//*/
