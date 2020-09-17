#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backupfile.h"
#include <QDebug>

const QString MainWindow::BACKUP_MOVIE_FILENAME = "movies.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modelTitles(new QStringListModel)
{
    ui->setupUi(this);
    // extra init ui settings
    ui->btnSaveMovie->setEnabled(false);

    // attach model to view
    ui->lvMovies->setModel(modelTitles);
}

// destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete modelTitles;
}


void MainWindow::on_btnAddMovie_clicked()
{
    addMovieToView();
}

void MainWindow::on_btnDeleteMovie_clicked()
{
    removeMovieFromView();
}

void MainWindow::on_btnCleanMovie_clicked()
{
    cleanMovieForm();
}

void MainWindow::on_btnSaveMovie_clicked()
{
    saveMovieToView();
}

void MainWindow::on_btnEditMovie_clicked()
{
    editMovieFromWiew();
}



void MainWindow::on_btnSaveListMovie_clicked()
{
    // saveListMovieFromWidget();
    saveListMovieFromModel();
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

/**
 * save list from ListWidget to file
 * @brief MainWindow::saveListMovie
 */
void MainWindow::saveListMovieFromWidget()
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

void MainWindow::saveListMovieFromModel()
{
   QStringList listMovie = modelTitles->stringList();
   saveListMovieTextFile(listMovie, BACKUP_MOVIE_FILENAME);
}

void MainWindow::editMovieFromWidget()
{
    QListWidgetItem *item = ui->lwMovies->currentItem();
    if (item != nullptr) {
        QString titleMovieToEdit = item->text();
        ui->leTitle->setText(titleMovieToEdit);
        ui->btnSaveMovie->setEnabled(true);
    }
}

void MainWindow::editMovieFromWiew()
{
    // get selection index from view
    QModelIndex index = ui->lvMovies->currentIndex();
    if (index != QModelIndex()) {
        // get title movie from model at same index
        QString titleMovieToEdit = modelTitles->data(index, Qt::EditRole).toString();
        qDebug() << "edit title:" << titleMovieToEdit;
        ui->leTitle->setText(titleMovieToEdit);
        ui->btnSaveMovie->setEnabled(true);
    } else {
        qDebug() << "no title selected for edition";
    }
}

void MainWindow::saveMovieToWidget()
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

void MainWindow::saveMovieToView()
{
    QString modifiedTitle = ui->leTitle->text();
    QModelIndex index = ui->lvMovies->currentIndex();
    if (index != QModelIndex()) {
        modelTitles->setData(index, QVariant(modifiedTitle), Qt::EditRole);
    }
}

void MainWindow::addMovieToWidget()
{
    QString title = ui->leTitle->text();
    // TODO : check title + other fields are valid
    ui->lwMovies->addItem(title);
    cleanMovieForm();
}

void MainWindow::addMovieToView()
{
    QString title = ui->leTitle->text();
    // TODO
}

void MainWindow::removeMovieFromWidget()
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

void MainWindow::removeMovieFromView()
{
    // TODO
}

/**
 * load list titles from files and refresh ListView and ListWidget
 * @brief MainWindow::loadListMovie
 */
void MainWindow::loadListMovie()
{
    try {
        // read movi titles from file
        QStringList movieList = loadListMovieTextFile(BACKUP_MOVIE_FILENAME);
        // update list widget
        ui->lwMovies->clear();
        ui->lwMovies->addItems(movieList);
        // update model list view
        modelTitles->setStringList(movieList);
    }  catch (std::runtime_error &e) {
        // signal pb to user
    }
}
























