#ifndef BACKUPFILE_H
#define BACKUPFILE_H

#include <QList>
#include <QTextStream>
#include "movie.h"
/**
 * @brief saveListMovie
 * @param listMovie
 */
void  saveListMovieTextFile(const QList<Movie> &listMovie, QString filename, QChar sep=',');

QList<Movie> loadListMovieTextFile(QString filename, QChar sep=',');

QTextStream& operator<<(QTextStream& out, const Movie &movie);

#endif // BACKUPFILE_H
