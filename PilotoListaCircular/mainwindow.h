#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<ListaCircular.h>
#include<No.h>
#include<Piloto.h>
#include<Persistencia.h>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include<fstream>
#include <QTableWidget>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonOrdenarInicio_clicked();

    void on_pushButtonOrdenarFim_clicked();

    void on_pushButtonOrdenado_clicked();

    void on_pushButtonPosicao_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
