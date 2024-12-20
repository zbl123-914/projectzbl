#include "zhujiemian.h"

zhujiemian::zhujiemian(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant zhujiemian::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex zhujiemian::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex zhujiemian::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int zhujiemian::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int zhujiemian::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant zhujiemian::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
