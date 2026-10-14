#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Task.h"

#include <QPushButton>
#include <QLabel>
#include <Qt>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Gestor de tareas");

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::abrirTarea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abrirTarea()
{
    Task *tarea = new Task(this);

    // Mostrar Task como ventana independiente.
    tarea->setWindowFlag(Qt::Window);

    // Liberar el objeto al cerrar su ventana.
    tarea->setAttribute(Qt::WA_DeleteOnClose);

    // Comunicar Task con MainWindow.
    connect(tarea, &Task::estadoCambiado,
            this, &MainWindow::actualizarEstado);

    tarea->show();
}

void MainWindow::actualizarEstado(
    const QString &nombre, bool completada)
{
    QString estado;

    if (completada) {
        estado = "Completada";
    } else {
        estado = "Pendiente";
    }

    ui->statusLabel->setText(nombre + ": " + estado);
}
