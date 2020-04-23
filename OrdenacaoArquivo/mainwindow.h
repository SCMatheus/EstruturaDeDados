#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Pilha.h>
#include <Aluno.h>
#include <Persistencia.h>
#include <QMainWindow>
#include <QMessageBox>
#include<fstream>
#include <QFileDialog>
#include <Ordenacao.h>

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
    void on_pushButtonOrdenarPorCodigo_clicked();

    void on_pushButtonOrdenarPorNome_clicked();

    void exibeDados(ED1::Pilha<ED1::Aluno> *pilhaDeDados);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
