#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOrdenarInicio_clicked()
{
    ED1::Piloto exibePiloto;
    ED1::Lista *listaPiloto = 0;
    QString saida = "";
    int linha = 0;
        try{
            ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"OrdenarInicio",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));
            listaPiloto = ordenacao.inclusaoInicio();
            ui->tableWidgetSaida -> setRowCount ( listaPiloto->getQuantidadeDeElementos()) ;
            ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibePiloto.getNome()));
            while(!listaPiloto->listaVazia()){
                exibePiloto = listaPiloto->retirarInicio();
                ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibePiloto.getNumero())));
                ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibePiloto.getNome()));
                ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibePiloto.getPais()));
                ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(QString::number(exibePiloto.getIdade())));
                ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibePiloto.getEquipe()));
                ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibePiloto.getMotor()));
                ui->tableWidgetSaida->setItem(linha , 6, new QTableWidgetItem(QString::number(exibePiloto.getPontos())));
                linha++;
            }
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonOrdenarFim_clicked()
{
    ED1::Piloto exibePiloto;
    ED1::Lista *listaPiloto = 0;
    QString saida = "";
    int linha = 0;
        try{
            ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"OrdenarInicio",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));
            listaPiloto = ordenacao.inclusaoFim();
            ui->tableWidgetSaida -> setRowCount ( listaPiloto->getQuantidadeDeElementos()) ;
            ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibePiloto.getNome()));
            while(!listaPiloto->listaVazia()){
                exibePiloto = listaPiloto->retirarFim();
                ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibePiloto.getNumero())));
                ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibePiloto.getNome()));
                ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibePiloto.getPais()));
                ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(QString::number(exibePiloto.getIdade())));
                ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibePiloto.getEquipe()));
                ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibePiloto.getMotor()));
                ui->tableWidgetSaida->setItem(linha , 6, new QTableWidgetItem(QString::number(exibePiloto.getPontos())));
                linha++;
            }
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonOrdenado_clicked()
{
    ED1::Piloto exibePiloto;
    ED1::Lista *listaPiloto = 0;
    QString saida = "";
    int linha = 0;
        try{
            ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"OrdenarInicio",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));
            listaPiloto = ordenacao.inclusaoOrdenada();
            ui->tableWidgetSaida -> setRowCount ( listaPiloto->getQuantidadeDeElementos()) ;
            ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibePiloto.getNome()));
            while(!listaPiloto->listaVazia()){
                exibePiloto = listaPiloto->retirarInicio();
                ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibePiloto.getNumero())));
                ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibePiloto.getNome()));
                ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibePiloto.getPais()));
                ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(QString::number(exibePiloto.getIdade())));
                ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibePiloto.getEquipe()));
                ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibePiloto.getMotor()));
                ui->tableWidgetSaida->setItem(linha , 6, new QTableWidgetItem(QString::number(exibePiloto.getPontos())));
                linha++;
            }
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonPosicao_clicked()
{
    ED1::Piloto exibePiloto;
    ED1::Lista *listaPiloto = 0;
    QString saida = "";
    int linha = 0;
        try{
            ED1::Persistencia ordenacao(QFileDialog::getOpenFileName(this,"OrdenarInicio",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)"));
            listaPiloto = ordenacao.inclusaoOrdenada();
            ui->tableWidgetSaida -> setRowCount (1) ;
            ui->tableWidgetSaida->setItem(1 , 1, new QTableWidgetItem(exibePiloto.getNome()));
            exibePiloto = listaPiloto->retirarDoMeio((ui->lineEditPosicao->text().toInt()) - 1);
            ui->tableWidgetSaida->setItem(linha , 0, new QTableWidgetItem(QString::number(exibePiloto.getNumero())));
            ui->tableWidgetSaida->setItem(linha , 1, new QTableWidgetItem(exibePiloto.getNome()));
            ui->tableWidgetSaida->setItem(linha , 2, new QTableWidgetItem(exibePiloto.getPais()));
            ui->tableWidgetSaida->setItem(linha , 3, new QTableWidgetItem(QString::number(exibePiloto.getIdade())));
            ui->tableWidgetSaida->setItem(linha , 4, new QTableWidgetItem(exibePiloto.getEquipe()));
            ui->tableWidgetSaida->setItem(linha , 5, new QTableWidgetItem(exibePiloto.getMotor()));
            ui->tableWidgetSaida->setItem(linha , 6, new QTableWidgetItem(QString::number(exibePiloto.getPontos())));
                linha++;
    }catch(QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
