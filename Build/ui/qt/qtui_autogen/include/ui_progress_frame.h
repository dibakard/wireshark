/********************************************************************************
** Form generated from reading UI file 'progress_frame.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_FRAME_H
#define UI_PROGRESS_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include "widgets/stock_icon_tool_button.h"

QT_BEGIN_NAMESPACE

class Ui_ProgressFrame
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    StockIconToolButton *stopButton;

    void setupUi(QFrame *ProgressFrame)
    {
        if (ProgressFrame->objectName().isEmpty())
            ProgressFrame->setObjectName(QString::fromUtf8("ProgressFrame"));
        ProgressFrame->resize(210, 38);
        ProgressFrame->setFrameShape(QFrame::NoFrame);
        ProgressFrame->setFrameShadow(QFrame::Raised);
        ProgressFrame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(ProgressFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label = new QLabel(ProgressFrame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(ProgressFrame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        horizontalLayout->addWidget(progressBar);

        stopButton = new StockIconToolButton(ProgressFrame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(stopButton);


        retranslateUi(ProgressFrame);

        QMetaObject::connectSlotsByName(ProgressFrame);
    } // setupUi

    void retranslateUi(QFrame *ProgressFrame)
    {
        ProgressFrame->setWindowTitle(QCoreApplication::translate("ProgressFrame", "Frame", nullptr));
        label->setText(QCoreApplication::translate("ProgressFrame", "Loading", nullptr));
        stopButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProgressFrame: public Ui_ProgressFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_FRAME_H
