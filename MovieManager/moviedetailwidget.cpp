#include "moviedetailwidget.h"
#include "ui_moviedetailwidget.h"

MovieDetailWidget::MovieDetailWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MovieDetailWidget)
{
    ui->setupUi(this);
}

MovieDetailWidget::~MovieDetailWidget()
{
    delete ui;
}

void MovieDetailWidget::update(const Movie &movie)
{
    ui->lblTitle->setText(movie.getTitle());
    ui->lblYear->setText(QString::number(movie.getYear()));
    ui->lblDuration->setText(QString::number(movie.getDuration()));
}
