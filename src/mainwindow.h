#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "inputscreen.h"
#include "visualizationscreen.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void DisplayVisualizationScreen(int resolution);

private:
    InputScreen *inputScreen;
    VisualizationScreen *visualizationScreen;
};

#endif // MAINWINDOW_H
