#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("To Do List");

    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#3C424A"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setFixedSize(400, 500);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::adicionarTarefa);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removerTarefas);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::adicionarTarefa);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::atualizarHora);
    timer->start(1000);
    atualizarHora();

    atualizarProgresso();
    atualizarMensagemVazio();
    atualizarEstadoBotoes();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::adicionarTarefa() {
    QString texto = ui->lineEdit->text().trimmed();
    if (!texto.isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem();
        QWidget* widget = criarTarefa(texto);

        item->setSizeHint(widget->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);

        ui->lineEdit->clear();
        atualizarProgresso();
        atualizarMensagemVazio();
        atualizarEstadoBotoes();
    }
}

void MainWindow::removerTarefas() {
    for (int i = ui->listWidget->count() - 1; i >= 0; --i) {
        QListWidgetItem* item = ui->listWidget->item(i);
        QWidget* widget = ui->listWidget->itemWidget(item);
        QCheckBox* checkbox = widget->findChild<QCheckBox*>();

        if (checkbox && checkbox->isChecked()) {
            delete ui->listWidget->takeItem(i);
        }
    }
    atualizarProgresso();
    atualizarMensagemVazio();
    atualizarEstadoBotoes();
}

void MainWindow::atualizarHora() {
    QString horaAtual = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->labelHora->setText(horaAtual);
}

void MainWindow::atualizarProgresso() {
    int total = ui->listWidget->count();
    if (total == 0) {
        ui->progressBar->setValue(0);
        return;
    }

    int feitas = 0;
    for (int i = 0; i < total; ++i) {
        QWidget* widget = ui->listWidget->itemWidget(ui->listWidget->item(i));
        QCheckBox* checkbox = widget->findChild<QCheckBox*>();
        if (checkbox && checkbox->isChecked()) {
            feitas++;
        }
    }

    int progresso = static_cast<int>((feitas * 100.0) / total);
    ui->progressBar->setValue(progresso);
}

void MainWindow::atualizarMensagemVazio() {
    bool listaVazia = (ui->listWidget->count() == 0);
    ui->emptyLabel->setVisible(listaVazia);
}

void MainWindow::atualizarEstadoBotoes() {
    bool temTarefas = (ui->listWidget->count() > 0);
    ui->removeButton->setEnabled(temTarefas);
}

QWidget* MainWindow::criarTarefa(const QString& texto) {
    QWidget* widget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->setContentsMargins(8, 8, 8, 8);

    QCheckBox* checkbox = new QCheckBox(texto);
    QFont font = checkbox->font();
    font.setPointSize(14);
    checkbox->setFont(font);

    // Estilo
    checkbox->setStyleSheet(R"(
        QCheckBox {
            spacing: 12px;
            color: white;
        }
        QCheckBox::indicator {
            width: 18px;
            height: 18px;
            border-radius: 7px;
            border: 2px solid #3498db;
            background-color: white;
        }
        QCheckBox::indicator:checked {
            border: 2px solid #2ecc71;
            background-color: #25a059;
        }
    )");

    layout->addWidget(checkbox, 0, Qt::AlignVCenter);

    connect(checkbox, &QCheckBox::stateChanged, this, &MainWindow::atualizarProgresso);

    return widget;
}

