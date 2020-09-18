#ifndef MOVIEDETAILWIDGET_H
#define MOVIEDETAILWIDGET_H

#include <QFrame>
#include "movie.h"

namespace Ui {
class MovieDetailWidget;
}

class MovieDetailWidget : public QFrame
{
    Q_OBJECT

public:
    explicit MovieDetailWidget(QWidget *parent = nullptr);
    ~MovieDetailWidget();

public slots:
    void update(const Movie &movie);
private:
    Ui::MovieDetailWidget *ui;
};

#endif // MOVIEDETAILWIDGET_H
