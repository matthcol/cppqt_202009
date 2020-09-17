#ifndef BACKUPFILE_H
#define BACKUPFILE_H

#include <QStringList>

/**
 * @brief saveListMovie
 * @param listMovie
 */
void  saveListMovieTextFile(const QStringList &listMovie, QString filename);

QStringList loadListMovieTextFile(QString filename);

#endif // BACKUPFILE_H
