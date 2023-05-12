
import sys
import os
import shutil

from PyQt5 import QtWidgets, QtGui
import design
import captions

import math
import numpy
import random
import matplotlib
matplotlib.use('Qt5Agg')


import tarfile
import datetime


from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar

from matplotlib.figure import Figure
import matplotlib.pyplot as plt

import imas
import xml.etree.ElementTree as ET
from xml.dom import minidom


from plequi import Second_window
#import eq_win2
#from equil_script_2 import Second_window
#from MyCanvaseq import MyCanvas
#------------------------NEW IMPORT
#from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar
from functools import partial
#from matplotlib.figure import Figure
from pathlib import Path
from PyQt5 import QtGui
from PyQt5 import QtCore
from PyQt5.QtWidgets import (QTabWidget, QWidget, QSlider, QFormLayout, QApplication,
                             QMenu, QMainWindow, QDockWidget,QMenuBar,QSizePolicy,
                             QLineEdit, QPushButton, QVBoxLayout, QComboBox,
                             QPlainTextEdit, QGridLayout, QMdiArea, QMdiSubWindow, QTableView, QAction) 
from PyQt5.QtWidgets import QApplication, QMainWindow, QTreeWidget, QTreeWidgetItem, \
                            QWidget, QGridLayout, QVBoxLayout, QLineEdit, \
                            QSlider, QPushButton, QHBoxLayout, QLabel, QMessageBox


import viz_plug




sys.path.append((os.environ['VIZ_HOME']))

from imasviz.VizUtils import (QVizGlobalValues, QVizPreferences,
                              QVizGlobalOperations, QVizLogger)


#--------------------------END NEW IMPORT


class CodeParameter():
  def __init__(self, mytype=float, value=0, unit="", widget=None, comment="", rawname="", name=""):
    self.unit = unit
    self.value = value
    self.mytype = mytype
    self.comment = comment
    self.rawname = rawname
    self.name = name
    self.size = 1
    if widget == None:
      self.widget = QtWidgets.QTableWidgetItem(str(value))
    else:
      self.widget = widget
    
  def SetValue(self, value):
    self.widget.setText(str(value))
    
  def GetValue(self, value):
    if mytype == int:
      return int(self.widget.text())
    if mytype == float:
      return float(self.widget.text())


class Waveform():
  def __init__(self, data, unit):
    self.data = data
    self.unit = unit
    self.name = name
    
class TimeSerie():
  def __init__(self, time=[]):
    self.time = time
    self.data = []


class Graph():
  def __init__(self, parent, toolbar = 1):
    toolbar = 1
    self.figure = plt.figure()
    self.canvas = FigureCanvas(self.figure)
    self.layout = QtWidgets.QVBoxLayout()
    if toolbar == 1:
      # this is the Navigation widget
      # it takes the Canvas widget and a parent
      self.toolbar = NavigationToolbar(self.canvas, parent) 
      self.layout.addWidget(self.toolbar)
    self.layout.addWidget(self.canvas) 
    
  def Plot(self, x, y, name = ''):
    self.figure.clear()
    ax = self.figure.add_subplot(111)
    ax.plot(x, y, '-')
    ax.set_xlabel('time, s')
    ax.set_ylabel(name)
    self.canvas.draw()
#-----------NEW CLASSes

class QVizMDI(QMdiArea):
    """Class for Multiple Document Interface (MDI) area.
    """

    def __init__(self, parent):
        super().__init__(parent)
        self.setWindowTitle("MDI")
        self.setObjectName("MDI")

