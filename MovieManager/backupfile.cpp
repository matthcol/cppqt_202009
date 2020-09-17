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

QStringList loadListMovieTextFile(QString filename)
{
   QFile file(filename);
   if (!file.exists()) {
       throw std::runtime_error("file not found");
   }
   QStringList res;
   // lire la liste
   if (file.open(QFile::ReadOnly)) {
       QTextStream in(&file);
       QString title;
       while (in.readLineInto(&title)) {
           res << title;
       }
       // retour de la liste
       return res;
   } else {
       throw std::runtime_error("error while reading content file");
   }
}
