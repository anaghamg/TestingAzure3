#ifndef VISUALIZATIONSCREEN_H
#define VISUALIZATIONSCREEN_H

#include <QMainWindow>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCylinderSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>

#include <array>

class VisualizationScreen : public QWidget
{
    Q_OBJECT
public:
    explicit VisualizationScreen(QWidget *parent = nullptr);

    void Visualize(int resolution);

signals:

public slots:
};

#endif // VISUALIZATIONSCREEN_H
