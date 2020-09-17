#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // let's see what's inside
    qDebug() << ui->lblDay->text() << ": " << ui->lnDay->text();
    ui->lnDay->setText("東京");
    qDebug() << ui->btnSay->text();

    qDebug() << ui->rbLanguageCpp->isChecked();
    qDebug() << ui->ckLanguageCpp->isChecked();

    qDebug() << ui->spinBox->value();
    qDebug() << ui->doubleSpinBox->value();
    qDebug() << ui->horizontalSlider->value();

    qDebug() << ui->dateEdit->date();
}

MainWindow::~MainWindow()
{
    delete ui; // detruire l'arbre de composant graphique (en cascade)
}



// methode connecté au slot clicked du pushbutton btnActionClap
void MainWindow::on_btnActionClap_clicked()
{
      QString day = ui->lnDay->text();
      QDate date = ui->dateEdit->date();
      QString language = ui->cbLanguage->currentText();
      bool isJava = ui->ckLanguageJava->isChecked();
      bool isCpp = ui->rbLanguageCpp->isChecked();
      quint8 nb = ui->spinBox->value();
      double nb2 = ui->doubleSpinBox->value();
      QString summary = ui->teSummary->toPlainText();
      // collect other infos
      // debug : display info collected
      QString message = QString("%1, %2, %3")
              .arg(day).arg(date.toString()).arg(nb);
//      << ", "
//               << date << ", "
//               << language << ", "
//               << day << ", "
//               << (isJava ? "Java" : "No Java") << ", "
//               << (isCpp ? "C++": "No C++") << ", "
//               << nb << "," << nb2 << "," << summary;
      qDebug() << "new data: " << message;
}

void MainWindow::on_btnActionClap_pressed()
{
    qDebug() << "Add Movie pressed";
}

void MainWindow::on_btnActionClap_released()
{
    qDebug() << "Add Movie released";
}

void MainWindow::on_rbLanguageCpp_toggled(bool checked)
{
    qDebug() << "C++" << (checked ? "ok" : "nok");
    // ui->rbLanguageJava->setChecked(checked);
}

void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    qDebug() << "Nb text has changed:" << arg1;
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    qDebug() << "Nb value has changed:" << arg1;
}

void MainWindow::on_teSummary_copyAvailable(bool b)
{
    qDebug() << "Data copy available: " << b;
}

void MainWindow::on_lnDay_textChanged(const QString &arg1)
{
    qDebug() << "line edit changed " << arg1;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    qDebug() << "Tab changed: " << index;
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Open file";
}

void MainWindow::on_btnOpen_clicked()
{
    qDebug() << "Open file";
}
