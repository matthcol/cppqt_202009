#include "movielistmodel.h"

MovieListModel::MovieListModel(QObject *parent)
    :QAbstractListModel(parent)
{

}

int MovieListModel::rowCount(const QModelIndex &parent) const
{
    return movieList.count();
}

QVariant MovieListModel::data(const QModelIndex &index, int role) const
{
    if (role==Qt::DisplayRole) {
        const Movie &movie = movieList[index.row()];
        return QVariant(movie.toString());
    }
    return QVariant();
}

QList<Movie> MovieListModel::getMovieList() const
{
    return movieList;
}

void MovieListModel::setMovieList(const QList<Movie> &value)
{
    movieList = value;
    // TODO : notify view
}
