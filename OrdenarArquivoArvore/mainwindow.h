#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Fila.h>
#include <Pilha.h>
#include <ArvoreBinariaPorCodigo.h>
#include <Aluno.h>
#include <Persistencia.h>
#include <QMainWindow>
#include <QMessageBox>
#include<fstream>
#include <QFileDialog>
#include <Ordenacao.h>
#include <ArvoreBinariaPorNome.h>

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

    void exibeDados(ED1::Fila<ED1::Aluno> *filaDeDados);

    void exibeDadoPilha(ED1::Pilha<ED1::Aluno> *pilhaDeDados);

    void on_pushButtonPreFDireita_clicked();

    void on_pushButtonPosFDireita_clicked();

    void on_pushButtonPreFEsquerda_clicked();

    void on_pushButtonProsFEsquerda_clicked();

    void on_pushButtonOrdenarPorNomeFila_clicked();

    void on_pushButtonOrdenarPorNomePilha_clicked();

    void on_pushButtonNomePreFDireita_clicked();

    void on_pushButtonNomePosFDireita_clicked();

    void on_pushButtonNomePreFEsquerda_clicked();

    void on_pushButtonNomeProsFEsquerda_clicked();

    void on_pushButtonOrdenarPorSobrenomeFila_clicked();

    void on_pushButtonSobrenomePreFDireita_clicked();

    void on_pushButtonSobrenomePosFDireita_clicked();

    void on_pushButtonOrdenarPorSobrenomePilha_clicked();

    void on_pushButtonSobreNomePreFEsquerda_clicked();

    void on_pushButtonSobrenomeProsFEsquerda_clicked();

private:
    Ui::MainWindow *ui;
    QString diretorioArquivo;
};

#endif // MAINWINDOW_H
