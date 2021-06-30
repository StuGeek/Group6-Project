#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MeshApp.h"
#include "data.h"

class MeshApp : public QMainWindow
{
    Q_OBJECT

public:
    MeshApp(QWidget *parent = Q_NULLPTR);

public slots:
    void _calculateProgressBar_set(int value);
    void _TimerLabel_set(struct Timer* timer);
    void _Iter_set(int iter);
    void _Rms_set(int rms);

private:
    Ui::MeshAppClass ui;
    Mesh* _mesh;
    FlowField* _flow_;
private slots:
    void on_calculateButton_clicked();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
};
