#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include <QDebug>

class Movie
{
public:
    Movie();
    Movie(const QString &title, quint16 year, quint16 duration);

    QString getTitle() const;
    void setTitle(const QString &value);

    quint16 getYear() const;
    void setYear(const quint16 &value);

    quint16 getDuration() const;
    void setDuration(const quint16 &value);

    QString toString() const;

private:
    QString title;
    quint16 year;
    quint16 duration;
};

QDebug& operator<<(QDebug &out, const Movie &movie);

#endif // MOVIE_H
