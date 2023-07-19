# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'design.ui'
##
## Created by: Qt User Interface Compiler version 6.2.3
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QGridLayout, QLabel, QLayout,
    QLineEdit, QMainWindow, QMenu, QMenuBar,
    QPlainTextEdit, QPushButton, QSizePolicy, QStatusBar,
    QTabWidget, QTextEdit, QVBoxLayout, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(1598, 1102)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.verticalLayout = QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.tabWidget = QTabWidget(self.centralwidget)
        self.tabWidget.setObjectName(u"tabWidget")
        self.tabInput = QWidget()
        self.tabInput.setObjectName(u"tabInput")
        self.tabWidgetInput = QTabWidget(self.tabInput)
        self.tabWidgetInput.setObjectName(u"tabWidgetInput")
        self.tabWidgetInput.setGeometry(QRect(10, 380, 1421, 541))
        self.tabTokamakData = QWidget()
        self.tabTokamakData.setObjectName(u"tabTokamakData")
        self.tabWidgetInput.addTab(self.tabTokamakData, "")
        self.tabGeneralData = QWidget()
        self.tabGeneralData.setObjectName(u"tabGeneralData")
        self.tabWidgetInput.addTab(self.tabGeneralData, "")
        self.tabDINAData = QWidget()
        self.tabDINAData.setObjectName(u"tabDINAData")
        self.tabWidgetInput.addTab(self.tabDINAData, "")
        self.tabControlData = QWidget()
        self.tabControlData.setObjectName(u"tabControlData")
        self.tabWidgetInput.addTab(self.tabControlData, "")
        self.tabExternalData = QWidget()
        self.tabExternalData.setObjectName(u"tabExternalData")
        self.tabWidgetInput.addTab(self.tabExternalData, "")
        self.gridLayoutWidget_3 = QWidget(self.tabInput)
        self.gridLayoutWidget_3.setObjectName(u"gridLayoutWidget_3")
        self.gridLayoutWidget_3.setGeometry(QRect(0, 0, 591, 291))
        self.layoutInputSetup = QGridLayout(self.gridLayoutWidget_3)
        self.layoutInputSetup.setObjectName(u"layoutInputSetup")
        self.layoutInputSetup.setContentsMargins(0, 0, 0, 0)
        self.label_2 = QLabel(self.gridLayoutWidget_3)
        self.label_2.setObjectName(u"label_2")

        self.layoutInputSetup.addWidget(self.label_2, 9, 1, 1, 1)

        self.gridLayout = QGridLayout()
        self.gridLayout.setObjectName(u"gridLayout")
        self.lineInputRun = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputRun.setObjectName(u"lineInputRun")

        self.gridLayout.addWidget(self.lineInputRun, 2, 2, 1, 1)

        self.lineInputPulse = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputPulse.setObjectName(u"lineInputPulse")

        self.gridLayout.addWidget(self.lineInputPulse, 1, 2, 1, 1)

        self.lineInputTokamak = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputTokamak.setObjectName(u"lineInputTokamak")

        self.gridLayout.addWidget(self.lineInputTokamak, 0, 2, 1, 1)

        self.labelInputRun = QLabel(self.gridLayoutWidget_3)
        self.labelInputRun.setObjectName(u"labelInputRun")

        self.gridLayout.addWidget(self.labelInputRun, 2, 0, 1, 1)

        self.labelInputTokamak = QLabel(self.gridLayoutWidget_3)
        self.labelInputTokamak.setObjectName(u"labelInputTokamak")

        self.gridLayout.addWidget(self.labelInputTokamak, 0, 0, 1, 1)

        self.labelInputPulse = QLabel(self.gridLayoutWidget_3)
        self.labelInputPulse.setObjectName(u"labelInputPulse")

        self.gridLayout.addWidget(self.labelInputPulse, 1, 0, 1, 1)


        self.layoutInputSetup.addLayout(self.gridLayout, 10, 1, 1, 1)

        self.btnLoad2 = QPushButton(self.gridLayoutWidget_3)
        self.btnLoad2.setObjectName(u"btnLoad2")

        self.layoutInputSetup.addWidget(self.btnLoad2, 8, 0, 1, 1)

        self.btnSave2 = QPushButton(self.gridLayoutWidget_3)
        self.btnSave2.setObjectName(u"btnSave2")

        self.layoutInputSetup.addWidget(self.btnSave2, 4, 1, 1, 1)

        self.label = QLabel(self.gridLayoutWidget_3)
        self.label.setObjectName(u"label")

        self.layoutInputSetup.addWidget(self.label, 5, 1, 1, 1)

        self.btnSave = QPushButton(self.gridLayoutWidget_3)
        self.btnSave.setObjectName(u"btnSave")

        self.layoutInputSetup.addWidget(self.btnSave, 8, 1, 1, 1)

        self.btnLoad = QPushButton(self.gridLayoutWidget_3)
        self.btnLoad.setObjectName(u"btnLoad")

        self.layoutInputSetup.addWidget(self.btnLoad, 4, 0, 1, 1)

        self.labelDirSave = QLabel(self.gridLayoutWidget_3)
        self.labelDirSave.setObjectName(u"labelDirSave")

        self.layoutInputSetup.addWidget(self.labelDirSave, 7, 1, 1, 1)

        self.gridLayout_4 = QGridLayout()
        self.gridLayout_4.setObjectName(u"gridLayout_4")
        self.lineInputRun_2 = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputRun_2.setObjectName(u"lineInputRun_2")

        self.gridLayout_4.addWidget(self.lineInputRun_2, 2, 2, 1, 1)

        self.lineInputPulse_2 = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputPulse_2.setObjectName(u"lineInputPulse_2")

        self.gridLayout_4.addWidget(self.lineInputPulse_2, 1, 2, 1, 1)

        self.lineInputTokamak_2 = QLineEdit(self.gridLayoutWidget_3)
        self.lineInputTokamak_2.setObjectName(u"lineInputTokamak_2")

        self.gridLayout_4.addWidget(self.lineInputTokamak_2, 0, 2, 1, 1)

        self.labelInputRun_2 = QLabel(self.gridLayoutWidget_3)
        self.labelInputRun_2.setObjectName(u"labelInputRun_2")

        self.gridLayout_4.addWidget(self.labelInputRun_2, 2, 0, 1, 1)

        self.labelInputTokamak_2 = QLabel(self.gridLayoutWidget_3)
        self.labelInputTokamak_2.setObjectName(u"labelInputTokamak_2")

        self.gridLayout_4.addWidget(self.labelInputTokamak_2, 0, 0, 1, 1)

        self.labelInputPulse_2 = QLabel(self.gridLayoutWidget_3)
        self.labelInputPulse_2.setObjectName(u"labelInputPulse_2")

        self.gridLayout_4.addWidget(self.labelInputPulse_2, 1, 0, 1, 1)


        self.layoutInputSetup.addLayout(self.gridLayout_4, 10, 0, 1, 1)

        self.labelDirLoad = QLabel(self.gridLayoutWidget_3)
        self.labelDirLoad.setObjectName(u"labelDirLoad")

        self.layoutInputSetup.addWidget(self.labelDirLoad, 3, 1, 1, 1)

        self.tabWidget.addTab(self.tabInput, "")
        self.tabOutput = QWidget()
        self.tabOutput.setObjectName(u"tabOutput")
        self.gridLayoutWidget_2 = QWidget(self.tabOutput)
        self.gridLayoutWidget_2.setObjectName(u"gridLayoutWidget_2")
        self.gridLayoutWidget_2.setGeometry(QRect(40, 30, 401, 271))
        self.gridLayout_2 = QGridLayout(self.gridLayoutWidget_2)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout_2.setSizeConstraint(QLayout.SetMinAndMaxSize)
        self.gridLayout_2.setHorizontalSpacing(6)
        self.gridLayout_2.setContentsMargins(0, 0, 0, 0)
        self.textUser = QPlainTextEdit(self.gridLayoutWidget_2)
        self.textUser.setObjectName(u"textUser")
        sizePolicy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.textUser.sizePolicy().hasHeightForWidth())
        self.textUser.setSizePolicy(sizePolicy)
        self.textUser.setMaximumSize(QSize(250, 50))

        self.gridLayout_2.addWidget(self.textUser, 3, 1, 1, 1)

        self.labelRun = QLabel(self.gridLayoutWidget_2)
        self.labelRun.setObjectName(u"labelRun")
        self.labelRun.setMaximumSize(QSize(100, 50))

        self.gridLayout_2.addWidget(self.labelRun, 1, 0, 1, 1)

        self.labelPulse = QLabel(self.gridLayoutWidget_2)
        self.labelPulse.setObjectName(u"labelPulse")
        self.labelPulse.setMaximumSize(QSize(100, 50))

        self.gridLayout_2.addWidget(self.labelPulse, 0, 0, 1, 1)

        self.textPulse = QTextEdit(self.gridLayoutWidget_2)
        self.textPulse.setObjectName(u"textPulse")
        self.textPulse.setMaximumSize(QSize(250, 50))

        self.gridLayout_2.addWidget(self.textPulse, 0, 1, 1, 1)

        self.textRun = QPlainTextEdit(self.gridLayoutWidget_2)
        self.textRun.setObjectName(u"textRun")
        self.textRun.setMaximumSize(QSize(250, 50))

        self.gridLayout_2.addWidget(self.textRun, 1, 1, 1, 1)

        self.textBase = QPlainTextEdit(self.gridLayoutWidget_2)
        self.textBase.setObjectName(u"textBase")
        self.textBase.setMaximumSize(QSize(250, 50))

        self.gridLayout_2.addWidget(self.textBase, 2, 1, 1, 1)

        self.labelBase = QLabel(self.gridLayoutWidget_2)
        self.labelBase.setObjectName(u"labelBase")
        self.labelBase.setMaximumSize(QSize(100, 50))

        self.gridLayout_2.addWidget(self.labelBase, 2, 0, 1, 1)

        self.labelUser = QLabel(self.gridLayoutWidget_2)
        self.labelUser.setObjectName(u"labelUser")
        self.labelUser.setMaximumSize(QSize(100, 50))

        self.gridLayout_2.addWidget(self.labelUser, 3, 0, 1, 1)

        self.btnLoadIDS = QPushButton(self.gridLayoutWidget_2)
        self.btnLoadIDS.setObjectName(u"btnLoadIDS")
        self.btnLoadIDS.setMaximumSize(QSize(250, 16777215))

        self.gridLayout_2.addWidget(self.btnLoadIDS, 4, 1, 1, 1)

        self.labelIDSInfo = QLabel(self.gridLayoutWidget_2)
        self.labelIDSInfo.setObjectName(u"labelIDSInfo")
        self.labelIDSInfo.setMaximumSize(QSize(100, 50))

        self.gridLayout_2.addWidget(self.labelIDSInfo, 4, 0, 1, 1)

        self.tabWidget.addTab(self.tabOutput, "")

        self.verticalLayout.addWidget(self.tabWidget)

        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.menuBar = QMenuBar(MainWindow)
        self.menuBar.setObjectName(u"menuBar")
        self.menuBar.setGeometry(QRect(0, 0, 1598, 19))
        self.menuDINA = QMenu(self.menuBar)
        self.menuDINA.setObjectName(u"menuDINA")
        MainWindow.setMenuBar(self.menuBar)

        self.menuBar.addAction(self.menuDINA.menuAction())

        self.retranslateUi(MainWindow)

        self.tabWidget.setCurrentIndex(0)
        self.tabWidgetInput.setCurrentIndex(2)


        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"DINA", None))
        self.tabWidgetInput.setTabText(self.tabWidgetInput.indexOf(self.tabTokamakData), QCoreApplication.translate("MainWindow", u"Tokamak Data", None))
        self.tabWidgetInput.setTabText(self.tabWidgetInput.indexOf(self.tabGeneralData), QCoreApplication.translate("MainWindow", u"General Data", None))
        self.tabWidgetInput.setTabText(self.tabWidgetInput.indexOf(self.tabDINAData), QCoreApplication.translate("MainWindow", u"DINA Data", None))
        self.tabWidgetInput.setTabText(self.tabWidgetInput.indexOf(self.tabControlData), QCoreApplication.translate("MainWindow", u"Controller Data", None))
        self.tabWidgetInput.setTabText(self.tabWidgetInput.indexOf(self.tabExternalData), QCoreApplication.translate("MainWindow", u"External Data", None))
        self.label_2.setText("")
        self.labelInputRun.setText(QCoreApplication.translate("MainWindow", u"Run", None))
        self.labelInputTokamak.setText(QCoreApplication.translate("MainWindow", u"Database", None))
        self.labelInputPulse.setText(QCoreApplication.translate("MainWindow", u"Pulse", None))
        self.btnLoad2.setText(QCoreApplication.translate("MainWindow", u"Load from work directory", None))
        self.btnSave2.setText(QCoreApplication.translate("MainWindow", u"Save *.dat files", None))
        self.label.setText("")
        self.btnSave.setText(QCoreApplication.translate("MainWindow", u"Save to work directory", None))
        self.btnLoad.setText(QCoreApplication.translate("MainWindow", u"Load *.dat files", None))
        self.labelDirSave.setText(QCoreApplication.translate("MainWindow", u"Select DINA work directory", None))
        self.labelInputRun_2.setText(QCoreApplication.translate("MainWindow", u"Run", None))
        self.labelInputTokamak_2.setText(QCoreApplication.translate("MainWindow", u"Database", None))
        self.labelInputPulse_2.setText(QCoreApplication.translate("MainWindow", u"Pulse", None))
        self.labelDirLoad.setText(QCoreApplication.translate("MainWindow", u"Select setups source folder", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabInput), QCoreApplication.translate("MainWindow", u"Input", None))
        self.labelRun.setText(QCoreApplication.translate("MainWindow", u"Run", None))
        self.labelPulse.setText(QCoreApplication.translate("MainWindow", u"Pulse", None))
        self.labelBase.setText(QCoreApplication.translate("MainWindow", u"Database", None))
        self.labelUser.setText(QCoreApplication.translate("MainWindow", u"User", None))
        self.btnLoadIDS.setText(QCoreApplication.translate("MainWindow", u"Load IDS", None))
        self.labelIDSInfo.setText("")
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabOutput), QCoreApplication.translate("MainWindow", u"Output", None))
        self.menuDINA.setTitle(QCoreApplication.translate("MainWindow", u"DINA", None))
    # retranslateUi

