/********************************************************************************
** Form generated from reading UI file 'capture_options_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURE_OPTIONS_DIALOG_H
#define UI_CAPTURE_OPTIONS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widgets/capture_filter_combo.h"

QT_BEGIN_NAMESPACE

class Ui_CaptureOptionsDialog
{
public:
    QVBoxLayout *verticalLayout_12;
    QTabWidget *tabWidget;
    QWidget *inputTab;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *interfaceTree;
    QHBoxLayout *horizontalLayout;
    QCheckBox *capturePromModeCheckBox;
    QCheckBox *captureMonitorModeCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *manageButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    CaptureFilterCombo *captureFilterComboBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *compileBPF;
    QWidget *outputTab;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *gbCaptureToFile;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *filenameLineEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QRadioButton *rbPcapng;
    QRadioButton *rbPcap;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_comp;
    QLabel *labelCompression;
    QRadioButton *rbCompressionNone;
    QRadioButton *rbCompressionGzip;
    QRadioButton *rbCompressionLZ4;
    QSpacerItem *horizontalSpacer_comp;
    QGroupBox *gbNewFileAuto;
    QGridLayout *gridLayout;
    QCheckBox *PktCheckBox;
    QSpinBox *PktSpinBox;
    QLabel *PktLabel;
    QCheckBox *MBCheckBox;
    QSpinBox *MBSpinBox;
    QComboBox *MBComboBox;
    QCheckBox *SecsCheckBox;
    QSpinBox *SecsSpinBox;
    QComboBox *SecsComboBox;
    QCheckBox *IntervalSecsCheckBox;
    QSpinBox *IntervalSecsSpinBox;
    QComboBox *IntervalSecsComboBox;
    QGroupBox *nameTemplateGB;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbTimeNum;
    QRadioButton *rbNumTime;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *RbCheckBox;
    QSpinBox *RbSpinBox;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_2;
    QWidget *optionsTab;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *cbUpdatePacketsRT;
    QCheckBox *cbAutoScroll;
    QCheckBox *cbExtraCaptureInfo;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cbResolveMacAddresses;
    QCheckBox *cbResolveNetworkNames;
    QCheckBox *cbResolveTransportNames;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *gbStopCaptureAuto;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *stopPktCheckBox;
    QSpinBox *stopPktSpinBox;
    QLabel *label_7;
    QCheckBox *stopFilesCheckBox;
    QSpinBox *stopFilesSpinBox;
    QLabel *label_8;
    QCheckBox *stopMBCheckBox;
    QSpinBox *stopMBSpinBox;
    QComboBox *stopMBComboBox;
    QCheckBox *stopSecsCheckBox;
    QSpinBox *stopSecsSpinBox;
    QComboBox *stopSecsComboBox;
    QGroupBox *gbTempDir;
    QGridLayout *gridLayout_4;
    QLineEdit *tempDirLineEdit;
    QPushButton *tempDirBrowseButton;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *nameTimeNumBG;

    void setupUi(QDialog *CaptureOptionsDialog)
    {
        if (CaptureOptionsDialog->objectName().isEmpty())
            CaptureOptionsDialog->setObjectName(QString::fromUtf8("CaptureOptionsDialog"));
        CaptureOptionsDialog->resize(950, 440);
        verticalLayout_12 = new QVBoxLayout(CaptureOptionsDialog);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        tabWidget = new QTabWidget(CaptureOptionsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        inputTab = new QWidget();
        inputTab->setObjectName(QString::fromUtf8("inputTab"));
        verticalLayout_2 = new QVBoxLayout(inputTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        interfaceTree = new QTreeWidget(inputTab);
        interfaceTree->headerItem()->setText(0, QString());
        interfaceTree->setObjectName(QString::fromUtf8("interfaceTree"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(interfaceTree->sizePolicy().hasHeightForWidth());
        interfaceTree->setSizePolicy(sizePolicy);
        interfaceTree->setSelectionMode(QAbstractItemView::ExtendedSelection);
        interfaceTree->setTextElideMode(Qt::ElideMiddle);
        interfaceTree->setSortingEnabled(true);

        verticalLayout_2->addWidget(interfaceTree);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        capturePromModeCheckBox = new QCheckBox(inputTab);
        capturePromModeCheckBox->setObjectName(QString::fromUtf8("capturePromModeCheckBox"));

        horizontalLayout->addWidget(capturePromModeCheckBox);

        captureMonitorModeCheckBox = new QCheckBox(inputTab);
        captureMonitorModeCheckBox->setObjectName(QString::fromUtf8("captureMonitorModeCheckBox"));

        horizontalLayout->addWidget(captureMonitorModeCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        manageButton = new QPushButton(inputTab);
        manageButton->setObjectName(QString::fromUtf8("manageButton"));
        manageButton->setEnabled(true);

        horizontalLayout->addWidget(manageButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(inputTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        captureFilterComboBox = new CaptureFilterCombo(inputTab);
        captureFilterComboBox->setObjectName(QString::fromUtf8("captureFilterComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(captureFilterComboBox->sizePolicy().hasHeightForWidth());
        captureFilterComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(captureFilterComboBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        compileBPF = new QPushButton(inputTab);
        compileBPF->setObjectName(QString::fromUtf8("compileBPF"));

        horizontalLayout_2->addWidget(compileBPF);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(inputTab, QString());
        outputTab = new QWidget();
        outputTab->setObjectName(QString::fromUtf8("outputTab"));
        verticalLayout_9 = new QVBoxLayout(outputTab);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        gbCaptureToFile = new QGroupBox(outputTab);
        gbCaptureToFile->setObjectName(QString::fromUtf8("gbCaptureToFile"));
        gbCaptureToFile->setEnabled(true);
        gbCaptureToFile->setAutoFillBackground(false);
        gbCaptureToFile->setFlat(true);
        gbCaptureToFile->setCheckable(false);
        gridLayout_3 = new QGridLayout(gbCaptureToFile);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(gbCaptureToFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        filenameLineEdit = new QLineEdit(gbCaptureToFile);
        filenameLineEdit->setObjectName(QString::fromUtf8("filenameLineEdit"));

        gridLayout_3->addWidget(filenameLineEdit, 0, 1, 1, 1);

        browseButton = new QPushButton(gbCaptureToFile);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        gridLayout_3->addWidget(browseButton, 0, 2, 1, 1);


        verticalLayout_9->addWidget(gbCaptureToFile);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(outputTab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        rbPcapng = new QRadioButton(outputTab);
        rbPcapng->setObjectName(QString::fromUtf8("rbPcapng"));

        horizontalLayout_3->addWidget(rbPcapng);

        rbPcap = new QRadioButton(outputTab);
        rbPcap->setObjectName(QString::fromUtf8("rbPcap"));

        horizontalLayout_3->addWidget(rbPcap);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_comp = new QHBoxLayout();
        horizontalLayout_comp->setObjectName(QString::fromUtf8("horizontalLayout_comp"));
        labelCompression = new QLabel(outputTab);
        labelCompression->setObjectName(QString::fromUtf8("labelCompression"));

        horizontalLayout_comp->addWidget(labelCompression);

        rbCompressionNone = new QRadioButton(outputTab);
        buttonGroup = new QButtonGroup(CaptureOptionsDialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(rbCompressionNone);
        rbCompressionNone->setObjectName(QString::fromUtf8("rbCompressionNone"));

        horizontalLayout_comp->addWidget(rbCompressionNone);

        rbCompressionGzip = new QRadioButton(outputTab);
        buttonGroup->addButton(rbCompressionGzip);
        rbCompressionGzip->setObjectName(QString::fromUtf8("rbCompressionGzip"));

        horizontalLayout_comp->addWidget(rbCompressionGzip);

        rbCompressionLZ4 = new QRadioButton(outputTab);
        buttonGroup->addButton(rbCompressionLZ4);
        rbCompressionLZ4->setObjectName(QString::fromUtf8("rbCompressionLZ4"));

        horizontalLayout_comp->addWidget(rbCompressionLZ4);

        horizontalSpacer_comp = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_comp->addItem(horizontalSpacer_comp);


        verticalLayout_9->addLayout(horizontalLayout_comp);

        gbNewFileAuto = new QGroupBox(outputTab);
        gbNewFileAuto->setObjectName(QString::fromUtf8("gbNewFileAuto"));
        gbNewFileAuto->setFlat(true);
        gbNewFileAuto->setCheckable(true);
        gridLayout = new QGridLayout(gbNewFileAuto);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PktCheckBox = new QCheckBox(gbNewFileAuto);
        PktCheckBox->setObjectName(QString::fromUtf8("PktCheckBox"));

        gridLayout->addWidget(PktCheckBox, 1, 0, 1, 1);

        PktSpinBox = new QSpinBox(gbNewFileAuto);
        PktSpinBox->setObjectName(QString::fromUtf8("PktSpinBox"));
        PktSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        PktSpinBox->setMaximum(2147483647);
        PktSpinBox->setValue(100000);

        gridLayout->addWidget(PktSpinBox, 1, 1, 1, 1);

        PktLabel = new QLabel(gbNewFileAuto);
        PktLabel->setObjectName(QString::fromUtf8("PktLabel"));

        gridLayout->addWidget(PktLabel, 1, 2, 1, 1);

        MBCheckBox = new QCheckBox(gbNewFileAuto);
        MBCheckBox->setObjectName(QString::fromUtf8("MBCheckBox"));

        gridLayout->addWidget(MBCheckBox, 2, 0, 1, 1);

        MBSpinBox = new QSpinBox(gbNewFileAuto);
        MBSpinBox->setObjectName(QString::fromUtf8("MBSpinBox"));
        MBSpinBox->setWrapping(true);
        MBSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        MBSpinBox->setValue(1);

        gridLayout->addWidget(MBSpinBox, 2, 1, 1, 1);

        MBComboBox = new QComboBox(gbNewFileAuto);
        MBComboBox->addItem(QString());
        MBComboBox->addItem(QString());
        MBComboBox->addItem(QString());
        MBComboBox->setObjectName(QString::fromUtf8("MBComboBox"));

        gridLayout->addWidget(MBComboBox, 2, 2, 1, 1);

        SecsCheckBox = new QCheckBox(gbNewFileAuto);
        SecsCheckBox->setObjectName(QString::fromUtf8("SecsCheckBox"));

        gridLayout->addWidget(SecsCheckBox, 3, 0, 1, 1);

        SecsSpinBox = new QSpinBox(gbNewFileAuto);
        SecsSpinBox->setObjectName(QString::fromUtf8("SecsSpinBox"));
        SecsSpinBox->setWrapping(true);
        SecsSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        SecsSpinBox->setMaximum(1000000);
        SecsSpinBox->setValue(1);

        gridLayout->addWidget(SecsSpinBox, 3, 1, 1, 1);

        SecsComboBox = new QComboBox(gbNewFileAuto);
        SecsComboBox->addItem(QString());
        SecsComboBox->addItem(QString());
        SecsComboBox->addItem(QString());
        SecsComboBox->setObjectName(QString::fromUtf8("SecsComboBox"));

        gridLayout->addWidget(SecsComboBox, 3, 2, 1, 1);

        IntervalSecsCheckBox = new QCheckBox(gbNewFileAuto);
        IntervalSecsCheckBox->setObjectName(QString::fromUtf8("IntervalSecsCheckBox"));

        gridLayout->addWidget(IntervalSecsCheckBox, 4, 0, 1, 1);

        IntervalSecsSpinBox = new QSpinBox(gbNewFileAuto);
        IntervalSecsSpinBox->setObjectName(QString::fromUtf8("IntervalSecsSpinBox"));
        IntervalSecsSpinBox->setWrapping(true);
        IntervalSecsSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        IntervalSecsSpinBox->setMaximum(1000000);
        IntervalSecsSpinBox->setValue(1);

        gridLayout->addWidget(IntervalSecsSpinBox, 4, 1, 1, 1);

        IntervalSecsComboBox = new QComboBox(gbNewFileAuto);
        IntervalSecsComboBox->addItem(QString());
        IntervalSecsComboBox->addItem(QString());
        IntervalSecsComboBox->addItem(QString());
        IntervalSecsComboBox->setObjectName(QString::fromUtf8("IntervalSecsComboBox"));

        gridLayout->addWidget(IntervalSecsComboBox, 4, 2, 1, 1);

        nameTemplateGB = new QGroupBox(gbNewFileAuto);
        nameTemplateGB->setObjectName(QString::fromUtf8("nameTemplateGB"));
        verticalLayout_5 = new QVBoxLayout(nameTemplateGB);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        rbTimeNum = new QRadioButton(nameTemplateGB);
        nameTimeNumBG = new QButtonGroup(CaptureOptionsDialog);
        nameTimeNumBG->setObjectName(QString::fromUtf8("nameTimeNumBG"));
        nameTimeNumBG->addButton(rbTimeNum);
        rbTimeNum->setObjectName(QString::fromUtf8("rbTimeNum"));

        verticalLayout_5->addWidget(rbTimeNum);

        rbNumTime = new QRadioButton(nameTemplateGB);
        nameTimeNumBG->addButton(rbNumTime);
        rbNumTime->setObjectName(QString::fromUtf8("rbNumTime"));

        verticalLayout_5->addWidget(rbNumTime);


        gridLayout->addWidget(nameTemplateGB, 5, 0, 1, 2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 3, 4, 1);


        verticalLayout_9->addWidget(gbNewFileAuto);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        RbCheckBox = new QCheckBox(outputTab);
        RbCheckBox->setObjectName(QString::fromUtf8("RbCheckBox"));

        horizontalLayout_4->addWidget(RbCheckBox);

        RbSpinBox = new QSpinBox(outputTab);
        RbSpinBox->setObjectName(QString::fromUtf8("RbSpinBox"));
        RbSpinBox->setWrapping(true);
        RbSpinBox->setMaximum(65535);
        RbSpinBox->setValue(2);

        horizontalLayout_4->addWidget(RbSpinBox);

        label_3 = new QLabel(outputTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout_9->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        tabWidget->addTab(outputTab, QString());
        gbNewFileAuto->raise();
        gbCaptureToFile->raise();
        optionsTab = new QWidget();
        optionsTab->setObjectName(QString::fromUtf8("optionsTab"));
        formLayout = new QFormLayout(optionsTab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        groupBox = new QGroupBox(optionsTab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbUpdatePacketsRT = new QCheckBox(groupBox);
        cbUpdatePacketsRT->setObjectName(QString::fromUtf8("cbUpdatePacketsRT"));

        verticalLayout->addWidget(cbUpdatePacketsRT);

        cbAutoScroll = new QCheckBox(groupBox);
        cbAutoScroll->setObjectName(QString::fromUtf8("cbAutoScroll"));

        verticalLayout->addWidget(cbAutoScroll);

        cbExtraCaptureInfo = new QCheckBox(groupBox);
        cbExtraCaptureInfo->setObjectName(QString::fromUtf8("cbExtraCaptureInfo"));

        verticalLayout->addWidget(cbExtraCaptureInfo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(optionsTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cbResolveMacAddresses = new QCheckBox(groupBox_2);
        cbResolveMacAddresses->setObjectName(QString::fromUtf8("cbResolveMacAddresses"));

        verticalLayout_3->addWidget(cbResolveMacAddresses);

        cbResolveNetworkNames = new QCheckBox(groupBox_2);
        cbResolveNetworkNames->setObjectName(QString::fromUtf8("cbResolveNetworkNames"));

        verticalLayout_3->addWidget(cbResolveNetworkNames);

        cbResolveTransportNames = new QCheckBox(groupBox_2);
        cbResolveTransportNames->setObjectName(QString::fromUtf8("cbResolveTransportNames"));

        verticalLayout_3->addWidget(cbResolveTransportNames);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);


        horizontalLayout_8->addWidget(groupBox_2);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_8);

        gbStopCaptureAuto = new QGroupBox(optionsTab);
        gbStopCaptureAuto->setObjectName(QString::fromUtf8("gbStopCaptureAuto"));
        gbStopCaptureAuto->setEnabled(true);
        gbStopCaptureAuto->setFlat(true);
        gridLayout_2 = new QGridLayout(gbStopCaptureAuto);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 4, 1);

        stopPktCheckBox = new QCheckBox(gbStopCaptureAuto);
        stopPktCheckBox->setObjectName(QString::fromUtf8("stopPktCheckBox"));

        gridLayout_2->addWidget(stopPktCheckBox, 0, 0, 1, 1);

        stopPktSpinBox = new QSpinBox(gbStopCaptureAuto);
        stopPktSpinBox->setObjectName(QString::fromUtf8("stopPktSpinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stopPktSpinBox->sizePolicy().hasHeightForWidth());
        stopPktSpinBox->setSizePolicy(sizePolicy2);
        stopPktSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        stopPktSpinBox->setMaximum(2147483647);
        stopPktSpinBox->setValue(1);

        gridLayout_2->addWidget(stopPktSpinBox, 0, 1, 1, 1);

        label_7 = new QLabel(gbStopCaptureAuto);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        stopFilesCheckBox = new QCheckBox(gbStopCaptureAuto);
        stopFilesCheckBox->setObjectName(QString::fromUtf8("stopFilesCheckBox"));

        gridLayout_2->addWidget(stopFilesCheckBox, 1, 0, 1, 1);

        stopFilesSpinBox = new QSpinBox(gbStopCaptureAuto);
        stopFilesSpinBox->setObjectName(QString::fromUtf8("stopFilesSpinBox"));
        sizePolicy2.setHeightForWidth(stopFilesSpinBox->sizePolicy().hasHeightForWidth());
        stopFilesSpinBox->setSizePolicy(sizePolicy2);
        stopFilesSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        stopFilesSpinBox->setMaximum(2147483647);
        stopFilesSpinBox->setValue(1);

        gridLayout_2->addWidget(stopFilesSpinBox, 1, 1, 1, 1);

        label_8 = new QLabel(gbStopCaptureAuto);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        stopMBCheckBox = new QCheckBox(gbStopCaptureAuto);
        stopMBCheckBox->setObjectName(QString::fromUtf8("stopMBCheckBox"));

        gridLayout_2->addWidget(stopMBCheckBox, 2, 0, 1, 1);

        stopMBSpinBox = new QSpinBox(gbStopCaptureAuto);
        stopMBSpinBox->setObjectName(QString::fromUtf8("stopMBSpinBox"));
        stopMBSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        stopMBSpinBox->setValue(1);

        gridLayout_2->addWidget(stopMBSpinBox, 2, 1, 1, 1);

        stopMBComboBox = new QComboBox(gbStopCaptureAuto);
        stopMBComboBox->addItem(QString());
        stopMBComboBox->addItem(QString());
        stopMBComboBox->addItem(QString());
        stopMBComboBox->setObjectName(QString::fromUtf8("stopMBComboBox"));

        gridLayout_2->addWidget(stopMBComboBox, 2, 2, 1, 1);

        stopSecsCheckBox = new QCheckBox(gbStopCaptureAuto);
        stopSecsCheckBox->setObjectName(QString::fromUtf8("stopSecsCheckBox"));

        gridLayout_2->addWidget(stopSecsCheckBox, 3, 0, 1, 1);

        stopSecsSpinBox = new QSpinBox(gbStopCaptureAuto);
        stopSecsSpinBox->setObjectName(QString::fromUtf8("stopSecsSpinBox"));
        stopSecsSpinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        stopSecsSpinBox->setMaximum(2147483647);
        stopSecsSpinBox->setValue(1);

        gridLayout_2->addWidget(stopSecsSpinBox, 3, 1, 1, 1);

        stopSecsComboBox = new QComboBox(gbStopCaptureAuto);
        stopSecsComboBox->addItem(QString());
        stopSecsComboBox->addItem(QString());
        stopSecsComboBox->addItem(QString());
        stopSecsComboBox->setObjectName(QString::fromUtf8("stopSecsComboBox"));

        gridLayout_2->addWidget(stopSecsComboBox, 3, 2, 1, 1);


        formLayout->setWidget(1, QFormLayout::LabelRole, gbStopCaptureAuto);

        gbTempDir = new QGroupBox(optionsTab);
        gbTempDir->setObjectName(QString::fromUtf8("gbTempDir"));
        gbTempDir->setEnabled(true);
        gbTempDir->setAutoFillBackground(false);
        gbTempDir->setFlat(true);
        gbTempDir->setCheckable(false);
        gridLayout_4 = new QGridLayout(gbTempDir);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tempDirLineEdit = new QLineEdit(gbTempDir);
        tempDirLineEdit->setObjectName(QString::fromUtf8("tempDirLineEdit"));

        gridLayout_4->addWidget(tempDirLineEdit, 0, 0, 1, 1);

        tempDirBrowseButton = new QPushButton(gbTempDir);
        tempDirBrowseButton->setObjectName(QString::fromUtf8("tempDirBrowseButton"));

        gridLayout_4->addWidget(tempDirBrowseButton, 0, 1, 1, 1);


        formLayout->setWidget(2, QFormLayout::LabelRole, gbTempDir);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_3);

        tabWidget->addTab(optionsTab, QString());

        verticalLayout_12->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(CaptureOptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout_12->addWidget(buttonBox);


        retranslateUi(CaptureOptionsDialog);

        tabWidget->setCurrentIndex(0);
        IntervalSecsComboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CaptureOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *CaptureOptionsDialog)
    {
        QTreeWidgetItem *___qtreewidgetitem = interfaceTree->headerItem();
        ___qtreewidgetitem->setText(8, QCoreApplication::translate("CaptureOptionsDialog", "Capture Filter", nullptr));
        ___qtreewidgetitem->setText(7, QCoreApplication::translate("CaptureOptionsDialog", "Monitor Mode", nullptr));
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("CaptureOptionsDialog", "Buffer (MB)", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("CaptureOptionsDialog", "Snaplen (B)", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("CaptureOptionsDialog", "Promiscuous", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("CaptureOptionsDialog", "Link-layer Header", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("CaptureOptionsDialog", "Traffic", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("CaptureOptionsDialog", "Interface", nullptr));
#if QT_CONFIG(tooltip)
        capturePromModeCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>You probably want to enable this. Usually a network card will only capture the traffic sent to its own network address. If you want to capture all traffic that the network card can &quot;see&quot;, mark this option. See the FAQ for some more details of capturing packets from a switched network.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        capturePromModeCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "Enable promiscuous mode on all interfaces", nullptr));
#if QT_CONFIG(tooltip)
        captureMonitorModeCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Usually a wireless network card will only capture the traffic sent to and from its own network address, and only captures <em>user data</em> traffic with &quot;fake&quot; Ethernet headers. If you want to capture all traffic that wireless network cards can &quot;see&quot;, or are interested in 802.11 management or control packets, or radio-layer information, mark this option. Monitor mode availability depends on the wireless card and driver. See the Wiki for some more details of capturing packets on WLAN networks.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        captureMonitorModeCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "Enable monitor mode on all 802.11 interfaces", nullptr));
#if QT_CONFIG(tooltip)
        manageButton->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Show and hide interfaces, add comments, and manage pipes and remote interfaces.", nullptr));
#endif // QT_CONFIG(tooltip)
        manageButton->setText(QCoreApplication::translate("CaptureOptionsDialog", "Manage Interfaces\342\200\246", nullptr));
        label_4->setText(QCoreApplication::translate("CaptureOptionsDialog", "Capture filter for selected interfaces:", nullptr));
        compileBPF->setText(QCoreApplication::translate("CaptureOptionsDialog", "Compile BPFs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(inputTab), QCoreApplication::translate("CaptureOptionsDialog", "Input", nullptr));
#if QT_CONFIG(tooltip)
        gbCaptureToFile->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Enter the file name to which captured data will be written. By default, a temporary file will be used.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbCaptureToFile->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Capture to a permanent file", nullptr));
        label_2->setText(QCoreApplication::translate("CaptureOptionsDialog", "File:", nullptr));
        browseButton->setText(QCoreApplication::translate("CaptureOptionsDialog", "Browse\342\200\246", nullptr));
        label->setText(QCoreApplication::translate("CaptureOptionsDialog", "Output format:", nullptr));
        rbPcapng->setText(QCoreApplication::translate("CaptureOptionsDialog", "pcapng", nullptr));
        rbPcap->setText(QCoreApplication::translate("CaptureOptionsDialog", "pcap", nullptr));
        labelCompression->setText(QCoreApplication::translate("CaptureOptionsDialog", "Compression:", nullptr));
        rbCompressionNone->setText(QCoreApplication::translate("CaptureOptionsDialog", "None", nullptr));
        rbCompressionGzip->setText(QCoreApplication::translate("CaptureOptionsDialog", "gzip", nullptr));
        rbCompressionLZ4->setText(QCoreApplication::translate("CaptureOptionsDialog", "LZ4", nullptr));
#if QT_CONFIG(tooltip)
        gbNewFileAuto->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Instead of using a single capture file, multiple files will be created.</p><p>The generated file names will contain an incrementing number and the start time of the capture.</p><p>NOTE: If enabled, at least one of the new-file criteria MUST be selected.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbNewFileAuto->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Create a new file automatically\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        PktCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file after the specified number of packets have been captured.", nullptr));
#endif // QT_CONFIG(tooltip)
        PktCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "after", nullptr));
#if QT_CONFIG(tooltip)
        PktSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file after the specified number of packets have been captured.", nullptr));
#endif // QT_CONFIG(tooltip)
        PktLabel->setText(QCoreApplication::translate("CaptureOptionsDialog", "packets", nullptr));
#if QT_CONFIG(tooltip)
        MBCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file after the file size exceeds the specified file size.", nullptr));
#endif // QT_CONFIG(tooltip)
        MBCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "after", nullptr));
#if QT_CONFIG(tooltip)
        MBSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file after the file size exceeds the specified file size.", nullptr));
#endif // QT_CONFIG(tooltip)
        MBComboBox->setItemText(0, QCoreApplication::translate("CaptureOptionsDialog", "kilobytes", nullptr));
        MBComboBox->setItemText(1, QCoreApplication::translate("CaptureOptionsDialog", "megabytes", nullptr));
        MBComboBox->setItemText(2, QCoreApplication::translate("CaptureOptionsDialog", "gigabytes", nullptr));

#if QT_CONFIG(tooltip)
        MBComboBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file after the file size exceeds the specified file size.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SecsCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the time capturing to the current file exceeds the specified time.", nullptr));
#endif // QT_CONFIG(tooltip)
        SecsCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "after", nullptr));
#if QT_CONFIG(tooltip)
        SecsSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the time capturing to the current file exceeds the specified time.", nullptr));
#endif // QT_CONFIG(tooltip)
        SecsComboBox->setItemText(0, QCoreApplication::translate("CaptureOptionsDialog", "seconds", nullptr));
        SecsComboBox->setItemText(1, QCoreApplication::translate("CaptureOptionsDialog", "minutes", nullptr));
        SecsComboBox->setItemText(2, QCoreApplication::translate("CaptureOptionsDialog", "hours", nullptr));

#if QT_CONFIG(tooltip)
        SecsComboBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the time capturing to the current file exceeds the specified time.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        IntervalSecsCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the (wall clock) time is an even multiple of the specified interval.\n"
"For example, use 1 hour to have a new file created every hour on the hour.", nullptr));
#endif // QT_CONFIG(tooltip)
        IntervalSecsCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "when time is a multiple of", nullptr));
#if QT_CONFIG(tooltip)
        IntervalSecsSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the (wall clock) time is an even multiple of the specified interval.\n"
"For example, use 1 hour to have a new file created every hour on the hour.", nullptr));
#endif // QT_CONFIG(tooltip)
        IntervalSecsComboBox->setItemText(0, QCoreApplication::translate("CaptureOptionsDialog", "seconds", nullptr));
        IntervalSecsComboBox->setItemText(1, QCoreApplication::translate("CaptureOptionsDialog", "minutes", nullptr));
        IntervalSecsComboBox->setItemText(2, QCoreApplication::translate("CaptureOptionsDialog", "hours", nullptr));

#if QT_CONFIG(tooltip)
        IntervalSecsComboBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Switch to the next file when the (wall clock) time is an even multiple of the specified interval.\n"
"For example, use 1 hour to have a new file created every hour on the hour.", nullptr));
#endif // QT_CONFIG(tooltip)
        nameTemplateGB->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "File infix pattern", nullptr));
#if QT_CONFIG(tooltip)
        nameTemplateGB->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>In multiple file mode, the date and time and file index number are inserted between filename template and any suffix. Select their order.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbTimeNum->setText(QCoreApplication::translate("CaptureOptionsDialog", "YYYYmmDDHHMMSS_NNNNN", nullptr));
#if QT_CONFIG(tooltip)
        rbTimeNum->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Date and time before the file index number. This causes files to sort in creation time order, and keeps files from the same batch closely ordered.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbNumTime->setText(QCoreApplication::translate("CaptureOptionsDialog", "NNNNN_YYYYmmDDHHMMSS", nullptr));
#if QT_CONFIG(tooltip)
        rbNumTime->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>File index number before the date and time. This is the historic Wireshark ordering.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RbCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>After capturing has switched to the next file and the given number of files has exceeded, the oldest file will be removed.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RbCheckBox->setText(QCoreApplication::translate("CaptureOptionsDialog", "Use a ring buffer with ", nullptr));
        label_3->setText(QCoreApplication::translate("CaptureOptionsDialog", "files", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(outputTab), QCoreApplication::translate("CaptureOptionsDialog", "Output", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Display Options", nullptr));
#if QT_CONFIG(tooltip)
        cbUpdatePacketsRT->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Using this option will show the captured packets immediately on the main screen. Please note: this will slow down capturing, so increased packet drops might appear.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUpdatePacketsRT->setText(QCoreApplication::translate("CaptureOptionsDialog", "Update list of packets in real-time", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoScroll->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>This will scroll the &quot;Packet List&quot; automatically to the latest captured packet, when the &quot;Update list of packets in real-time&quot; option is used.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAutoScroll->setText(QCoreApplication::translate("CaptureOptionsDialog", "Automatically scroll during live capture", nullptr));
#if QT_CONFIG(tooltip)
        cbExtraCaptureInfo->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Show the capture info dialog while capturing.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbExtraCaptureInfo->setText(QCoreApplication::translate("CaptureOptionsDialog", "Show capture information during live capture", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Name Resolution", nullptr));
#if QT_CONFIG(tooltip)
        cbResolveMacAddresses->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Perform MAC layer name resolution while capturing.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbResolveMacAddresses->setText(QCoreApplication::translate("CaptureOptionsDialog", "Resolve MAC addresses", nullptr));
#if QT_CONFIG(tooltip)
        cbResolveNetworkNames->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Perform network layer name resolution while capturing.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbResolveNetworkNames->setText(QCoreApplication::translate("CaptureOptionsDialog", "Resolve network names", nullptr));
#if QT_CONFIG(tooltip)
        cbResolveTransportNames->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Perform transport layer name resolution while capturing.", nullptr));
#endif // QT_CONFIG(tooltip)
        cbResolveTransportNames->setText(QCoreApplication::translate("CaptureOptionsDialog", "Resolve transport names", nullptr));
        gbStopCaptureAuto->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Stop capture automatically after\342\200\246", nullptr));
#if QT_CONFIG(tooltip)
        stopPktCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Stop capturing after the specified number of packets have been captured.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        stopPktCheckBox->setText(QString());
#if QT_CONFIG(tooltip)
        stopPktSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified number of packets have been captured.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("CaptureOptionsDialog", "packets", nullptr));
#if QT_CONFIG(tooltip)
        stopFilesCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Stop capturing after the specified number of files have been created.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        stopFilesCheckBox->setText(QString());
#if QT_CONFIG(tooltip)
        stopFilesSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified number of files have been created.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("CaptureOptionsDialog", "files", nullptr));
#if QT_CONFIG(tooltip)
        stopMBCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Stop capturing after the specified amount of data has been captured.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        stopMBCheckBox->setText(QString());
#if QT_CONFIG(tooltip)
        stopMBSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified amount of data has been captured.", nullptr));
#endif // QT_CONFIG(tooltip)
        stopMBComboBox->setItemText(0, QCoreApplication::translate("CaptureOptionsDialog", "kilobytes", nullptr));
        stopMBComboBox->setItemText(1, QCoreApplication::translate("CaptureOptionsDialog", "megabytes", nullptr));
        stopMBComboBox->setItemText(2, QCoreApplication::translate("CaptureOptionsDialog", "gigabytes", nullptr));

#if QT_CONFIG(tooltip)
        stopMBComboBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified amount of data has been captured.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        stopSecsCheckBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified amount of time has passed.", nullptr));
#endif // QT_CONFIG(tooltip)
        stopSecsCheckBox->setText(QString());
#if QT_CONFIG(tooltip)
        stopSecsSpinBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified amount of time has passed.", nullptr));
#endif // QT_CONFIG(tooltip)
        stopSecsComboBox->setItemText(0, QCoreApplication::translate("CaptureOptionsDialog", "seconds", nullptr));
        stopSecsComboBox->setItemText(1, QCoreApplication::translate("CaptureOptionsDialog", "minutes", nullptr));
        stopSecsComboBox->setItemText(2, QCoreApplication::translate("CaptureOptionsDialog", "hours", nullptr));

#if QT_CONFIG(tooltip)
        stopSecsComboBox->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "Stop capturing after the specified amount of time has passed.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        gbTempDir->setToolTip(QCoreApplication::translate("CaptureOptionsDialog", "<html><head/><body><p>Optionally specify a temporary directory for unnamed capture files.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbTempDir->setTitle(QCoreApplication::translate("CaptureOptionsDialog", "Directory for temporary files", nullptr));
        tempDirBrowseButton->setText(QCoreApplication::translate("CaptureOptionsDialog", "Browse\342\200\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(optionsTab), QCoreApplication::translate("CaptureOptionsDialog", "Options", nullptr));
        (void)CaptureOptionsDialog;
    } // retranslateUi

};

namespace Ui {
    class CaptureOptionsDialog: public Ui_CaptureOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_OPTIONS_DIALOG_H
