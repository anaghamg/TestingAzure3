#ifndef INPUTSCREEN_H
#define INPUTSCREEN_H

#include <QObject>
#include <QtWidgets>

class InputScreen : public QWidget
{
    Q_OBJECT
public:
    explicit InputScreen(QWidget *parent = nullptr);

    QLineEdit *resfield;
    QPushButton *submitButton;

signals:
    void ResolutionUpdated(int resolution);

public slots:
    void setResolution();

private:
    int m_resolution;
};

#endif // INPUTSCREEN_H
