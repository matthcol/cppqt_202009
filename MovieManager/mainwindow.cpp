#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backupfile.h"
#include <QDebug>

const QString MainWindow::BACKUP_MOVIE_FILENAME = "movies.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnSaveMovie->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAddMovie_clicked()
{
    QString title = ui->leTitle->text();
    // TODO : check title + other fields are valid
    ui->lwMovies->addItem(title);
    cleanMovieForm();
}

void MainWindow::on_btnDeleteMovie_clicked()
{
    QListWidgetItem *item = ui->lwMovies->currentItem();
    if (item != nullptr) {
        QString titleMovieToDelete = item->text();  // item->data(Qt::DisplayRole);
        item = ui->lwMovies->takeItem(ui->lwMovies->currentRow());
        qDebug() << titleMovieToDelete << "deleted";
        // delete item from memory
        delete item;
    }
}

void MainWindow::on_btnCleanMovie_clicked()
{
    cleanMovieForm();
}

void MainWindow::on_btnSaveMovie_clicked()
{
    QString modifiedTitle = ui->leTitle->text();
    QListWidgetItem *item = ui->lwMovies->currentItem();
    if (item != nullptr) {
        // TODO : check title + other fields are valid
        item->setText(modifiedTitle);
        ui->btnSaveMovie->setEnabled(false);
        cleanMovieForm();
    }
}

void MainWindow::on_btnEditMovie_clicked()
{
    QListWidgetItem *item = ui->lwMovies->currentItem();
    if (item != nullptr) {
        QString titleMovieToEdit = item->text();
        ui->leTitle->setText(titleMovieToEdit);
        ui->btnSaveMovie->setEnabled(true);
    }
}



void MainWindow::on_btnSaveListMovie_clicked()
{
    saveListMovie();
}


void MainWindow::on_btnOpenListMovie_clicked()
{
    loadListMovie();
}

void MainWindow::cleanMovieForm()
{
    // default form settings
    ui->leTitle->setText("");
}

void MainWindow::saveListMovie()
{
    QStringList listMovie;
    // parcourir tous les items pour collecter les titres à sauver
    for (int i=0; i < ui->lwMovies->count(); i++) {
        // accéder à l'item d'index i
        QListWidgetItem *item = ui->lwMovies->item(i);
        // accéder au modèle texte de l'item et ajout dans la liste de movie
        listMovie << item->text();
    }
    qDebug() << listMovie;
    saveListMovieTextFile(listMovie, BACKUP_MOVIE_FILENAME);
}

void MainWindow::loadListMovie()
{
    try {
        QStringList movieList = loadListMovieTextFile(BACKUP_MOVIE_FILENAME);
        ui->lwMovies->clear();
//        for (QString &title: movieList) {
//             ui->lwMovies->addItem(title);
//        }
        ui->lwMovies->addItems(movieList);
    }  catch (std::runtime_error &e) {
        // signal pb to user
    }
}
























