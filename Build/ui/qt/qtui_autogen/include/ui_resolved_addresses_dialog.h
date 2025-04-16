/********************************************************************************
** Form generated from reading UI file 'resolved_addresses_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOLVED_ADDRESSES_DIALOG_H
#define UI_RESOLVED_ADDRESSES_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ui/qt/widgets/resolved_addresses_view.h"

QT_BEGIN_NAMESPACE

class Ui_ResolvedAddressesDialog
{
public:
    QAction *actionComment;
    QAction *actionIPv4HashTable;
    QAction *actionIPv6HashTable;
    QAction *actionShowAll;
    QAction *actionHideAll;
    QAction *actionAddressesHosts;
    QAction *actionPortNames;
    QAction *actionEthernetAddresses;
    QAction *actionEthernetWKA;
    QAction *actionEthernetManufacturers;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSearchFilter;
    QComboBox *cmbDataType;
    ResolvedAddressesView *tblAddresses;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtPortFilter;
    QComboBox *cmbPortFilterType;
    ResolvedAddressesView *tblPorts;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResolvedAddressesDialog)
    {
        if (ResolvedAddressesDialog->objectName().isEmpty())
            ResolvedAddressesDialog->setObjectName(QString::fromUtf8("ResolvedAddressesDialog"));
        ResolvedAddressesDialog->resize(620, 450);
        actionComment = new QAction(ResolvedAddressesDialog);
        actionComment->setObjectName(QString::fromUtf8("actionComment"));
        actionComment->setCheckable(true);
        actionComment->setChecked(true);
        actionIPv4HashTable = new QAction(ResolvedAddressesDialog);
        actionIPv4HashTable->setObjectName(QString::fromUtf8("actionIPv4HashTable"));
        actionIPv4HashTable->setCheckable(true);
        actionIPv6HashTable = new QAction(ResolvedAddressesDialog);
        actionIPv6HashTable->setObjectName(QString::fromUtf8("actionIPv6HashTable"));
        actionIPv6HashTable->setCheckable(true);
        actionShowAll = new QAction(ResolvedAddressesDialog);
        actionShowAll->setObjectName(QString::fromUtf8("actionShowAll"));
        actionHideAll = new QAction(ResolvedAddressesDialog);
        actionHideAll->setObjectName(QString::fromUtf8("actionHideAll"));
        actionAddressesHosts = new QAction(ResolvedAddressesDialog);
        actionAddressesHosts->setObjectName(QString::fromUtf8("actionAddressesHosts"));
        actionAddressesHosts->setCheckable(true);
        actionAddressesHosts->setChecked(true);
        actionPortNames = new QAction(ResolvedAddressesDialog);
        actionPortNames->setObjectName(QString::fromUtf8("actionPortNames"));
        actionPortNames->setCheckable(true);
        actionPortNames->setChecked(true);
        actionEthernetAddresses = new QAction(ResolvedAddressesDialog);
        actionEthernetAddresses->setObjectName(QString::fromUtf8("actionEthernetAddresses"));
        actionEthernetAddresses->setCheckable(true);
        actionEthernetAddresses->setChecked(true);
        actionEthernetWKA = new QAction(ResolvedAddressesDialog);
        actionEthernetWKA->setObjectName(QString::fromUtf8("actionEthernetWKA"));
        actionEthernetWKA->setCheckable(true);
        actionEthernetWKA->setChecked(true);
        actionEthernetManufacturers = new QAction(ResolvedAddressesDialog);
        actionEthernetManufacturers->setObjectName(QString::fromUtf8("actionEthernetManufacturers"));
        actionEthernetManufacturers->setCheckable(true);
        actionEthernetManufacturers->setChecked(true);
        verticalLayout_2 = new QVBoxLayout(ResolvedAddressesDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(ResolvedAddressesDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtSearchFilter = new QLineEdit(tab);
        txtSearchFilter->setObjectName(QString::fromUtf8("txtSearchFilter"));

        horizontalLayout->addWidget(txtSearchFilter);

        cmbDataType = new QComboBox(tab);
        cmbDataType->setObjectName(QString::fromUtf8("cmbDataType"));

        horizontalLayout->addWidget(cmbDataType);


        verticalLayout->addLayout(horizontalLayout);

        tblAddresses = new ResolvedAddressesView(tab);
        tblAddresses->setObjectName(QString::fromUtf8("tblAddresses"));

        verticalLayout->addWidget(tblAddresses);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        txtPortFilter = new QLineEdit(tab_3);
        txtPortFilter->setObjectName(QString::fromUtf8("txtPortFilter"));

        horizontalLayout_2->addWidget(txtPortFilter);

        cmbPortFilterType = new QComboBox(tab_3);
        cmbPortFilterType->setObjectName(QString::fromUtf8("cmbPortFilterType"));

        horizontalLayout_2->addWidget(cmbPortFilterType);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tblPorts = new ResolvedAddressesView(tab_3);
        tblPorts->setObjectName(QString::fromUtf8("tblPorts"));

        verticalLayout_3->addWidget(tblPorts);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_4->addWidget(plainTextEdit);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(ResolvedAddressesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(ResolvedAddressesDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ResolvedAddressesDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ResolvedAddressesDialog, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ResolvedAddressesDialog);
    } // setupUi

    void retranslateUi(QDialog *ResolvedAddressesDialog)
    {
        ResolvedAddressesDialog->setWindowTitle(QCoreApplication::translate("ResolvedAddressesDialog", "Dialog", nullptr));
        actionComment->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Comment", nullptr));
#if QT_CONFIG(tooltip)
        actionComment->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show the comment.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionIPv4HashTable->setText(QCoreApplication::translate("ResolvedAddressesDialog", "IPv4 Hash Table", nullptr));
#if QT_CONFIG(tooltip)
        actionIPv4HashTable->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show the IPv4 hash table entries.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionIPv6HashTable->setText(QCoreApplication::translate("ResolvedAddressesDialog", "IPv6 Hash Table", nullptr));
#if QT_CONFIG(tooltip)
        actionIPv6HashTable->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show the IPv6 hash table entries.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionShowAll->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Show All", nullptr));
#if QT_CONFIG(tooltip)
        actionShowAll->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show all address types.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHideAll->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Hide All", nullptr));
#if QT_CONFIG(tooltip)
        actionHideAll->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Hide all address types.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAddressesHosts->setText(QCoreApplication::translate("ResolvedAddressesDialog", "IPv4 and IPv6 Addresses (hosts)", nullptr));
#if QT_CONFIG(tooltip)
        actionAddressesHosts->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show resolved IPv4 and IPv6 host names in \"hosts\" format.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPortNames->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Port names (services)", nullptr));
#if QT_CONFIG(tooltip)
        actionPortNames->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show resolved port names in \"services\" format.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEthernetAddresses->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Ethernet Addresses", nullptr));
#if QT_CONFIG(tooltip)
        actionEthernetAddresses->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show resolved Ethernet addresses in \"ethers\" format.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEthernetWKA->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Ethernet Well-Known Addresses", nullptr));
#if QT_CONFIG(tooltip)
        actionEthernetWKA->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show well-known Ethernet addresses in \"ethers\" format.", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEthernetManufacturers->setText(QCoreApplication::translate("ResolvedAddressesDialog", "Ethernet Manufacturers", nullptr));
#if QT_CONFIG(tooltip)
        actionEthernetManufacturers->setToolTip(QCoreApplication::translate("ResolvedAddressesDialog", "Show Ethernet manufacturers in \"ethers\" format.", nullptr));
#endif // QT_CONFIG(tooltip)
        txtSearchFilter->setPlaceholderText(QCoreApplication::translate("ResolvedAddressesDialog", "Search for entry (min 3 characters)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ResolvedAddressesDialog", "Hosts", nullptr));
        txtPortFilter->setPlaceholderText(QCoreApplication::translate("ResolvedAddressesDialog", "Search for port or name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("ResolvedAddressesDialog", "Ports", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ResolvedAddressesDialog", "Capture File Comments", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResolvedAddressesDialog: public Ui_ResolvedAddressesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOLVED_ADDRESSES_DIALOG_H
