/********************************************************************************
** Form generated from reading UI file 'dissector_tables_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISSECTOR_TABLES_DIALOG_H
#define UI_DISSECTOR_TABLES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "widgets/dissector_tables_view.h"

QT_BEGIN_NAMESPACE

class Ui_DissectorTablesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtSearchLine;
    DissectorTablesTreeView *tableTree;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DissectorTablesDialog)
    {
        if (DissectorTablesDialog->objectName().isEmpty())
            DissectorTablesDialog->setObjectName(QString::fromUtf8("DissectorTablesDialog"));
        DissectorTablesDialog->resize(400, 351);
        verticalLayout = new QVBoxLayout(DissectorTablesDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DissectorTablesDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtSearchLine = new QLineEdit(DissectorTablesDialog);
        txtSearchLine->setObjectName(QString::fromUtf8("txtSearchLine"));

        horizontalLayout->addWidget(txtSearchLine);


        verticalLayout->addLayout(horizontalLayout);

        tableTree = new DissectorTablesTreeView(DissectorTablesDialog);
        tableTree->setObjectName(QString::fromUtf8("tableTree"));
        tableTree->setUniformRowHeights(true);

        verticalLayout->addWidget(tableTree);

        buttonBox = new QDialogButtonBox(DissectorTablesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DissectorTablesDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DissectorTablesDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DissectorTablesDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DissectorTablesDialog);
    } // setupUi

    void retranslateUi(QDialog *DissectorTablesDialog)
    {
        DissectorTablesDialog->setWindowTitle(QCoreApplication::translate("DissectorTablesDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DissectorTablesDialog", "Search:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DissectorTablesDialog: public Ui_DissectorTablesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISSECTOR_TABLES_DIALOG_H
