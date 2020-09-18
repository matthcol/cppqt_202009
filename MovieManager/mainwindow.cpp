#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "backupfile.h"
#include <QDebug>
#include "movie.h"

const QString MainWindow::BACKUP_MOVIE_FILENAME = "movies.csv";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , modelMovies(new MovieListModel)
{
    ui->setupUi(this);
    // extra init ui settings
    ui->btnSaveMovie->setEnabled(false);


    // dummy list movies for the model
    QList<Movie> movies;
    movies << Movie("Pulp Fiction", 1994, 121) << Movie("E.T.", 1982, 117);
    modelMovies->setMovieList(movies);

    // attach model to view
    ui->lvMovies->setModel(modelMovies);
}

// destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete modelMovies;
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

void MainWindow::saveListMovieFromModel()
{
   QList<Movie> listMovie = modelMovies->getMovieList();
   saveListMovieTextFile(listMovie, BACKUP_MOVIE_FILENAME);
}


void MainWindow::editMovieFromWiew()
{
    // get selection index from view
    QModelIndex index = ui->lvMovies->currentIndex();
    if (index != QModelIndex()) {
        // get title movie from model at same index
        QString titleMovieToEdit = modelMovies->data(index, Qt::EditRole).toString();
        qDebug() << "edit title:" << titleMovieToEdit;
        ui->leTitle->setText(titleMovieToEdit);
        ui->btnSaveMovie->setEnabled(true);
    } else {
        qDebug() << "no title selected for edition";
    }
}


void MainWindow::saveMovieToView()
{
    QString modifiedTitle = ui->leTitle->text();
    QModelIndex index = ui->lvMovies->currentIndex();
    if (index != QModelIndex()) {
        modelMovies->setData(index, QVariant(modifiedTitle), Qt::EditRole);
    }
}


void MainWindow::addMovieToView()
{
    // read values from UI Form
    QString title = ui->leTitle->text();
    quint16 year = ui->spbYear->value();
    quint16 duration = ui->spbDuration->value();
    // create model object
    Movie movie(title, year, duration);
    // add title in model
    modelMovies->add(movie);
    // it's done
    // qDebug() << movie << "added";
}


void MainWindow::removeMovieFromView()
{
    QModelIndex index = ui->lvMovies->currentIndex();
    if (index != QModelIndex()) {
        modelMovies->remove(index.row());
    }
}

/**
 * load list titles from files and refresh ListView and ListWidget
 * @brief MainWindow::loadListMovie
 */
void MainWindow::loadListMovie()
{
//    try {
//        // read movi titles from file
//        QStringList movieList = loadListMovieTextFile(BACKUP_MOVIE_FILENAME);
//        // update model list view
//        modelMovies->setStringList(movieList);
//    }  catch (std::runtime_error &e) {
//        // signal pb to user
//    }
}
























