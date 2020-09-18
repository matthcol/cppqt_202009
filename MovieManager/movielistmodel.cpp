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
        QString display = QString("%1, %2, %3 mn")
                .arg(movie.getTitle())
                .arg(movie.getYear())
                .arg(movie.getDuration());
        //return QVariant(movie.toString());
        return QVariant(display);
    }
    return QVariant();
}

QList<Movie> MovieListModel::getMovieList() const
{
    return movieList;
}

void MovieListModel::setMovieList(const QList<Movie> &value)
{
    // clean data and notify view
    int size = movieList.size();
    if (size > 0) {
        beginRemoveRows(QModelIndex(),0,size-1);
        movieList.clear();
        endRemoveRows();
    }
    // add new data and notify view
    size = value.size();
    beginInsertRows(QModelIndex(),0,size-1);
    movieList = value;
    endInsertRows();
}

void MovieListModel::add(const Movie &movie)
{
    int index = movieList.size();
    beginInsertRows(QModelIndex(), index, index);
    movieList << movie;
    endInsertRows();
}

void MovieListModel::update(int index, const Movie &movie)
{

}

void MovieListModel::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    movieList.removeAt(index);
    endRemoveRows();
}