class ExampleApp(QMainWindow, design.Ui_MainWindow):
    def __init__(self):
        super(ExampleApp, self).__init__()
        #self.MDI = QVizMDI(self)
        #self.GUIVIZ = GUIFrame(self)
        self.setObjectName("IMASViz root window")
        self.MDI = QVizMDI(self)
        self.startWindow = viz_plug.QVizStartWindow(self)
        #self.viz_plug.QVizStartWindow.setStatusBar()
        #self.GUIVIZ = viz_plug.QVizMainWindow(self)
        self.EQUIL_win = None
        #self.setupUi(self)  # Initialise design
        #self.initUi()      MAYBE DELETE
        #screen_resolution = app.desktop().screenGeometry()
        #width, height = screen_resolution.width(), screen_resolution.height()
        #print("width = " + str(width), "height = " + str(height))
        self.setupUi()  # Initialise design
        #self.resize(width*1.0, height*1.0)
        self.showMaximized()
        #-------------------------------------------------testing--------------------------------


    def initTableOfParameters(self, table, headers):
        nCol = len(headers)
        table.setRowCount(nCol)
        table.setVerticalHeaderLabels(headers)
        for i in range(nCol):
            table.verticalHeaderItem(i).setToolTip(captions.tooltip[headers[i]])
        
        
    def setupUi(self):
        super().setupUi(self)
        
        self.setWindowTitle('DINA GUI')
        self.setObjectName("DINA-VIZ GUI")
                
        
        self.directoryLoad = os.path.normpath(os.getcwd() + '/../../machines/iter/')
        self.directorySave = os.path.normpath(os.getcwd() + '/../../imas/python_wf/')
        self.labelDirLoad.setText(self.directoryLoad)
        self.labelDirSave.setText(self.directorySave)
        
        self.btnLoad.clicked.connect(self.LoadSetups)
        self.btnSave.clicked.connect(self.SaveSetups)
        
        
        
        self.TokamakData = {}
        self.controlData = {}
        self.DINAData = {}
        self.generalData = []
        self.externalData = []
        
        
        
        
        
        self.tabExternalDataChild = QtWidgets.QTabWidget(self.tabExternalData)
        self.tabExternalDataChild.setObjectName("tabExternalDataChild") 
        verticalLayout = QtWidgets.QVBoxLayout(self.tabExternalData)
        verticalLayout.setObjectName("tabExternalDataLayout")       
        verticalLayout.addWidget(self.tabExternalDataChild)
        
        
        self.tabControlDataChild = QtWidgets.QTabWidget(self.tabControlData)
        self.tabControlDataChild.setObjectName("tabControlDataChild")      
        verticalLayout = QtWidgets.QVBoxLayout(self.tabControlData)
        verticalLayout.setObjectName("tabControlDataLayout")       
        verticalLayout.addWidget(self.tabControlDataChild)
        
        
        self.tabGeneralDataChild = QtWidgets.QTabWidget(self.tabGeneralData)
        self.tabGeneralDataChild.setObjectName("tabGeneralDataChild")     
        verticalLayout = QtWidgets.QVBoxLayout(self.tabGeneralData)
        verticalLayout.setObjectName("tabGeneralDataLayout")       
        verticalLayout.addWidget(self.tabGeneralDataChild)      
        
        
        self.tabDINADataChild = QtWidgets.QTabWidget(self.tabDINAData)
        self.tabDINADataChild.setObjectName("tabDINADataChild") 
        verticalLayout = QtWidgets.QVBoxLayout(self.tabDINAData)
        verticalLayout.setObjectName("tabDINADataLayout")       
        verticalLayout.addWidget(self.tabDINADataChild)        
        
    
        self.tabTokamakDataChild = QtWidgets.QTabWidget(self.tabTokamakData)
        self.tabTokamakDataChild.setObjectName("tabTokamakDataChild") 
        verticalLayout = QtWidgets.QVBoxLayout(self.tabTokamakData)
        verticalLayout.setObjectName("tabTokamakDataLayout")       
        verticalLayout.addWidget(self.tabTokamakDataChild) 


        self.CSHeaders = ['CSU3','CSU2','CS1','CSL2','CSL3']
        self.PFHeaders = ['PF1','PF2','PF3','PF4','PF5','PF6']
        self.coilNames = self.CSHeaders + self.PFHeaders
         
      
        #user = os.environ['USER']
        user = os.getenv('USER')
        #workdir = os.environ['KEPLER_DIR']
        print('user is ', user)
        #print('workdir is ', workdir)
         
        self.lineInputPulse.setText('170')
        self.lineInputRun.setText('1')
        self.lineInputTokamak.setText('test')         
      
        #self.tableCurrents.itemClicked.connect(self.TableClicked)
        #self.tableCurrents.itemSelectionChanged.connect(self.tableCurrentsSelectionChanged)                
        #self.dataCurrentsHeaders = ['Time, s', 'Iplasma, MA']
        #for i in range(len(self.coilNames)):
          #self.dataCurrentsHeaders = self.dataCurrentsHeaders + [self.coilNames[i] + ', MA*t']
        ##print(self.dataCurrentsHeaders)  
        #self.tableCurrents.setHorizontalHeaderLabels(self.dataCurrentsHeaders)         
        
        
        #self.tableVoltages.itemSelectionChanged.connect(self.tableVoltagesSelectionChanged)                       
        #self.dataVoltagesHeaders = ['Time, s']
        #for i in range(len(self.coilNames)):
          #self.dataVoltagesHeaders = self.dataVoltagesHeaders + [self.coilNames[i] + ', V']
        #self.tableVoltages.setHorizontalHeaderLabels(self.dataVoltagesHeaders)
        
        
        #gridGaps = QtWidgets.QGridLayout()
        
        #self.tableGap1.setHorizontalHeaderLabels(['Time, s', 'g1']) 
        #gridGaps.addWidget(self.tableGap1, 0, 0)
        #self.tableGap1.itemSelectionChanged.connect(self.tableGap1SelectionChanged) 

        #self.tableGap2.setHorizontalHeaderLabels(['Time, s', 'g2']) 
        #gridGaps.addWidget(self.tableGap2, 0, 1)
        #self.tableGap2.itemSelectionChanged.connect(self.tableGap2SelectionChanged)

        #self.tableGap3.setHorizontalHeaderLabels(['Time, s', 'g3']) 
        #gridGaps.addWidget(self.tableGap3, 0, 2)
        #self.tableGap3.itemSelectionChanged.connect(self.tableGap3SelectionChanged)        
        
        #self.tableGap4.setHorizontalHeaderLabels(['Time, s', 'g4']) 
        #gridGaps.addWidget(self.tableGap4, 0, 3)
        #self.tableGap4.itemSelectionChanged.connect(self.tableGap4SelectionChanged) 

        #self.tableGap5.setHorizontalHeaderLabels(['Time, s', 'g5']) 
        #gridGaps.addWidget(self.tableGap5, 0, 4)
        #self.tableGap5.itemSelectionChanged.connect(self.tableGap5SelectionChanged)

        #self.tableGap6.setHorizontalHeaderLabels(['Time, s', 'g6'])  
        #gridGaps.addWidget(self.tableGap6, 0, 5)
        #self.tableGap6.itemSelectionChanged.connect(self.tableGap6SelectionChanged)        
        
        #self.tableGap1_term.setHorizontalHeaderLabels(['Time, s', 'g1_term'])  
        #gridGaps.addWidget(self.tableGap1_term, 1, 0)
        #self.tableGap1_term.itemSelectionChanged.connect(self.tableGap1_termSelectionChanged) 

        #self.tableGap2_term.setHorizontalHeaderLabels(['Time, s', 'g2_term']) 
        #gridGaps.addWidget(self.tableGap2_term, 1, 1)
        #self.tableGap2_term.itemSelectionChanged.connect(self.tableGap2_termSelectionChanged)

        #self.tableGap3_term.setHorizontalHeaderLabels(['Time, s', 'g3_term'])  
        #gridGaps.addWidget(self.tableGap3_term, 1, 2)
        #self.tableGap3_term.itemSelectionChanged.connect(self.tableGap3_termSelectionChanged)        
        
        #self.tableGap4_term.setHorizontalHeaderLabels(['Time, s', 'g4_term']) 
        #gridGaps.addWidget(self.tableGap4_term, 1, 3)
        #self.tableGap4_term.itemSelectionChanged.connect(self.tableGap4_termSelectionChanged) 

        #self.tableGap5_term.setHorizontalHeaderLabels(['Time, s', 'g5_term']) 
        #gridGaps.addWidget(self.tableGap5_term, 1, 4)
        #self.tableGap5_term.itemSelectionChanged.connect(self.tableGap5_termSelectionChanged)

        #self.tableGap6_term.setHorizontalHeaderLabels(['Time, s', 'g6_term']) 
        #gridGaps.addWidget(self.tableGap6_term, 1, 5)
        #self.tableGap6_term.itemSelectionChanged.connect(self.tableGap6_termSelectionChanged)        
        
        #self.tableElong.setHorizontalHeaderLabels(['Time, s', 'Elongation'])  
        #gridGaps.addWidget(self.tableElong, 0, 6)
        #self.tableElong.itemSelectionChanged.connect(self.tableElongSelectionChanged)        
        
        #self.tabGaps.setLayout(gridGaps)
        
        
        #layoutContr = QtWidgets.QHBoxLayout()
        
        
        #self.tableControlMarg.setHorizontalHeaderLabels(['Max Voltage, V', 'Max current, kA']) 
        #self.tableControlMarg.setVerticalHeaderLabels(['VVS1', 'VVS3'] + self.coilNames) 
        #layoutContr.addWidget(self.tableControlMarg)
                
        #self.initTableOfParameters(self.tableControl1, ['Time_cont2', 'Ip_div', 'Time_ref_ramp', 'Ip_rd', 'Time_rd_ref', 'Time_V'])
        #layoutContr.addWidget(self.tableControl1)
                            
        #self.initTableOfParameters(self.tableControl2, ['c_a_tpl1', 'c_a_tpl1_EOB', 'c_a_tpl2', 'c_a_tpl_min', 'y0', 'c1_y0', 'c2_y0'])       
        #layoutContr.addWidget(self.tableControl2)
        
        #self.tabControlData.setLayout(layoutContr)
        
        
        
        
        
        
        
        
        # Output tab 
        self.btnLoadIDS.clicked.connect(self.PlotOutput)
        
        self.textPulse.setPlainText('170')
        self.textRun.setPlainText('6')
        self.textUser.setPlainText(user)
        self.textBase.setPlainText('test')

             
       
        self.outpGraph = []
        
        grid = QtWidgets.QGridLayout()
        grid.addWidget(self.gridLayoutWidget_2, 0, 0) 

        grid.addLayout(self.AddCanvas(0), 0, 1)    
        grid.addLayout(self.AddCanvas(1), 0, 2)
        grid.addLayout(self.AddCanvas(2), 1, 0)
        grid.addLayout(self.AddCanvas(3), 1, 1)    
        grid.addLayout(self.AddCanvas(4), 1, 2)        
        
        self.tabOutput.setLayout(grid)
        
        
        self.timeTraceGraph = Graph(self)
        
        layGr = QtWidgets.QGridLayout()       
        layGr.addWidget(self.gridLayoutWidget_3, 0,0,1,1)
        #layGr.addStretch(1)
        layGr.addLayout(self.timeTraceGraph.layout, 0,1,1,1)
        
        layout = QtWidgets.QGridLayout()
        layout.addLayout(layGr,0,0,1,1)

        layout.addWidget(self.tabWidgetInput, 1,0,1,1)
        self.tabInput.setLayout(layout)
        
        
        #---------------new
        centralWidget = QWidget(self)
        ###layout1 = QVBoxLayout()
        layout1 = QGridLayout(centralWidget)
        #layout1.addLayout(GUIFrame)
        layout1.setColumnStretch(0, 1)
        layout1.setColumnStretch(1, 7)
        layout1.addWidget(self.startWindow, 0, 0, 1, 1)
        layout1.addWidget(self.MDI, 0, 1, 1, 1)
        #self.setCentralWidget(centralWidget)
        QVizGlobalOperations.checkEnvSettings()
        QVizPreferences().build()
        #layout1.addWidget(self.GUIVIZ)
        self.tabVIZ.setLayout(layout1)
        #--------------------------------
        
        
    def AddCanvas(self, i, toolbar = 1):
      graph = Graph(self)
      
      # a figure instance to plot on
      #graph.figure = plt.figure()
      self.outpGraph.append(graph)
      # this is the Canvas Widget that displays the `figure`
      # it takes the `figure` instance as a parameter to __init__
      #graph.canvas = FigureCanvas(graph.figure)
      
      #if toolbar == 1:
        # this is the Navigation widget
        # it takes the Canvas widget and a parent
      #  graph.toolbar = NavigationToolbar(graph.canvas, self)
      
      
      #layout = QtWidgets.QVBoxLayout()
      
      #if toolbar == 1:
      #  layout.addWidget(graph.toolbar)
            
      #layout.addWidget(graph.canvas)
        
      return graph.layout
      
                      
    def TableClicked(self):
      print('\n')
      #table.resizeColumnsToContents()
      for currItem in self.tableCurrents.selectedItems():
        print(currItem.row(), currItem.column(), currItem.text())


    def tableColumnPlot(self, table, graph):
      selItems = table.selectedItems()
      col = -1
      if len(selItems) > 0:
        col = selItems[0].column()
      for currItem in selItems:
        if currItem.column() != col:
          col = -1
      if col != -1:
        time = []
        data = []
        n = table.rowCount()
        for i in range(n):
          time.append(float(table.item(i,0).text()))
          data.append(float(table.item(i,col).text()))
          
        self.timeTraceGraph.Plot(time, data)
        
    
    def tableCoilsEdited(self, table):
      table.resizeColumnsToContents()
      
        
    def tableSelectionChanged(self, table):
      table.resizeColumnsToContents()
      self.tableColumnPlot(table, self.timeTraceGraph)
    
    
    def CreateInputTabCoils(self, parentObject, recordset):
      # Coils tab
      title = "Coils"
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["coils"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0)
      
      headerNames = [item["name"] for item in record["geometry"]]
      headerMeta = ["Nr", "Nz", "Direction", "Circuit"]      
      headerGeometry = ["Rc", "Zc", "dR", "dZ", "Alpha", "Beta"]
      
      n = len(record["geometry"])
      m1 = 4
      m2 = 6
      table.setRowCount(n)
      table.setColumnCount(m1 + m2)
      table.setHorizontalHeaderLabels(headerMeta + headerGeometry)      
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        for j in range(m1):
          table.setItem(i, j, record["geometry"][i]["items_p"][j])
        for j in range(m2):
          table.setItem(i, m1+j, record["geometry"][i]["items_g"][j])
      table.resizeColumnsToContents()
      table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))
      
      
      # Table for circuit resistances
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1)
      
      n = len(record["resist"]["items"])
      m = 1
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(["Circuit Resistance"])      
      #table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["resist"]["items"][i])
      table.resizeColumnsToContents()
            


      # Vessel tab
      title = "Vessel"
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["vessel"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0)
      
      n = len(record["geometry"])
      
      headerNames = [str(i+1) for i in range(n)]
      headerMeta = ["Nr", "Nz", "Direction", "Circuit"]      
      headerGeometry = ["Rc", "Zc", "dR", "dZ", "Alpha", "Beta"]
           
      m1 = 4
      m2 = 6
      table.setRowCount(n)
      table.setColumnCount(m1 + m2)
      table.setHorizontalHeaderLabels(headerMeta + headerGeometry)
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        for j in range(m1):
          table.setItem(i, j, record["geometry"][i]["items_p"][j])
        for j in range(m2):
          table.setItem(i, m1+j, record["geometry"][i]["items_g"][j])
      table.resizeColumnsToContents()
      table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))
      
      
      # Table for circuit resistances
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1)
      
      n = len(record["resist"]["items"])
      m = 1
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(["Circuit Resistance"])
      #table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["resist"]["items"][i])
      table.resizeColumnsToContents()
      
      
      
      # Loops tab
      title = "Loops"
      tab = QtWidgets.QWidget()
      tab.setObjectName("tab" + title)
      grid = QtWidgets.QGridLayout()
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["loops"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0)
      
      n = len(record["items"])
      
      headerNames = [str(i+1) for i in range(n)]
      headerParameters = ["R", "Z"]
      
      m = 2

      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(headerParameters)
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["items"][i]["r"])
        table.setItem(i, 1, record["items"][i]["z"])
        table.resizeColumnsToContents()
        table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))      


      # Probes tab
      title = "Probes"
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["probes"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0, 1, 1)
      
      n = len(record["items"])
      
      headerNames = [str(i+1) for i in range(n)]
      headerParameters = ["R", "Z", "Angle", "Length"]      
      
      m = 4
      
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(headerParameters)      
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["items"][i]["r"])
        table.setItem(i, 1, record["items"][i]["z"])
        table.setItem(i, 2, record["items"][i]["a"])
        table.setItem(i, 3, record["items"][i]["l"])
        table.resizeColumnsToContents()
        table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))

      
      
      # Table for subdivisions data
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1, 1, 1)
      table.setRowCount(1)
      table.setColumnCount(1)
      table.setItem(0, 0, record["common"][1])
      table.setVerticalHeaderLabels(["Probe subdivisions"])
      table.horizontalHeader().setVisible(False)
      
      
      # Subdivision is specified using QLineEdit
      #labelProbesDivision = QtWidgets.QLabel(tab)
      #labelProbesDivision.setObjectName("labelProbesDivision")
      #labelProbesDivision.setText("Probe subdivisions")
      #grid.addWidget(labelProbesDivision, 0, 0, 1, 1)

      #lineProbesDivision = QtWidgets.QLineEdit(tab)
      #lineProbesDivision.setObjectName("lineProbesDivision")
      #lineProbesDivision.setValidator(QtGui.QIntValidator(1,999))
      ##lineProbesDivision.setPlaceholderText("Enter your text")
      #lineProbesDivision.setText(str(record["common"]["data"][1]))
      #grid.addWidget(lineProbesDivision, 0, 1, 1, 1)



      # Limiter tab
      title = "Limiter"
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["limiter"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0)
      
      n = len(record["items_r"])
      
      headerNames = [str(i+1) for i in range(n)]
      headerParameters = ["R", "Z"]      
      
      m = 2
      
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(headerParameters)
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["items_r"][i])
        table.setItem(i, 1, record["items_z"][i])
        table.resizeColumnsToContents()
        table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))


      # Area tab
      title = "Area"
      tab = QtWidgets.QWidget()
      tab.setObjectName("tab" + title)
      grid = QtWidgets.QGridLayout()
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      record = recordset["area"]
      # Table for coils data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 0)
      
      n = 2
      
      headerNames = ["Min", "Max"]
      headerParameters = ["R", "Z"]
      
      m = 2
      
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(headerNames)
      table.setVerticalHeaderLabels(headerParameters)

      table.setItem(0, 0, record["items_r"][0])
      table.setItem(0, 1, record["items_r"][1])
      
      table.setItem(1, 0, record["items_z"][0])
      table.setItem(1, 1, record["items_z"][1])
      table.resizeColumnsToContents()
      table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x))
    
    
    
    def CreateInputTabTimed(self, parentObject, setOfParams, title):
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      for i in range(len(setOfParams)):
        table = QtWidgets.QTableWidget(tab)
        table.setDragEnabled(False)
        table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
        grid.addWidget(table, i, 0)
        
        datarow = setOfParams[i]
        if datarow["type"] == "timed":
          n = len(datarow["items"])
          m = len(datarow["items"][0])
          if len(datarow["names2"]) == m:
            header = datarow["names2"]
          else:
            header = ["Time"] + [str(j) for j in range(1,m+1)]
          table.setRowCount(n)
          table.setColumnCount(m)
          table.setHorizontalHeaderLabels(header)
          for i in range(n):
            for j in range(m):
              table.setItem(i, j, datarow["items"][i][j])
          table.itemSelectionChanged.connect(lambda x=table:self.tableSelectionChanged(x))
          
          
      
    def CreateInputTab(self, parentObject, setOfParams, title):
      tab = QtWidgets.QWidget()         
      tab.setObjectName("tab" + title)     
      grid = QtWidgets.QGridLayout()      
      tab.setLayout(grid)
      
      parentObject.addTab(tab, title)
      self.tabInputs.append(tab)
      
      
      for i in range(len(setOfParams)):
        table = QtWidgets.QTableWidget(tab)
        table.setDragEnabled(False)
        table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
        grid.addWidget(table, i, 0)
        
        datarow = setOfParams[i]
        m = len(datarow)
        table.setColumnCount(m)
        table.setRowCount(1)
        labels = []
        for j in range(m):
          table.setItem(0, j, datarow[j].widget)
          label = ""
          if datarow[j].name != "":
            label = datarow[j].name
          else:
            label = datarow[j].rawname
            
          if datarow[j].unit != "":
            label = label + ' [' + datarow[j].unit + ']'
            
          labels.append(label)
          
        table.setHorizontalHeaderLabels(labels)
        table.resizeColumnsToContents()
         
      
    def LoadSetups(self):
      dirTmp = QtWidgets.QFileDialog.getExistingDirectory(self, "Select folder load from...", self.directoryLoad)
      #dirTmp = os.path.normpath(os.getcwd() + '/../../machines/iter/15MA_40ka')

      if dirTmp: 
        self.directoryLoad = dirTmp
        self.labelDirLoad.setText(self.directoryLoad)
        
        self.tabInputs = []
        
        
        self.DINAData["kpr"] = CodeParameter(mytype=int, value=0, comment = '')
        self.DINAData["time_eq"] = CodeParameter(mytype=int, value=0, comment = '', unit='ms')
        self.DINAData["tau"] = CodeParameter(mytype=float, value=0., comment = '', unit='s')
        self.DINAData["tau_sim"] = CodeParameter(mytype=float, value=0., comment = '', unit='ms')
        self.DINAData["tau_dw"] = CodeParameter(mytype=float, value=0., comment = '', unit='ms')
        self.DINAData["rs0"] = CodeParameter(mytype=float, value=0., comment = '', unit='cm')
        self.DINAData["bt0"] = CodeParameter(mytype=float, value=0., comment = '', unit='Gs')
        self.DINAData["key_t11"] = CodeParameter(mytype=int, value=0, comment = '')
        self.DINAData["tt_dina"] = CodeParameter(mytype=float, value=0., comment = '', unit='ms')
        self.DINAData["p"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["T_e"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["T_i"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["gam"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["gain_puff"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["bohm_gbohm"] = CodeParameter(mytype=int, value=0, comment = '')
        self.DINAData["pcchp_end"] = CodeParameter(mytype=float, value=0., comment = '')
        self.DINAData["ener_ext"] = CodeParameter(mytype=bool, value=False, comment = '')
        self.DINAData["dens_ext"] = CodeParameter(mytype=bool, value=False, comment = '')
        self.DINAData["ajb_ext"] = CodeParameter(mytype=bool, value=False, comment = '')
        
        
        
        self.controlData["tcont2"] = CodeParameter(mytype=int, value=0., comment = '')
        self.controlData["Ip_div"] = CodeParameter(mytype=int, value=0., comment = '')
        self.controlData["ref_ramp"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["Ip_rd"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["trd_ref"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["c_a_tpl1"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["c_a_tpl1_eob"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["c_a_tpl2"] = CodeParameter(mytype=int, value=0., comment = '')
        self.controlData["c_a_tpl_min"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["y0"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["c1_y0"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["c2_y0"] = CodeParameter(mytype=float, value=0., comment = '')
        self.controlData["t_tran2D"] = CodeParameter(mytype=float, value=0., comment = '', unit='ms')
        self.controlData["Tu"] = CodeParameter(mytype=float, value=0., comment = '', name='Tu')
        self.controlData["c_cur_max"] = CodeParameter(mytype=int, value=0., comment = '', name='c_cur_max')
        
        self.controlData["tt_rampup"] = CodeParameter(mytype=float, value=0., comment = '', unit='ms')
        self.controlData["dt_end_sim"] = CodeParameter(mytype=float, value=0., comment = '', unit='s')
        self.controlData["dtpl_term_l"] = CodeParameter(mytype=float, value=0., comment = '', unit='s')
        self.controlData["cIp_end"] = CodeParameter(mytype=float, value=0., comment = '', unit='MA')
        self.controlData["Ics1_eob"] = CodeParameter(mytype=float, value=0., comment = 'Value of the current in CS1 circuit at which the current ramp down starts', name='I_CS1 EOF', unit='kA')
        self.controlData["rms_noise"] = CodeParameter(mytype=float, value=0., comment = 'RMS of noise in the diagnostic signal of dZ/dt for VS stabilization', name='VS RMS noise', unit='m/s')
        
        
        
        self.gapsData = []
        self.generalData = []
        self.externalData = []
        
        
        
        self.tabDINADataChild.clear()
        self.tabControlDataChild.clear()
        self.tabGeneralDataChild.clear()
        self.tabExternalDataChild.clear()
        
        
        
        
        self.LoadTokamakData()
        self.LoadControlData()
        self.LoadDINAData()
        
        
        self.LoadGeneralData()
        #self.LoadExternalData()
       
       
        for record in self.generalData:
          self.CreateInputTabTimed(self.tabGeneralDataChild, [record], record["title"])
        
    
    
    def LoadExternalData(self):
      filename = self.directoryLoad + '/external_data.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        parentObject = self.tabExternalDataChild
        
        

        params = self.ReadParameters(f)
        self.externalData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])

        params = self.ReadParametersSet(f, 3)
        self.externalData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])
      
        timedData = self.ReadTimeTable(f)
        self.externalData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        
        #consist = setOfParams["data"] + [timedData]
        #self.CreateInputTab(parentObject, consist, "together")
        

        #heap = self.ReadHeap(f, 335)
        #self.externalData.append(heap)

        
        
        f.close()
        
        #1print('External data:')
        #for x in self.externalData:
        #  print(x)
        #print(self.externalData)

 
 
    def LoadControlData(self):
      filename = self.directoryLoad + '/control_init_1.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        parentObject = self.tabControlDataChild

        #control_data2.dat
        names = ('tcont2', 'Ip_div', 'ref_ramp', 'Ip_rd', 'trd_ref')
        self.ReadParameters(f, [self.controlData[k] for k in names])
        names = ('c_a_tpl1', 'c_a_tpl1_eob', 'c_a_tpl2', 'c_a_tpl_min', 'y0', 'c1_y0', 'c2_y0')
        self.ReadParameters(f, [self.controlData[k] for k in names])
        names = ('t_tran2D',)
        self.ReadParameters(f, [self.controlData[k] for k in names])
        
        #elong.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g1.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g1_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g2.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g2_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g3.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g3_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g4.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g4_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g5.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g5_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g6.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #g6_term.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #tt_kavin2.dat
        names = ['tt_rampup']
        self.ReadParameters(f, [self.controlData[k] for k in names])
        names = ['dt_end_sim', 'dtpl_term_l', 'cIp_end']
        self.ReadParameters(f, [self.controlData[k] for k in names])
        names = ['Ics1_eob', 'rms_noise']
        self.ReadParameters(f, [self.controlData[k] for k in names])
        
        
        #control_data.dat
        names = ['Tu', 'c_cur_max']
        f.readline()
        data = self.ReadRow(f)
        self.controlData['Tu'].SetValue(data[-1])
        
        f.readline()
        data = self.ReadRow(f)
        self.controlData['c_cur_max'].SetValue(data[0])
        

        #self.CreateInputTab(parentObject, params["data"], params["title"])
        
        
        # number of coil turns
        #params = self.ReadParameters(f)
        #self.controlData.append(params)
        #self.CreateInputTab(parentObject, [params], params["title"]) 
        
        
        f.close()
        
        
        ## Appearing in GUI
        
        params = []
        
        names = ('tcont2', 'Ip_div', 'ref_ramp', 'Ip_rd', 'trd_ref')
        params.append([self.controlData[k] for k in names])
        
        names = ('c_a_tpl1', 'c_a_tpl1_eob', 'c_a_tpl2', 'c_a_tpl_min', 'y0', 'c1_y0', 'c2_y0')
        params.append([self.controlData[k] for k in names])
        
        names = ('t_tran2D',)
        params.append([self.controlData[k] for k in names])
        
        names = ('Tu', 'c_cur_max')
        params.append([self.controlData[k] for k in names])
        
        self.CreateInputTab(parentObject, params, 'Controller Parameters')
        
        
        
        params = []
        
        names = ('tt_rampup',)
        params.append([self.controlData[k] for k in names])
        
        names = ('dt_end_sim', 'dtpl_term_l', 'cIp_end')
        params.append([self.controlData[k] for k in names])
        
        names = ('Ics1_eob', 'rms_noise')
        params.append([self.controlData[k] for k in names])
        
        self.CreateInputTab(parentObject, params, 'Kavin2')
        
    
    def LoadGeneralData(self):
      
      
      filename = self.directoryLoad + '/scr_data.dat'
      if os.path.isfile(filename):
        ntur=[554.,554.,554.,554.,554.,  248.6, 115.2, 185.9, 169.9, 216.8, 459.4]
        
        f = open(filename, 'rt')
        
        # scr_data.dat
        timedData = self.ReadScrData(f)
        f.close()
        
        timedData["title"] = "scr_data.dat"
        
        for row in timedData["items"]:
          
          # Ip
          wItem = row[1]
          wItem.setText(str(float(wItem.text())*(-1.e6)))
          
          # CS&PF currents
          for j in range(len(row)-2):
            wItem = row[j+2]
            wItem.setText(str(float(wItem.text())*(-1.e6)/ntur[j]))
            
        self.generalData.append(timedData)
        
        
      
      filename = self.directoryLoad + '/volt.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        # volt.dat
        timedData = self.ReadScrData(f)
        f.close()
        
        timedData["title"] = "volt.dat"
        # ms -> s
        for row in timedData["items"]:
          wItem = row[0]
          wItem.setText(str(float(wItem.text())*1.e-3))
          
          # CS&PF voltages
          for j in range(len(row)-1):
            wItem = row[j+1]
            wItem.setText(str(float(wItem.text())*(-ntur[j])))
        
        self.generalData.append(timedData)
        
        
        
      
      
      
    def LoadTokamakData(self):
      filename = self.directoryLoad + '/tokamak_config.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        parentObject = self.tabTokamakDataChild
        parentObject.clear()
        
        self.TokamakData = {}
        
        # tokamak_config.dat
        self.TokamakData = self.ReadTokamakConfig(f)
        f.close()
        
        self.CreateInputTabCoils(parentObject, self.TokamakData)
        
    
    
    def LoadDINAData(self):
      filename = self.directoryLoad + '/dina_data.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        parentObject = self.tabDINADataChild
        
        
        # time_eq.dat
        names = ['time_eq']
        self.ReadParameters(f, [self.DINAData['time_eq']])
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        # kpr.dat
        names = ['kpr']
        self.ReadParameters(f, [self.DINAData['kpr']])
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        # for002_kav.dat
        names = ['tau', 'rs0', 'key_t11', 'bt0']
        self.ReadParameters(f, [self.DINAData['tau'], self.DINAData['rs0'], self.DINAData['key_t11'], self.DINAData['bt0']])
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        # gaps_data_ramp
        #names = []
        #params = self.ReadParametersSet(f, 3)
        #ng = int(params["data"][0]["items"][0].text())
        #params["data"][1]["names"] = []
        #params["data"][2]["names"] = []
        #for ig in range(ng):
          #names.append('g'+str(ig+1)+'_R')
          #params["data"][1]["names"].append('g'+str(ig+1)+'_R')
          #params["data"][2]["names"].append('g'+str(ig+1)+'_Z')
        #self.CreateInputTab(parentObject, params["data"], params["title"])
        
        
        line = f.readline().rstrip()
        line = f.readline().rstrip()
        line = f.readline().rstrip()
        line = f.readline().rstrip()
        line = f.readline().rstrip()
        line = f.readline().rstrip()
        
        
        # tran_times.dat
        names = ['tt_dina']
        self.ReadParameters(f, [self.DINAData['tt_dina']])
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        #pfres.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #ech.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #n_d.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #gamma_z.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #gamma_z2.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)

        # init.dat
        names = ('p', 'T_e', 'T_i', 'gam', 'gain_puff')
        self.ReadParametersRow(f, [self.DINAData[k] for k in names])
        
        #emo.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        
        #dens.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #gamma_z1.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
 
        #gamma_z3.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)

        #gamma_z4.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)

        # bohm_gbohm.dat
        self.ReadParameters(f, [self.DINAData['bohm_gbohm']])
        #self.DINAData.append(params)
        #self.CreateInputTab(parentObject, [params], params["title"])

        # tay_simul.dat
        self.ReadParameters(f, [self.DINAData['tau_sim']])
        #self.DINAData.append(params)
        #self.CreateInputTab(parentObject, [params], params["title"])

        # dw.dat
        self.ReadParameters(f, [self.DINAData['tau_dw']])
        #self.DINAData.append(params)
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        # pcchp_end.dat
        self.ReadParameters(f, [self.DINAData['pcchp_end']])
        #self.DINAData.append(params)
        #self.CreateInputTab(parentObject, [params], params["title"])
        
        # transp_ext.dat
        names = ('ener_ext', 'dens_ext', 'ajb_ext')
        self.ReadParameters(f, [self.DINAData[k] for k in names])
        
        
        f.close()
        
        
        ## Appearing in the GUI
        params = []
        
        names = ('time_eq', 'kpr', 'tt_dina')
        params.append([self.DINAData[k] for k in names])
        
        names = ['tau', 'rs0', 'key_t11', 'bt0']
        params.append([self.DINAData[k] for k in names])
        
        names = ('p', 'T_e', 'T_i', 'gam', 'gain_puff')
        params.append([self.DINAData[k] for k in names])
        
        self.CreateInputTab(parentObject, params, 'Parameters1')
        
        
        
        params = []
        
        names = ('bohm_gbohm', 'tau_sim', 'tau_dw', 'pcchp_end')
        params.append([self.DINAData[k] for k in names])
        
        names = ('ener_ext', 'dens_ext', 'ajb_ext')
        params.append([self.DINAData[k] for k in names])
        
        self.CreateInputTab(parentObject, params, 'Parameters2')
        
        
        
    
    def ReadCoilData(self, f):
      output = {}      
      output["type"] = "coil"
      
      output["name"] = f.readline().strip()
      
      props = self.ReadRowStr(f)
      if len(props) != 4:
        print("Incorrect properties amount: " + str(len(props)))
      output["items_p"] = [QtWidgets.QTableWidgetItem(x) for x in props]
      
      geometry = self.ReadRowStr(f)
      if len(geometry) != 6:
        print("Incorrect geometry items amount: " + str(len(geometry)))     
      output["items_g"] = [QtWidgets.QTableWidgetItem(x) for x in geometry]
      return output



    def ReadResistanceData(self, f, n):
      output = {}
      output["type"] = "resist-list"
      data = []
      
      for i in range(n):
        line = f.readline().rstrip()
        description = line.split()
        data.append(float(description[0]))
        
      output["items"] = [QtWidgets.QTableWidgetItem(str(x)) for x in data]
      return output
    
    
    
    def ReadTokamakConfig(self, f):
      output = {}
      
      # Coils
      record = {}
      data = []
      f.readline()
      NPF = self.ReadRow(f)
      NPF_items = [QtWidgets.QTableWidgetItem(str(x)) for x in NPF]
      record["common_geom"] = NPF_items
      npf = NPF[0]
      print("npf = " + str(npf))
      for i in range(npf):
        data.append(self.ReadCoilData(f))
      record["geometry"] = data
      
      # Coil resistances
      data = []
      f.readline()
      NPF = self.ReadRow(f)
      record["common_res"] = NPF
      npf = NPF[0]
      print("npf res = " + str(npf))
      record["resist"] = self.ReadResistanceData(f, npf) 
      
      output["coils"] = record
      
      
      # Vessel
      record = {}
      data = []
      f.readline()
      NCAM = self.ReadRow(f)
      record["common_geom"] = NCAM
      ncam = NCAM[0]
      print("ncam = " + str(ncam))
      for i in range(ncam):
        data.append(self.ReadCoilData(f))
      record["geometry"] = data
      
      # Vessel resistances
      f.readline()
      NCAM = self.ReadRow(f)
      record["common_res"] = NCAM
      ncam = NCAM[0]
      print("ncam res = " + str(ncam))
      record["resist"] = self.ReadResistanceData(f, ncam)
      
      output["vessel"] = record
      
      
      # Loops
      record = {}
      f.readline()
      NLOOP = self.ReadRow(f)
      record["common"] = NLOOP
      nloop = NLOOP[0]
      print("nloop = " + str(nloop))
      loops = [] 
      #loopR = []
      #loopZ = []
      for i in range(nloop):
        line = self.ReadRow(f)
        #loopR.append(line[0])
        #loopZ.append(line[1])  
        loop = {}
        loop["r"] = QtWidgets.QTableWidgetItem(str(line[0]))
        loop["z"] = QtWidgets.QTableWidgetItem(str(line[1]))
        loops.append(loop)
      #record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in loopR] 
      #record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in loopZ] 
      record["items"] = loops
      output["loops"] = record
      
      
      # Probes
      record = {}
      f.readline()
      NPROB = self.ReadRow(f)
      NPROB_items = [QtWidgets.QTableWidgetItem(str(x)) for x in NPROB]
      record["common"] = NPROB_items
      nprob = NPROB[0]
      print("nprob = " + str(nprob))
      #probR = []
      #probZ = []
      #probA = []
      #probL = []
      probes = []
      for i in range(nprob):
        line = self.ReadRow(f)
        #probR.append(line[0])
        #probZ.append(line[1])    
        #probA.append(line[2])
        #probL.append(line[3])         
        probe = {}
        probe["r"] = QtWidgets.QTableWidgetItem(str(line[0]))
        probe["z"] = QtWidgets.QTableWidgetItem(str(line[1]))
        probe["a"] = QtWidgets.QTableWidgetItem(str(line[2]))
        probe["l"] = QtWidgets.QTableWidgetItem(str(line[3]))
        probes.append(probe)       
      #record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probR] 
      #record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probZ] 
      #record["items_a"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probA] 
      #record["items_l"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probL]      
      record["items"] = probes
      output["probes"] = record
      
      
      # Limiter
      record = {}
      f.readline()
      NLIM = self.ReadRow(f)
      record["common"] = NLIM
      nlim = NLIM[0]
      print("nlim = " + str(nlim))
      limR = []
      limZ = []
      for i in range(nlim):
        line = self.ReadRow(f)
        limR.append(line[0])
        limZ.append(line[1])         
      record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in limR] 
      record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in limZ] 
      output["limiter"] = record
      
      
      # Area
      record = {}
      record["name"] = f.readline().rstrip()
      lineR = self.ReadRow(f)
      lineZ = self.ReadRow(f)
      record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in lineR]
      record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in lineZ]
      output["area"] = record
      
      
      output["type"] = "tokamakdata"
      
      return output


    
    def SaveTokamakConfig(self, f, record):
      
      # Coils 
      recsave = record["coils"]
      self.SaveFilePart(f, recsave["common_geom"])
      for coil in recsave["geometry"]:       
        self.SaveFilePart(f, coil)     
      self.SaveFilePart(f, recsave["common_res"])
      self.SaveFilePart(f, recsave["resist"])
         
         
      # Vessel
      recsave = record["vessel"]
      self.SaveFilePart(f, recsave["common_geom"])
      for coil in recsave["geometry"]:       
        self.SaveFilePart(f, coil)     
      self.SaveFilePart(f, recsave["common_res"])
      self.SaveFilePart(f, recsave["resist"])  


      # Loops
      recsave = record["loops"]
      self.SaveFilePart(f, recsave["common"])
      nloop = len(recsave["items"])
      for i in range(nloop):
        s1 = recsave["items"][i]["r"].text()
        s2 = recsave["items"][i]["z"].text()
        f.write("  " + s1 + "  " + s2 + "\n")
      
      
      # Probes
      recsave = record["probes"]
      self.SaveFilePart(f, recsave["common"])
      nprobes = len(recsave["items"])
      for i in range(nprobes):
        s1 = recsave["items"][i]["r"].text()
        s2 = recsave["items"][i]["z"].text()
        s3 = recsave["items"][i]["a"].text()
        s4 = recsave["items"][i]["l"].text()
        f.write("  " + s1 + "  " + s2 + "  " + s3 + "  " + s4 + "\n")


      # Limiter
      recsave = record["limiter"]
      self.SaveFilePart(f, recsave["common"])
      nlim = len(recsave["items_r"])
      for i in range(nlim):
        s1 = recsave["items_r"][i].text()
        s2 = recsave["items_z"][i].text()
        f.write("  " + s1 + "  " + s2 + "\n")
        
        
      # Area
      recsave = record["area"]
      f.write(recsave["name"] + "\n")
      s1 = recsave["items_r"][0].text()
      s2 = recsave["items_r"][1].text()
      f.write("  " + s1 + "  " + s2 + "\n")
      s1 = recsave["items_z"][0].text()
      s2 = recsave["items_z"][1].text()
      f.write("  " + s1 + "  " + s2 + "\n") 
 
 
 
    def JoinListStr(self, lst):
      s = ""
      for x in lst:
        s += str(x) + "   "
      return s  

 
 
    def SaveFilePart(self, f, record):
      if isinstance(record, dict):
        #print("Dictionary found")
        if record["type"] == "heap":
          f.write(record["header"] + "\n")
          data = record["data"]
          for item in data:
            s = ""
            if isinstance(item, list):
              for x in item:       
                s += str(x) + "   "  
              f.write(s + "\n") 
            else:
              f.write(str(item) + "\n") 
        elif record["type"] == "params":
          strWr = ""
          for s in record["names"]:
            strWr = strWr + s + "   "
          if "title" in record:
            strWr = strWr + "!" + record["title"]
          f.write(strWr + "\n") 
          strWr = ""
          for item in record["items"]:
            strWr = strWr + item.text() + "   "
          f.write(strWr + "\n")  
          
        elif record["type"] == "paramsrow":
          for i in range(len(record["items"])):
            strWr = " " + record["items"][i].text() + "   " + record["names"][i]
            if i == 0 and "title" in record:
              strWr += "  !" + record["title"]
            f.write(strWr + "\n")                     
          
        elif record["type"] == "timed":
          n = len(record["items"])
          s = self.JoinListStr(record["names1"])
          if "title" in record:
            s += "!" + record["title"]
          f.write(s + "\n") 
          s = str(n)
          if "add" in record:
            for x in record["add"]:
              s += "  " + str(x)
          f.write(s + "\n")
          
          f.write(self.JoinListStr(record["names2"]) + "\n")
          
          for i in range(n):
            s = ""
            for item in record["items"][i]:
              s += item.text() + "  "
            f.write(s + "\n")
        
        elif record["type"] == "coil":
          s = record["name"]
          f.write(s + "\n") 
          f.write("  " + self.JoinListStr([item.text() for item in record["items_p"]]) + "\n")
          f.write("  " + self.JoinListStr([item.text() for item in record["items_g"]]) + "\n")
        
        elif record["type"] == "resist-list":
          for item in record["items"]:
            s = item.text()
            f.write("  " + s + "\n")        
        
        elif record["type"] == "set":
          for item in record["data"]:
            self.SaveFilePart(f,item)
      elif isinstance(record, list):
        for item in record:
          self.SaveFilePart(f,item)
    
    
    
    def SaveDataToFile(self, data, filename):
      f = open(filename, 'wt')
      for record in data:
        self.SaveFilePart(f, record)
      f.close()
      
      
    
    
    def GetXMLString(self, data):
      root = ET.Element("parameters")
      for key in data:
        element = ET.SubElement(root, key)
        element.text = str(data[key].widget.text())
        
      #tree = ET.ElementTree(root)
      xmlstr = minidom.parseString(ET.tostring(root)).toprettyxml(indent="   ")
      return xmlstr
 
 
    def GetStuctWithFieldValue(self, record, field, value):
      for item in record:
        if field in item:
          if item[field] == value:
            return item
      print("item is not found")    
      return []  
   
   
    def ReadParametersRow(self, f, CodeParameters):
      output = {}
      data = []
      names = []
      
      nrows = len(CodeParameters)
      for i in range(nrows):
        line = f.readline().rstrip()
        if i == 0:
          header = line.split("!")
          if len(header) > 1:
            line = header[0]
        description = line.split()
        data.append(float(description[0]))
        names.append(description[1])
        
      for i in range(nrows):
        CodeParameters[i].SetValue(data[i])
        CodeParameters[i].rawname = names[i]
      
      return
    
    
    
    def ReadParameters(self, f, CodeParameters):
      output = {}
      data = []
      
      line = f.readline().rstrip()
      if not line:
        print('Unexpected end of file')
        return
      #data.append(line)
      
      header = line.split("!")
      params = header[0]
      names = params.split()
      print(names)
      #if len(header) > 1:
        #output["title"] = header[1].strip()
           
      data = self.ReadRow(f)    
      print(data)
      
      if len(data) != len(CodeParameters):
        print('Found ' + str(len(data)) + ' parameters when expected ' + str(len(CodeParameters)))
      
      n = len(CodeParameters)
      
      for i in range(n):
        CodeParameters[i].SetValue(data[i])
        if i < len(names):
          CodeParameters[i].rawname = names[i]
    
    
    
    def ReadParametersSet(self, f, nset):
      output = {}
      data = []
      
      for i in range(nset):
        data.append(self.ReadParameters(f))
      
      output["data"] = data
      if "title" in data[0]:
        print('Set Name = ' + data[0]["title"])
        output["title"] = data[0]["title"]
      else:
        output["title"] = "none"
        
      output["type"] = "set"
      return output
        
        
        
    def ReadTimeTable(self, f):
      output = {}
      
      line = f.readline().rstrip()
      if not line:
        print('Unexpected end of file')
        return
      
      header = line.split("!")
      params = header[0]
      names1 = params.split()
      print(names1)
      output["names1"] = names1
      if len(header) > 1:
        output["title"] = header[1].strip()
      
      datant = self.ReadRow(f)     
      if len(datant) == 0:
        return []
      nt = datant[0]

      if len(datant) > 1:
        output["add"] = datant[1:]
      
      names2 = f.readline().rstrip().split()
      output["names2"] = names2
      
      items = []
      for it in range(nt):
        row = self.ReadRow(f)
        items.append([QtWidgets.QTableWidgetItem(str(x)) for x in row])
        
        #lineFl = [float(dataStr[i]) for i in range(len(dataStr))]
        #data.append(lineFl)
      
      output["type"] = "timed"
      output["items"] = items  

      return output
    
    
    
    def ReadScrData(self, f):
      
      output = {}
      
      line = f.readline().rstrip()
      if not line:
        print('Unexpected end of file')
        return
      
      names2 = line.split()
      output["names2"] = names2
      
      items = []
      while True:
        line = f.readline()
        if not line:
          break
        dataStr = line.rstrip().split()
        data = []
        for i in range(len(dataStr)):
          data.append(float(dataStr[i]))
        
        if (len(data) > 0):
          items.append([QtWidgets.QTableWidgetItem(str(x)) for x in data])
          #items.append([x for x in data])
        
        #lineFl = [float(dataStr[i]) for i in range(len(dataStr))]
        #data.append(lineFl)
      
      output["type"] = "timed"
      output["items"] = items
      
      return output
    
    
    
    def ReadHeap(self, f, nrows):
      record = {}
      data = []
      record["header"] = self.ReadLineStripped(f)
      for i in range(nrows-1):
        #data.append(self.ReadRow(f))
        data.append(self.ReadLineStripped(f))
      record["data"] = data 
      record["type"] = "heap" 
      return record
    
    
    def ReadLineStripped(self, f):
      line = f.readline()
      if not line:
        print('Unexpected end of file')
        return ""
      return line.rstrip()


    def ReadRowStr(self, f):
      line = self.ReadLineStripped(f)
      dataStr = line.split()    
      return dataStr  
    
    
    def ReadRow(self, f):
      dataStr = self.ReadRowStr(f)
      data = []
      for i in range(len(dataStr)):
        if dataStr[i].isdigit():
          data.append(int(dataStr[i]))
        else:
          data.append(float(dataStr[i])) 
                 
      return data
 
 
    def FillPulseScheduleItem(self, PSitem, record, col=1, mult=1.):
      nt = len(record["items"])
      
      PSitem.time.resize(nt)
      PSitem.data.resize(nt)
      
      for i in range(nt):
        ins = record["items"][i]
        PSitem.time[i] = float(ins[0].text())
        PSitem.data[i] = float(ins[col].text())*mult
        
        
    def FillCoilGeometry(self, geometry, record):
                 
      rc = float(record[0].text())
      zc = float(record[1].text())
      length = float(record[2].text())
      height = float(record[3].text())
      alpha = float(record[4].text()) 
      beta = float(record[5].text())   
      
      # Alpha and beta swapped here because in tokamakdata alpha is for height and beta for length
      alpha_imas = beta
      beta_imas = alpha - math.pi/2.0
       
      alpha_imas = alpha_imas%(2.0*math.pi) 
      beta_imas = beta_imas%(2.0*math.pi) 
       
      tol = 1.e-12
      if (abs(alpha_imas) < tol and abs(beta_imas) < tol):     
        geometry.geometry_type = 2
        geometry.rectangle.r = rc
        geometry.rectangle.z = zc
        geometry.rectangle.width = length
        geometry.rectangle.height = height

      else:       
        geometry.geometry_type = 3
        geometry.oblique.r = rc - 0.5*(length*math.cos(beta) + height*math.cos(alpha))
        geometry.oblique.z = zc - 0.5*(length*math.sin(beta) + height*math.sin(alpha))
        geometry.oblique.length_alpha = length
        geometry.oblique.length_beta = height
        geometry.oblique.alpha = alpha_imas
        geometry.oblique.beta = beta_imas        
      
      
    def SaveInputIDS(self, nameSaveSetups):
      # Create input ids
      pulseText = self.lineInputPulse.text()
      runText = self.lineInputRun.text()
      
      if (not pulseText.isnumeric()):
        
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Critical)
        msg.setWindowTitle("Saving IDS")
        msg.setText("Saving IDS failed")
        msg.setInformativeText("Pulse must be numeric.")
          
        retval = msg.exec_()
        return
  
  
      if (not runText.isnumeric()):
        
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Critical)
        msg.setWindowTitle("Saving IDS")
        msg.setText("Saving IDS failed")
        msg.setInformativeText("Run must be numeric.")
        
        retval = msg.exec_()
        return
      
      
      tokamakdata = self.TokamakData
      
      
      pfa1 = imas.pf_active()
      pfa1.ids_properties.homogeneous_time = 1
      pfa1.time.resize(1)
      
      npfa = len(tokamakdata["coils"]["geometry"])
      
      #pfa1.coil.resize(npfa)
      
      #turndata = self.GetStuctWithFieldValue(self.controlData, "title", "n_turn")
      
      #for i in range(npfa):
        
        #coil = tokamakdata["coils"]["geometry"][i]
        
        #pfa1.coil[i].index = coil["name"]
        #pfa1.coil[i].element.resize(1)
        
        #self.FillCoilGeometry(pfa1.coil[i].element[0].geometry, coil["items_g"])
        
        #pfa1.coil[i].element[0].turns_with_sign = float(coil["items_p"][2].text()) #*float(turndata["items"][i].text())
        ##print(str(pfa1.coil[i].element[ie].turns_with_sign))
            
        
        ##print("Coil" + str(i) + ":" + pfa1.coil[i].name)
        ##pfa1.coil[i].resistance = float(tokamakdata["coils"]["resist"]["items"][i].text())

        #pfa1.coil[i].current.data.resize(1)
        #pfa1.coil[i].voltage.data.resize(1)
      
      
      npfa = 12
      
      pfa1.coil.resize(npfa)
      
      ncircuit = 0
      for coil in tokamakdata["coils"]["geometry"]:
        ncircuit = max(ncircuit, int(coil["items_p"][3].text()))
      
      for i in range(npfa):                   
        ne = 0
        icircuit = i + 1
               
        for coil in tokamakdata["coils"]["geometry"]:
          if icircuit == int(coil["items_p"][3].text()):
            ne = ne + 1
                             
        pfa1.coil[i].element.resize(ne)
        
        ie = -1
        for coil in tokamakdata["coils"]["geometry"]:         
          if icircuit == int(coil["items_p"][3].text()):
            ie = ie + 1
            
            pfa1.coil[i].element[ie].name = coil["name"]
            
            
            self.FillCoilGeometry(pfa1.coil[i].element[ie].geometry, coil["items_g"])         
            
            
            pfa1.coil[i].element[ie].turns_with_sign = float(coil["items_p"][2].text())#*float(turndata["items"][i].text())
            #print(str(pfa1.coil[i].element[ie].turns_with_sign))
            
            pfa1.coil[i].name += coil["name"]
        
        #print("Coil" + str(i) + ":" + pfa1.coil[i].name)
        pfa1.coil[i].resistance = float(tokamakdata["coils"]["resist"]["items"][i].text())

        pfa1.coil[i].current.data.resize(1)
        pfa1.coil[i].voltage.data.resize(1)

      pfa1.coil[2].name = "CS1"
      pfa1.coil[11].name = "VS3"
      
      
      
      
      
      
      
      pfp1 = imas.pf_passive()
      pfp1.ids_properties.homogeneous_time = 1
      pfp1.time.resize(1)
      
      ncam = len(tokamakdata["vessel"]["geometry"])
      
      #pfp1.loop.resize(ncam)
      
      
      # Vessel passive elements
      #for iloop in range(ncam):
        
        #cam = tokamakdata["vessel"]["geometry"][iloop]
            
        #pfp1.loop[iloop].element.resize(1)
        
            
        #self.FillCoilGeometry(pfp1.loop[iloop].element[0].geometry, cam["items_g"])
        
        #pfp1.loop[iloop].element[0].turns_with_sign = float(cam["items_p"][2].text())
                    
        #pfp1.loop[iloop].name = cam["name"]
        
        #pfp1.loop[iloop].current.resize(1)

        #pfp1.loop[iloop].resistance = float(tokamakdata["vessel"]["resist"]["items"][iloop].text())
        ##print("Passive " + str(iloop) + " name = " + pfp1.loop[iloop].name)      
      
      
      
      
      
      ncircuitcam = 0
      for cam in tokamakdata["vessel"]["geometry"]:
        ncircuitcam = max(ncircuitcam, int(cam["items_p"][3].text()))
      #ncam = len(tokamakdata["vessel"]["geometry"])
      
      pfp1.loop.resize(ncircuit - npfa + ncircuitcam)
      
      
      # Passive coils
      iloop = -1
      
      for i in range(npfa, ncircuit):
        iloop += 1
        
        ne = 0
        icircuit = i + 1
        
        for coil in tokamakdata["coils"]["geometry"]:
          if icircuit == int(coil["items_p"][3].text()):
            ne = ne + 1
            
        pfp1.loop[iloop].element.resize(ne)
            
        ie = -1
        for coil in tokamakdata["coils"]["geometry"]:         
          if icircuit == int(coil["items_p"][3].text()):
            ie = ie + 1           
            
            pfp1.loop[iloop].element[ie].name = coil["name"]                     
      
            self.FillCoilGeometry(pfp1.loop[iloop].element[ie].geometry, coil["items_g"])  
      
            pfp1.loop[iloop].element[ie].turns_with_sign = float(coil["items_p"][2].text())
      
            pfp1.loop[iloop].name += coil["name"]
            
            pfp1.loop[iloop].current.resize(1)

        pfp1.loop[iloop].resistance = float(tokamakdata["coils"]["resist"]["items"][i].text())           
        #print("Passive " + str(iloop) + " name = " + pfp1.loop[iloop].name)

           
      # Vessel passive elements
      ncircuit = 0
      for cam in tokamakdata["vessel"]["geometry"]:
        ncircuit = max(ncircuit, int(cam["items_p"][3].text()))
      
      for i in range(ncircuit):
        iloop += 1
        
        ne = 0
        icircuit = i + 1
        
        for cam in tokamakdata["vessel"]["geometry"]:
          if icircuit == int(cam["items_p"][3].text()):
            ne = ne + 1
            
        pfp1.loop[iloop].element.resize(ne)
        
        ie = -1
        for cam in tokamakdata["vessel"]["geometry"]:         
          if icircuit == int(cam["items_p"][3].text()):
            ie = ie + 1           
            
            pfp1.loop[iloop].element[ie].name = cam["name"]         
            
            self.FillCoilGeometry(pfp1.loop[iloop].element[ie].geometry, cam["items_g"])  
            
            pfp1.loop[iloop].element[ie].turns_with_sign = float(cam["items_p"][2].text())
                       
            pfp1.loop[iloop].name += cam["name"]
            
            pfp1.loop[iloop].current.resize(1)

        pfp1.loop[iloop].resistance = float(tokamakdata["vessel"]["resist"]["items"][i].text())            
        #print("Passive " + str(iloop) + " name = " + pfp1.loop[iloop].name)      
      
      
      
      
      
      
      
      
      # Magnetic diagnostics
      magnetics = imas.magnetics()
      magnetics.ids_properties.homogeneous_time = 0
      magnetics.time.resize(1)
      
      nloop = len(tokamakdata["loops"]["items"])
      magnetics.flux_loop.resize(nloop)
      for iloop in range(nloop):
        loop = tokamakdata["loops"]["items"][iloop]
        magnetics.flux_loop[iloop].type.index = 1
        magnetics.flux_loop[iloop].position.resize(1)
        magnetics.flux_loop[iloop].position[0].r = float(loop["r"].text())
        magnetics.flux_loop[iloop].position[0].z = float(loop["z"].text())
        magnetics.flux_loop[iloop].position[0].phi = 0.0
      
      nprobe = len(tokamakdata["probes"]["items"])
      magnetics.b_field_pol_probe.resize(nprobe)
      for iprobe in range(nprobe):
        probe = tokamakdata["probes"]["items"][iprobe]
        magnetics.b_field_pol_probe[iprobe].type.index = 1
        magnetics.b_field_pol_probe[iprobe].position.r = float(probe["r"].text())
        magnetics.b_field_pol_probe[iprobe].position.z = float(probe["z"].text())
        magnetics.b_field_pol_probe[iprobe].position.phi = 0.0
        
        a = -float(probe["a"].text())
        if (a < 0.0):
          a = a + 2.0*math.pi       
        magnetics.b_field_pol_probe[iprobe].poloidal_angle = a
        
        magnetics.b_field_pol_probe[iprobe].toroidal_angle = 0.0
        magnetics.b_field_pol_probe[iprobe].length = float(probe["l"].text())
      
      
      
      
      
      wall = imas.wall()
      wall.ids_properties.homogeneous_time = 1
      wall.time.resize(1)
      wall.time[0] = 0.0
      
      wall.description_2d.resize(1)
      wall.description_2d[0].type.index = 0
      
      wall.description_2d[0].limiter.type.index = 0
      
      wall.description_2d[0].limiter.unit.resize(1)
      limiter = tokamakdata["limiter"]
      nlim = len(limiter["items_r"])
      wall.description_2d[0].limiter.unit[0].outline.r.resize(nlim)
      wall.description_2d[0].limiter.unit[0].outline.z.resize(nlim)
      for i in range(nlim):       
        wall.description_2d[0].limiter.unit[0].outline.r[i] = float(limiter["items_r"][i].text())
        wall.description_2d[0].limiter.unit[0].outline.z[i] = float(limiter["items_z"][i].text())
      
      
      
      
      # Pulse schedule
      psch = imas.pulse_schedule()
      psch.ids_properties.homogeneous_time = 0
      psch.time.resize(1)
      
      
      # Densities
      psch.density_control.ion.resize(7)
      
      # Deuterium density
      record = self.GetStuctWithFieldValue(self.generalData, "title", "n_d.dat")
      ion = 0
      psch.density_control.ion[ion].label = 'D'
      psch.density_control.ion[ion].z_ion = 1.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 2.
      psch.density_control.ion[ion].element[0].z_n = 1.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record, mult=1.e19)
      
      # Tritium density
      record = self.GetStuctWithFieldValue(self.generalData, "title", "dens.dat")
      ion = 1
      psch.density_control.ion[ion].label = 'T'
      psch.density_control.ion[ion].z_ion = 1.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 3.
      psch.density_control.ion[ion].element[0].z_n = 1.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record, mult=1.e19)
      
      # Be content (0D transport)
      record = self.GetStuctWithFieldValue(self.generalData, "title", "gamma_z.dat")
      ion = 2
      psch.density_control.ion[ion].label = 'Be'
      psch.density_control.ion[ion].z_ion = 4.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 9.
      psch.density_control.ion[ion].element[0].z_n = 4.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record)
      
      # Be content (1D transport)
      record = self.GetStuctWithFieldValue(self.generalData, "title", "gamma_z1.dat")
      print(record)
      ion = 3
      psch.density_control.ion[ion].label = 'Be'
      psch.density_control.ion[ion].z_ion = 4.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 9.
      psch.density_control.ion[ion].element[0].z_n = 4.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record)
      
      # W content
      record = self.GetStuctWithFieldValue(self.generalData, "title", "gamma_z2.dat")
      ion = 4
      psch.density_control.ion[ion].label = 'W'
      psch.density_control.ion[ion].z_ion = 74.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 183.84
      psch.density_control.ion[ion].element[0].z_n = 74.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record)
       
      # Ar content
      record = self.GetStuctWithFieldValue(self.generalData, "title", "gamma_z3.dat")
      ion = 5
      psch.density_control.ion[ion].label = 'Ar'
      psch.density_control.ion[ion].z_ion = 18.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 40.
      psch.density_control.ion[ion].element[0].z_n = 18.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record)
      
      # Ne content
      record = self.GetStuctWithFieldValue(self.generalData, "title", "gamma_z4.dat")
      ion = 6
      psch.density_control.ion[ion].label = 'Ne'
      psch.density_control.ion[ion].z_ion = 10.
      psch.density_control.ion[ion].element.resize(1)
      psch.density_control.ion[ion].element[0].a = 20.
      psch.density_control.ion[ion].element[0].z_n = 10.
      psch.density_control.ion[ion].element[0].atoms_n = 1
      self.FillPulseScheduleItem(psch.density_control.ion[ion].n_i_volume_average.reference, record)
 
 
      # Aux heating
      psch.ec.launcher.resize(1)
      # EC heating (Ip < 1.5 MA)
      record = self.GetStuctWithFieldValue(self.generalData, "title", "ech.dat")
      self.FillPulseScheduleItem(psch.ec.launcher[0].power.reference, record, mult=1.e6)
 
      # EC+EQ heating (Ip > 1.5 MA)
      record = self.GetStuctWithFieldValue(self.generalData, "title", "emo.dat")
      self.FillPulseScheduleItem(psch.ec.power.reference, record, col=1, mult=1.e6)
      #self.FillPulseScheduleItem(psch.ic.power.reference, record, col=2, mult=1.e6)
 
 
      ## Magnetic control
      # Elongation
      record = self.GetStuctWithFieldValue(self.generalData, "title", "elong_ref.dat")
      print(record)
      self.FillPulseScheduleItem(psch.position_control.elongation.reference, record)
      psch.position_control.elongation.reference_name = "Elongation"


      psch.position_control.gap.resize(12)
      ng = 6
      GapName = ['Gap_1', 'Gap_2', 'R_LFS', 'Gap_4', 'Gap_5', 'R_HFS']
      #Rg = [422.30, 556.50, 828.06, 750.95, 533.15, 405.99]
      Rg = [422.30, 556.50, 0.0, 750.95, 533.15, 0.0]
      Zg = [-379.20, -440.40, 46.65, 299.71, 458.04, 77.77]
      #Ag = [-65.0, -150.0, 0.0, -135.0, -90.0, 0.0]
      
      # Gaps on ramp-up and flat-top
      for j in range(ng):
        gapname = GapName[j]
        refname = gapname
        record = self.GetStuctWithFieldValue(self.generalData, "title", 'g' + str(j+1) + '.dat')
        self.FillPulseScheduleItem(psch.position_control.gap[j].value.reference, record, mult=1.e-2)
        psch.position_control.gap[j].r = Rg[j]*1.e-2
        psch.position_control.gap[j].z = Zg[j]*1.e-2
        #psch.position_control.gap[j].angle = Ag[j]*numpy.pi/180.
        psch.position_control.gap[j].name = gapname
        psch.position_control.gap[j].identifier = 'g' + str(j+1)
        psch.position_control.gap[j].value.reference_name = refname
      
      # Gaps on current ramp-down
      for j in range(ng):
        gapname = GapName[j]
        refname = gapname + "_Rampdown"
        record = self.GetStuctWithFieldValue(self.generalData, "title", 'g' + str(j+1) + '_term.dat')
        self.FillPulseScheduleItem(psch.position_control.gap[6+j].value.reference, record, mult=1.e-2)
        psch.position_control.gap[ng+j].r = Rg[j]*1.e-2
        psch.position_control.gap[ng+j].z = Zg[j]*1.e-2
        #psch.position_control.gap[ng+j].z = Ag[j]*numpy.pi/180.
        psch.position_control.gap[ng+j].name = gapname
        psch.position_control.gap[ng+j].identifier = 'g' + str(j+1)
        psch.position_control.gap[ng+j].value.reference_name = refname
      
      
      # scr_data.dat
      CircuitName = ["CS3U", "CS2U", "CS1", "CS2L", "CS3L", "PF1", "PF2", "PF3", "PF4", "PF5", "PF6", "VS3", "TRI_SUPP",  "COPP_CLAD", "INB_RAIL"]
      ncirc = 11
      ntur=[554.,554.,554.,554.,554.,  248.6, 115.2, 185.9, 169.9, 216.8, 459.4]
      record = self.GetStuctWithFieldValue(self.generalData, "title", 'scr_data.dat')
      
      # Plasma current
      self.FillPulseScheduleItem(psch.flux_control.i_plasma.reference, record, col=1, mult=1.0)
      
      # CSPF currents
      psch.pf_active.coil.resize(15)
      for j in range(ncirc):
        circname = CircuitName[j]
        refname = circname
        self.FillPulseScheduleItem(psch.pf_active.coil[j].current.reference, record, col=j+2, mult=1.0)
        psch.pf_active.coil[j].name = circname
        psch.pf_active.coil[j].identifier = circname
        psch.pf_active.coil[j].current.reference_name = refname
      
      
      # CSPF voltages
      record = self.GetStuctWithFieldValue(self.generalData, "title", 'volt.dat')
      psch.pf_active.supply.resize(ncirc)
      for j in range(ncirc):
        circname = CircuitName[j]
        refname = circname
        self.FillPulseScheduleItem(psch.pf_active.supply[j].voltage.reference, record, col=j+1, mult=1.0) 
        psch.pf_active.supply[j].name = circname
        psch.pf_active.supply[j].identifier = circname
        psch.pf_active.supply[j].voltage.reference_name = refname
      
      
      # CSPF resistances
      record = self.GetStuctWithFieldValue(self.generalData, "title", 'pfres.dat')
      ncirc = 15
      for j in range(ncirc):
        circname = CircuitName[j]
        refname = circname + 'res'
        self.FillPulseScheduleItem(psch.pf_active.coil[j].resistance_additional.reference, record, col=j+1, mult = 1.0)
        psch.pf_active.coil[j].resistance_additional.reference_name = refname
      
      
      
      
      
      dat1 = imas.dataset_description()
      dat1.ids_properties.homogeneous_time = 1
      dat1.time.resize(1)
      dat1.ids_properties.comment = "DINA setup file name in simulation/workflow"
      dat1.simulation.workflow = nameSaveSetups
      
      
      print("Dataset_description/simulation/workflow " + dat1.simulation.workflow +' saved')
      
      
      
      pulse = int(pulseText)
      run = int(runText)
      user = os.getenv('USER')
      database = self.lineInputTokamak.text()
      
      imas_obj = imas.DBEntry(imas.imasdef.MDSPLUS_BACKEND, database, pulse, run, user, data_version = '3')
      imas_obj.create()
      imas_obj.put(pfa1)
      imas_obj.put(pfp1)
      imas_obj.put(magnetics)
      imas_obj.put(wall)
      imas_obj.put(psch)
      imas_obj.put(dat1)
      imas_obj.close()




    def SaveSetups(self): 
      dirTmp = QtWidgets.QFileDialog.getExistingDirectory(self, "Select folder save into...", self.directorySave)
      #dirTmp = self.directoryLoad + '/temp'

      if dirTmp:
        self.directorySave = dirTmp
        self.labelDirSave.setText(self.directorySave)
        
        
        
        new_imp = self.directorySave + '/imp'
        if os.path.exists(new_imp):
          shutil.rmtree(new_imp)
        #shutil.copytree(self.directoryLoad + '/imp', new_imp)
        shutil.copytree(self.directoryLoad, self.directorySave, dirs_exist_ok=True)
        
        fname = self.directorySave + '/tokamak_config.dat'
        f = open(fname, 'w')
        self.SaveTokamakConfig(f, self.TokamakData)
        f.close()
        #self.SaveDataToFile(self.externalData, self.directorySave + '/external_data.dat')
        #self.SaveDataToFile(self.controlData, self.directorySave + '/control_init.dat')
        #self.SaveDataToFile(self.DINAData, self.directorySave + '/dina_data.dat')
        
        fname = self.directorySave + '/DINA_Parameters.xml'
        f = open(fname, 'w')
        params = self.DINAData.copy()
        keys = ["tt_rampup", "dt_end_sim", "dtpl_term_l", "cIp_end","Ics1_eob", "rms_noise"]
        for key in keys:
          params[key] = self.controlData[key]
        f.write(self.GetXMLString(params))
        f.close()
        
        fname = self.directorySave + '/KMC_Parameters.xml'
        f = open(fname, 'w')
        f.write(self.GetXMLString(self.controlData))
        f.close()
        
        # archive the saved setup files
        tarname = 'SaveSetups' + datetime.datetime.now().strftime("%Y%m%d-%H%M%S") + '.tgz'
        tar = tarfile.open(tarname, "w:gz")
        #tar.add(self.directorySave + '/external_data.dat')
        #tar.add(self.directorySave + '/control_init_1.dat')
        #tar.add(self.directorySave + '/dina_data.dat')
        #tar.add(self.directorySave + '/tokamak_config.dat')
        #tar.add(self.directorySave + '/scr_data.dat')
        #tar.add(self.directorySave + '/volt.dat')
        tar.add(new_imp)
        tar.close()
        print(tarname+' saved')

        self.SaveInputIDS(tarname)

    def PlotOutput(self):
      
        self.pulseout = int(self.textPulse.toPlainText(), 10)
        self.runout = int(self.textRun.toPlainText(), 10)
        self.userout = self.textUser.toPlainText()
        self.baseout = self.textBase.toPlainText()
        print('selected pulse = ', self.pulseout)
        print('selected run = ', self.runout)
        print('selected base = ', self.baseout)

        

        imas_entry_init = imas.DBEntry(imas.imasdef.MDSPLUS_BACKEND, self.baseout, self.pulseout, self.runout, self.userout, data_version = '3')
        imas_entry_init.open()
        
        idslist = {}
        
        idslist['equilibrium'] = imas_entry_init.get('equilibrium')
        idslist['wall'] = imas_entry_init.get('wall')
        idslist['pf_active'] = imas_entry_init.get('pf_active')
        idslist['pf_passive'] = imas_entry_init.get('pf_passive')
        idslist['core_profiles'] = imas_entry_init.get('core_profiles')
        idslist['core_sources'] = imas_entry_init.get('core_sources')
        idslist['summary'] = imas_entry_init.get('summary')
        
        imas_entry_init.close()

        
        self.sum1 = idslist['summary']
        self.cp1 = idslist['core_profiles']
        self.eq1 = idslist['equilibrium']

        
        t1 = self.sum1.time
        ipl1 = self.sum1.global_quantities.ip.value
        li_3 = self.sum1.global_quantities.li.value
        beta_pol = self.sum1.global_quantities.beta_pol.value
        n_e = self.sum1.volume_average.n_e.value
        t_e = self.sum1.volume_average.t_e.value
        t_i = self.sum1.volume_average.t_i_average.value
        z_eff = self.sum1.volume_average.zeff.value
        
        #li_3 = eq1.time_slice[:].global_quantities.li_3;
        
        
        self.outpGraph[0].Plot(t1, ipl1, 'I_pl, A')
        self.outpGraph[1].Plot(t1, n_e, 'N_e, A')
        self.outpGraph[2].Plot(t1, t_e, 'T_e, eV')
        self.outpGraph[3].Plot(t1, t_i, 'T_i, eV')
        self.outpGraph[4].Plot(t1, li_3, 'li_3')
        
        
        #if not self.EQUIL_win:
        #QVizGlobalOperations.checkEnvSettings()
        #QVizPreferences().build()
        self.EQUIL_win = Second_window(idslist)
        self.EQUIL_win.show()
    #--------------------
    def getMDI(self):
      if self.MDI != None:
          return self.MDI
      return None
    #-------------------------------


def main():
    app = QApplication(sys.argv)  # New instance QApplication
    window = ExampleApp()  # Create instance of ExampleApp
    window.setObjectName("IMASViz root window")
    window.show() 
    sys.exit(app.exec_())  # Start application

if __name__ == '__main__':  # If direct run, not import
    main() 
