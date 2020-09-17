#include "backupfile.h"

#include <QFile>
#include <QTextStream>

void saveListMovieTextFile(const QStringList &listMovie, QString filename)
{
    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&file);
        for (const QString &title: listMovie) {
            out << title << '\n';
        }
        // TODO: handle exceptions
        file.close();
    }
}
