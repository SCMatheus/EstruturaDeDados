#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetSaida->setColumnWidth(0,140);
    ui->tableWidgetSaida->setColumnWidth(1,200);
    ui->tableWidgetSaida->setColumnWidth(2,160);
    ui->tableWidgetSaida->setColumnWidth(3,150);
    ui->tableWidgetSaida->setColumnWidth(4,140);
    ui->tableWidgetSaida->setColumnWidth(5,120);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOrdenarPorCodigo_clicked()
{
    ED1::Pilha<ED1::Aluno> *primeiraPilha = 0;
    ED1::Ordenacao ordena;

    try{
        ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"Ordenar Por Codigo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));

        primeiraPilha = ordenacao.PegaDadosArquivo();

        primeiraPilha = ordena.ordenaPorCodigo(primeiraPilha);

        exibeDados(primeiraPilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonOrdenarPorNome_clicked()
{
    ED1::Pilha<ED1::Aluno> *primeiraPilha = 0;
    ED1::Ordenacao ordena;

    try{
        ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"Ordenar Por Codigo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));

        primeiraPilha = ordenacao.PegaDadosArquivo();

        primeiraPilha = ordena.ordenaPorNome(primeiraPilha);

        exibeDados(primeiraPilha);

    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }  
}

void MainWindow::exibeDados(ED1::Pilha<ED1::Aluno> *pilhaDeDados){

    ED1::Aluno exibeAluno;
    int linha = 0;

    ui->tableWidgetSaida -> setRowCount ( pilhaDeDados->getQuantidadedeElementos()) ;
    ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibeAluno.getNome()));
    while(!pilhaDeDados->vazia()){
        exibeAluno = pilhaDeDados->remover();
        ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibeAluno.getCodigo())));
        ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibeAluno.getNome()));
        ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibeAluno.getCurso()));
        ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(exibeAluno.getGraduacao()));
        ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibeAluno.getNaosei()));
        ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibeAluno.getData()));
        linha++;
    }
}
