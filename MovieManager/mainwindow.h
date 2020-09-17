#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddMovie_clicked();

    void on_btnDeleteMovie_clicked();

    void on_btnCleanMovie_clicked();

    void on_btnSaveMovie_clicked();

    void on_btnEditMovie_clicked();

    void on_btnSaveListMovie_clicked();

    void on_btnOpenListMovie_clicked();

private:
    Ui::MainWindow *ui;

    // model pour la liste de movies (title only)
    QStringListModel *modelTitles;

    void cleanMovieForm();
    void saveListMovieFromWidget();
    void saveListMovieFromModel();
    void editMovieFromWidget();
    void editMovieFromWiew();
    void loadListMovie();
    static const QString BACKUP_MOVIE_FILENAME;
};
#endif // MAINWINDOW_H
