#include "movie.h"

Movie::Movie()
{
    // movie with default values
}

Movie::Movie(const QString &title, quint16 year, quint16 duration)
    :title(title), year(year), duration(duration)
{

}

QString Movie::getTitle() const
{
    return title;
}

void Movie::setTitle(const QString &value)
{
    title = value;
}

quint16 Movie::getYear() const
{
    return year;
}

void Movie::setYear(const quint16 &value)
{
    year = value;
}

quint16 Movie::getDuration() const
{
    return duration;
}

void Movie::setDuration(const quint16 &value)
{
    duration = value;
}

QString Movie::toString() const
{
    return QString("%1 (%2)")
            .arg(title)
            .arg(year);
}

QDebug &operator<<(QDebug &out, const Movie &movie)
{
    return out << movie.toString();
}
