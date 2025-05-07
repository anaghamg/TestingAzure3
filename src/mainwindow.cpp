#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    inputScreen = new InputScreen(this);
    visualizationScreen = new VisualizationScreen(this);
    setCentralWidget(inputScreen);
    connect(inputScreen, SIGNAL(ResolutionUpdated(int)), this, SLOT(DisplayVisualizationScreen(int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::DisplayVisualizationScreen(int resolution)
{
    visualizationScreen->show();
    setCentralWidget(visualizationScreen);
    visualizationScreen->Visualize(resolution);
}
