#include "backupfile.h"

#include <QFile>


void saveListMovieTextFile(const QList<Movie> &listMovie, QString filename, QChar sep)
{
    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&file);
        for (const Movie &movie: listMovie) {
            out << movie.getTitle() << sep
                << movie.getYear() << sep
                << movie.getDuration()
                << '\n';
        }
        // TODO: handle exceptions
        file.close();
    }
}

QList<Movie> loadListMovieTextFile(QString filename, QChar sep)
{
   QFile file(filename);
   if (!file.exists()) {
       throw std::runtime_error("file not found");
   }
   QList<Movie> res;
   // lire la liste
   if (file.open(QFile::ReadOnly)) {
       QTextStream in(&file);
       QString line;
       while (in.readLineInto(&line)) {
           QStringList values = line.split(sep);
           Movie movie(values[0], values[1].toInt(), values[2].toInt());
           res << movie;
       }
       // retour de la liste
       return res;
   } else {
       throw std::runtime_error("error while reading content file");
   }
}

// example of operator override
QTextStream &operator<<(QTextStream &out, const Movie &movie)
{
    return out << movie.getTitle() << ','
        << movie.getYear() << ','
        << movie.getDuration()
        << '\n';
}
