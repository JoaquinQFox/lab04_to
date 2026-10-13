#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(350, 200);

    // Se añade nombres de colores
    ui->colorList->addItems({
        "Rojo",
        "Azul",
        "Verde",
        "Amarillo",
        "Naranja",
        "Morado",
        "Celeste"
    });

    // Se selecciona primer elemento de la lista
    ui->colorList->setCurrentRow(0);
    mostrarColor(ui->colorList->currentItem());

    connect(ui->colorList, &QListWidget::itemClicked, this, &MainWindow::mostrarColor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarColor(QListWidgetItem *item)
{
    QString nombre{ item->text() };
    QColor color{};

    if (nombre == "Rojo") {
        color = QColor(255, 0, 0);
    } else if (nombre == "Azul") {
        color = QColor(0, 0, 255);
    } else if (nombre == "Verde") {
        color = QColor(0, 255, 0);
    } else if (nombre == "Amarillo") {
        color = QColor(255, 255, 0);
    } else if (nombre == "Naranja") {
        color = QColor(255, 165, 0);
    } else if (nombre == "Morado") {
        color = QColor(128, 0, 128);
    } else if (nombre == "Celeste") {
        color = QColor(0, 191, 255);
    }

    ui->colorLabel->setText(item->text());
    ui->colorLabel->setStyleSheet(
        QString("background-color: %1;").arg(color.name())
    );
}
