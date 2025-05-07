#include "visualizationscreen.h"

VisualizationScreen::VisualizationScreen(QWidget *parent) : QWidget(parent)
{
    this->hide();
}

void VisualizationScreen::Visualize(int resolution)
{
    vtkNew<vtkNamedColors> colors;
    std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
    colors->SetColor("BkgColor", bkg.data());

    vtkNew<vtkCylinderSource> cylinder;
    cylinder->SetResolution(resolution);

    vtkNew<vtkPolyDataMapper> cylinderMapper;
    cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

    vtkNew<vtkActor> cylinderActor;
    cylinderActor->SetMapper(cylinderMapper);
    cylinderActor->GetProperty()->SetColor(
    colors->GetColor4d("Tomato").GetData());
    cylinderActor->RotateX(30.0);
    cylinderActor->RotateY(-45.0);

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(cylinderActor);
    renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());

    renderer->ResetCamera();
    renderer->GetActiveCamera()->Zoom(1.5);

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    renderWindow->SetSize(300, 300);
    renderWindow->AddRenderer(renderer);
    renderWindow->SetWindowName("Cylinder");

    QVTKOpenGLNativeWidget *RenderWidget = new QVTKOpenGLNativeWidget();
    RenderWidget->SetRenderWindow(renderWindow);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(RenderWidget);
    this->setLayout(layout);
}
