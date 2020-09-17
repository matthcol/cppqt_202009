#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_btnActionClap_clicked();

    void on_btnActionClap_pressed();

    void on_btnActionClap_released();

    void on_rbLanguageCpp_toggled(bool checked);

    void on_spinBox_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_teSummary_copyAvailable(bool b);

    void on_lnDay_textChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_actionOpen_triggered();

    void on_btnOpen_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
