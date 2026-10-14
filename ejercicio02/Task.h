#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void estadoCambiado(const QString &nombre, bool completada);

private slots:
    void notificarEstado(bool marcado);

private:
    Ui::Task *ui;
};

#endif // TASK_H
