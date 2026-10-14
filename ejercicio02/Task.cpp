#include "Task.h"
#include "ui_Task.h"

#include <QCheckBox>
#include <QLineEdit>

Task::Task(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Task)
{
    ui->setupUi(this);

    setWindowTitle("Registrar tarea");

    connect(ui->checkbox, &QCheckBox::toggled,
            this, &Task::notificarEstado);
}

Task::~Task()
{
    delete ui;
}

void Task::notificarEstado(bool marcado)
{
    QString nombre = ui->MiText->text().trimmed();

    if (nombre.isEmpty()) {
        nombre = "Sin nombre";
    }

    emit estadoCambiado(nombre, marcado);
}
