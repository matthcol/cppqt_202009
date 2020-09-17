#ifndef MOVIELISTMODEL_H
#define MOVIELISTMODEL_H

#include <QAbstractListModel>
#include "movie.h"

class MovieListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    MovieListModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QList<Movie> getMovieList() const;
    void setMovieList(const QList<Movie> &value);

private:
    QList<Movie> movieList;

};

#endif // MOVIELISTMODEL_H
