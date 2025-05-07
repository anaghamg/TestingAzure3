#include "inputscreen.h"

InputScreen::InputScreen(QWidget *parent) : QWidget(parent)
{
    QLabel *res = new QLabel(this);
    res->setText("Resolution:");
    resfield = new QLineEdit(this);
    resfield->setPlaceholderText("Enter cylinder resolution here");
    resfield->setMaxLength(2);

    QHBoxLayout *reslayout = new QHBoxLayout();
    reslayout->addWidget(res);
    reslayout->addWidget(resfield);

    submitButton = new QPushButton("Submit", this);

    QVBoxLayout *finalLayout = new QVBoxLayout(this);
    finalLayout->addLayout(reslayout);
    finalLayout->addWidget(submitButton);
    this->show();

    connect(this->submitButton, SIGNAL(clicked()), this, SLOT(setResolution()));
}

void InputScreen::setResolution()
{
    m_resolution = resfield->text().toInt();
    emit ResolutionUpdated(m_resolution);
}
