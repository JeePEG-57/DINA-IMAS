
import sys
import os
import shutil

from PyQt5 import QtWidgets, QtGui
import design
import captions

import numpy
import random

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar

from matplotlib.figure import Figure
import matplotlib.pyplot as plt
 
import imas # UAL library


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


class ExampleApp(QtWidgets.QMainWindow, design.Ui_MainWindow):
    def __init__(self, app):
        super().__init__()
        
        screen_resolution = app.desktop().screenGeometry()
        width, height = screen_resolution.width(), screen_resolution.height()
        print("width = " + str(width), "height = " + str(height))
        self.setupUi()  # Initialise design
        self.resize(width*1.0, height*1.0)
        
    def initTableOfParameters(self, table, headers):
        nCol = len(headers)
        table.setRowCount(nCol)
        table.setVerticalHeaderLabels(headers)
        for i in range(nCol):
            table.verticalHeaderItem(i).setToolTip(captions.tooltip[headers[i]])
        
        
    def setupUi(self):
        super().setupUi(self)
        
        self.setWindowTitle('DINA GUI')
                
        
        self.directoryLoad = os.path.normpath(os.getcwd() + '/../../machines/iter/')
        self.directorySave = os.getenv('KEPLER')
        self.labelDirLoad.setText(self.directoryLoad)
        self.labelDirSave.setText(self.directorySave)
        
        self.btnLoad.clicked.connect(self.LoadSetups)
        self.btnSave.clicked.connect(self.SaveSetups)
        
        
        
        self.externalData = []
        self.controlData = []
        self.generalData = []
        self.DINAData = []
        
        
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
     
   
    def ReadTabData(self, data, parentObject):
      params = self.ReadParameters(f)
      data.append(params)
      self.CreateInputTab(parentObject, [params], params["title"])
      return data



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
      
      
      # Table for circuit resistivities  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1)
      
      n = len(record["resist"]["items"])
      m = 1
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(["Circuit Resistivity"])      
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
      
      
      # Table for circuit resistivities  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1)
      
      n = len(record["resist"]["items"])
      m = 1
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(["Circuit Resistivity"])      
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
      
      n = len(record["items_r"])
      
      headerNames = [str(i+1) for i in range(n)]
      headerParameters = ["R", "Z", "Angle", "Length"]      
      
      m = 4
      
      table.setRowCount(n)
      table.setColumnCount(m)
      table.setHorizontalHeaderLabels(headerParameters)      
      table.setVerticalHeaderLabels(headerNames)
      for i in range(n):
        table.setItem(i, 0, record["items_r"][i])
        table.setItem(i, 1, record["items_z"][i])
        table.setItem(i, 2, record["items_a"][i])
        table.setItem(i, 3, record["items_l"][i])
        table.resizeColumnsToContents()
        table.itemSelectionChanged.connect(lambda x=table:self.tableCoilsEdited(x)) 

      
      
      # Table for subdivisions data  
      table = QtWidgets.QTableWidget(tab)
      table.setDragEnabled(False)
      table.setDragDropMode(QtWidgets.QAbstractItemView.NoDragDrop)
      grid.addWidget(table, 0, 1, 1, 1)      
      table.setRowCount(1)
      table.setColumnCount(1)
      table.setItem(0, 0, record["common"]["items"][1])
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
        elif datarow["type"] == "params" or datarow["type"] == "paramsrow":
          m = len(datarow["items"])
          table.setColumnCount(m)
          table.setRowCount(1)
          table.setHorizontalHeaderLabels(datarow["names"])      
          for j in range(m):
            table.setItem(0, j, datarow["items"][j])
             
        table.resizeColumnsToContents()
         
      
    def LoadSetups(self):
      dirTmp = QtWidgets.QFileDialog.getExistingDirectory(self, "Select folder load from...", self.directoryLoad)
      #dirTmp = os.path.normpath(os.getcwd() + '/../../machines/iter/15MA_40ka')

      if dirTmp: 
        self.directoryLoad = dirTmp
        self.labelDirLoad.setText(self.directoryLoad)
        
        self.tabInputs = []
        
        self.LoadExternalData()
        self.LoadControlData()
        self.LoadGeneralData()
        self.LoadDINAData()
       
        
        
    def LoadExternalData(self):
      filename = self.directoryLoad + '/external_data.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        self.externalData = []
        parentObject = self.tabExternalDataChild
        parentObject.clear()
    
    

        params = self.ReadParameters(f)
        self.externalData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        params = self.ReadParametersSet(f, 2)
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
      filename = self.directoryLoad + '/control_init.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        self.controlData = []
        parentObject = self.tabControlDataChild
        parentObject.clear()


        params = self.ReadParametersSet(f, 2)
        self.controlData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])
        
        
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])


        #elong.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])


        #g1.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])

        #g1_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])        
        
        
        #g2.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #g2_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])        
        
        
        #g3.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #g3_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])       
        
        
        #g4.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #g4_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])        
        
        
        #g5.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #g5_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])        
        
                
        #g6.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #g6_term.dat
        timedData = self.ReadTimeTable(f)
        self.controlData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])        
        
        
        
        params = self.ReadParametersSet(f, 2)
        self.controlData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])
        
        
        # number of coil turns
        params = self.ReadParameters(f)
        self.controlData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"]) 
        
        
        
        #consist = setOfParams["data"] + [timedData]
        #self.CreateInputTab(parentObject, consist, "together")
        
                               
        
        f.close()
        
        #print('Control data:')
        #for x in self.controlData:
        #  print(x)
        #print(self.controlData) 
 

    def LoadGeneralData(self):
      filename = self.directoryLoad + '/general_data.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        self.generalData = []
        parentObject = self.tabGeneralDataChild
        parentObject.clear()
        

        #scr_data.dat
        timedData = self.ReadTimeTable(f)
        self.generalData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 
 
 
        params = self.ReadParametersSet(f, 3)
        self.generalData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])
        
        
        f.close()
        
        
        
    def LoadDINAData(self):
      filename = self.directoryLoad + '/dina_data.dat'
      if os.path.isfile(filename):
        f = open(filename, 'rt')
        
        self.DINAData = []       
        parentObject = self.tabDINADataChild
        parentObject.clear()
        
        
        # tokamakdata.dat
        params = self.ReadTokamakConfig(f)
        self.DINAData.append(params)
        
        # k_jetto.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
               
        # time_eq.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        # jetto_ids.dat
        params = self.ReadParametersSet(f, 2)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])        
        
        # kpr.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        # for002_kav.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        # gaps_data_ramp
        params = self.ReadParametersSet(f, 3)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, params["data"], params["title"])        
                
        # tran_times.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])        
        
        #pfres.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 
 
        #ech.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 
 
        #n_d.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])  
 
        #gamma_z.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 
 
        #gamma_z2.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 

        # init.dat
        params = self.ReadParametersRow(f, 5)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        #emo.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
        
        #dens.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"]) 
 
        #gamma_z1.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])
 
        #gamma_z3.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])

        #gamma_z4.dat
        timedData = self.ReadTimeTable(f)
        self.DINAData.append(timedData)
        self.CreateInputTab(parentObject, [timedData], timedData["title"])

        # bohm_gbohm.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])

        # tay_simul.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])

        # dw.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        # pcchp_end.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])
        
        # transp_ext.dat
        params = self.ReadParameters(f)
        self.DINAData.append(params)
        self.CreateInputTab(parentObject, [params], params["title"])        
        
        f.close()
        
   
    
    def ReadCoilData(self, f):
      output = {}      
      output["type"] = "coil"
      
      output["name"] = f.readline().rstrip()
      
      props = self.ReadRowStr(f)
      if len(props) != 4:
        print("Incorrect properties amount: " + str(len(props)))
      output["items_p"] = [QtWidgets.QTableWidgetItem(x) for x in props]
      
      geometry = self.ReadRowStr(f)
      if len(geometry) != 6:
        print("Incorrect geometry items amount: " + str(len(geometry)))     
      output["items_g"] = [QtWidgets.QTableWidgetItem(x) for x in geometry]
      return output



    def ReadResistivityData(self, f, n):
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
      parentObject = self.tabTokamakDataChild
      parentObject.clear()
      output = {}
      
      
      # Coils
      record = {}
      data = []
      NPF = self.ReadParameters(f)
      record["common_geom"] = NPF     
      npf = NPF["data"][0]
      print("npf = " + str(npf))     
      for i in range(npf):
        data.append(self.ReadCoilData(f))
      record["geometry"] = data
      
      # Coil resistivities
      data = []
      NPF = self.ReadParameters(f)
      record["common_res"] = NPF     
      npf = NPF["data"][0]
      print("npf res = " + str(npf))               
      record["resist"] = self.ReadResistivityData(f, npf) 
      
      output["coils"] = record
      
      
      # Vessel
      record = {}
      data = []
      NCAM = self.ReadParameters(f)
      record["common_geom"] = NCAM     
      ncam = NCAM["data"][0]
      print("ncam = " + str(ncam))     
      for i in range(ncam):
        data.append(self.ReadCoilData(f))
      record["geometry"] = data 
       
      # Vessel resistivities
      NCAM = self.ReadParameters(f)
      record["common_res"] = NCAM     
      ncam = NCAM["data"][0]
      print("ncam res = " + str(ncam))      
      record["resist"] = self.ReadResistivityData(f, ncam)     
      
      output["vessel"] = record
      
      
      # Loops
      record = {}
      NLOOP = self.ReadParameters(f)
      record["common"] = NLOOP     
      nloop = NLOOP["data"][0]
      print("nloop = " + str(nloop))        
      loopR = []
      loopZ = []
      for i in range(nloop):
        line = self.ReadRow(f)
        loopR.append(line[0])
        loopZ.append(line[1])         
      record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in loopR] 
      record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in loopZ] 
      output["loops"] = record
      
      
      # Probes
      record = {}
      NPROB = self.ReadParameters(f)
      record["common"] = NPROB      
      nprob = NPROB["data"][0]
      print("nprob = " + str(nprob))     
      probR = []
      probZ = []
      probA = []
      probL = []
      for i in range(nprob):
        line = self.ReadRow(f)
        probR.append(line[0])
        probZ.append(line[1])    
        probA.append(line[2])
        probL.append(line[3]) 
      record["items_r"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probR] 
      record["items_z"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probZ] 
      record["items_a"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probA] 
      record["items_l"] = [QtWidgets.QTableWidgetItem(str(x)) for x in probL] 
      output["probes"] = record
      
      
      # Limiter
      record = {}
      NLIM = self.ReadParameters(f)
      record["common"] = NLIM     
      nlim = NLIM["data"][0]
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
      
      self.CreateInputTabCoils(parentObject, output)
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
      nloop = len(recsave["items_r"])
      for i in range(nloop):
        s1 = recsave["items_r"][i].text()
        s2 = recsave["items_z"][i].text()
        f.write("  " + s1 + "  " + s2 + "\n")
      
      
      # Probes
      recsave = record["probes"]
      self.SaveFilePart(f, recsave["common"])
      nprobes = len(recsave["items_r"])
      for i in range(nprobes):
        s1 = recsave["items_r"][i].text()
        s2 = recsave["items_z"][i].text()
        s3 = recsave["items_a"][i].text()
        s4 = recsave["items_l"][i].text()
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
            
        elif record["type"] == "tokamakdata":
          self.SaveTokamakConfig(f, record)
        
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

 
 
    def GetStuctWithFieldValue(self, record, field, value):
      for item in record:
        if field in item:
          if item[field] == value:
            return item
      print("item does not found")    
      return []  
   
   

    def ReadParametersRow(self, f, nrows):
      output = {}
      output["type"] = "paramsrow"
      data = []
      names = []
      
      for i in range(nrows):
        line = f.readline().rstrip()
        if i == 0:
          header = line.split("!")
          if len(header) > 1:
            output["title"] = header[1].strip()
            line = header[0]
        description = line.split()
        data.append(float(description[0]))
        names.append(description[1])
      output["names"] = names
      output["data"] = data
      output["items"] = [QtWidgets.QTableWidgetItem(str(x)) for x in data]
      return output      
      

       
    def ReadParameters(self, f):     
      output = {}
      output["type"] = "params"
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
      if len(header) > 1:
        output["title"] = header[1].strip()
           
      data = self.ReadRow(f)    
      print(data)
      
      output["names"] = names
      output["data"] = data 
      output["items"] = [QtWidgets.QTableWidgetItem(str(x)) for x in data]
      return output
    
    
    
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
 

    def SaveInputIDS(self):
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
      
      
      pulse = int(pulseText)
      run = int(runText)  
        
      user = os.getenv('USER')
      tokamakname = self.lineInputTokamak.text()
      
      for rec in self.DINAData:
        if rec["type"] == "tokamakdata":
          tokamakdata = rec
      
      if tokamakdata:
        print("pfa get()")  
      
      
      imas_obj1 = imas.ids(pulse, run)
      imas_obj1.create_env(user, tokamakname, '3')  
      
      
      
      pfa1 = imas_obj1.pf_active     
      pfa1.get()      
      pfa1.ids_properties.homogeneous_time = 1
      pfa1.time.resize(1)


      #npf = len(tokamakdata["coils"]["geometry"])
      
      npfa = 12
      
      pfa1.coil.resize(npfa)
      
      #rrr = pfa1.coil.dtype()
      rrr = type(pfa1.coil[0])
      print("Coil type = " + rrr.__name__)
      ggg = rrr()
      
      ncircuit = 0
      for coil in tokamakdata["coils"]["geometry"]:
        ncircuit = max(ncircuit, int(coil["items_p"][3].text()))
      
      print("ncircuit = " + str(ncircuit))
      
      turndata = self.GetStuctWithFieldValue(self.controlData, "title", "n_turn")
      
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
            
            pfa1.coil[i].element[ie].geometry.geometry_type = 3
            pfa1.coil[i].element[ie].geometry.oblique.r = float(coil["items_g"][0].text())
            pfa1.coil[i].element[ie].geometry.oblique.z = float(coil["items_g"][1].text())
            pfa1.coil[i].element[ie].geometry.oblique.length = float(coil["items_g"][2].text())
            pfa1.coil[i].element[ie].geometry.oblique.thickness = float(coil["items_g"][3].text())
            pfa1.coil[i].element[ie].geometry.oblique.alpha = float(coil["items_g"][4].text())
            pfa1.coil[i].element[ie].geometry.oblique.beta = float(coil["items_g"][5].text())
            
            pfa1.coil[i].element[ie].turns_with_sign = float(coil["items_p"][2].text())*float(turndata["items"][i].text())
            print(str(pfa1.coil[i].element[ie].turns_with_sign))
            
            pfa1.coil[i].name += coil["name"]
        
        print("Coil" + str(i) + ":" + pfa1.coil[i].name)
        pfa1.coil[i].resistance = float(tokamakdata["coils"]["resist"]["items"][i].text())

        pfa1.coil[i].current.data.resize(1)
        pfa1.coil[i].voltage.data.resize(1)

      pfa1.coil[2].name = "CS1"
      pfa1.coil[11].name = "VS3"
        
           
      pfa1.put()
      
      pfp1 = imas_obj1.pf_passive     
      pfp1.get()      
      pfp1.ids_properties.homogeneous_time = 1
      pfp1.time.resize(1)
      
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
            
            pfp1.loop[iloop].element[ie].geometry.geometry_type = 3
            pfp1.loop[iloop].element[ie].geometry.oblique.r = float(coil["items_g"][0].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.z = float(coil["items_g"][1].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.length = float(coil["items_g"][2].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.thickness = float(coil["items_g"][3].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.alpha = float(coil["items_g"][4].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.beta = float(coil["items_g"][5].text())            
      
            pfp1.loop[iloop].element[ie].turns_with_sign = float(coil["items_p"][2].text())
      
            pfp1.loop[iloop].name += coil["name"]
            
            pfp1.loop[iloop].current.resize(1)

        pfp1.loop[iloop].resistance = float(tokamakdata["coils"]["resist"]["items"][i].text())           
        print("Passive " + str(iloop) + " name = " + pfp1.loop[iloop].name)

           
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
            
            pfp1.loop[iloop].element[ie].geometry.geometry_type = 3
            pfp1.loop[iloop].element[ie].geometry.oblique.r = float(cam["items_g"][0].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.z = float(cam["items_g"][1].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.length = float(cam["items_g"][2].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.thickness = float(cam["items_g"][3].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.alpha = float(cam["items_g"][4].text())
            pfp1.loop[iloop].element[ie].geometry.oblique.beta = float(cam["items_g"][5].text()) 
            
            pfp1.loop[iloop].element[ie].turns_with_sign = float(cam["items_p"][2].text())
                       
            pfp1.loop[iloop].name += cam["name"]
            
            pfp1.loop[iloop].current.resize(1)

        pfp1.loop[iloop].resistance = float(tokamakdata["vessel"]["resist"]["items"][i].text())            
        print("Passive " + str(iloop) + " name = " + pfp1.loop[iloop].name)      
      
      
      pfp1.put()
      
      imas_obj1.close()




    def SaveSetups(self): 
      dirTmp = QtWidgets.QFileDialog.getExistingDirectory(self, "Select folder save into...", self.directorySave)
      #dirTmp = self.directoryLoad + '/temp'

      if dirTmp:
        self.directorySave = dirTmp
        self.labelDirSave.setText(self.directorySave)
        
        
        self.SaveDataToFile(self.externalData, self.directorySave + '/external_data.dat')
        self.SaveDataToFile(self.controlData, self.directorySave + '/control_init.dat')
        self.SaveDataToFile(self.generalData, self.directorySave + '/general_data.dat')
        self.SaveDataToFile(self.DINAData, self.directorySave + '/dina_data.dat')
        
        new_imp = self.directorySave + '/imp'
        if os.path.exists(new_imp):
          shutil.rmtree(new_imp)
        shutil.copytree(self.directoryLoad + '/imp', new_imp)
        
        self.SaveInputIDS()
        
 

    def PlotOutput(self):
      
        pulse = int(self.textPulse.toPlainText(), 10)
        run = int(self.textRun.toPlainText(), 10)
        user = self.textUser.toPlainText()
        print('selected pulse = ', pulse)
        print('selected run = ', run)

        
        imas_obj1 = imas.ids(pulse, run)
        imas_obj1.open_env(user, 'test', '3')
        
        sum1 = imas_obj1.summary
        cp1 = imas_obj1.core_profiles
        eq1 = imas_obj1.equilibrium
        
        sum1.get()
        cp1.get()
        eq1.get()
        
        imas_obj1.close()
        
        
        t1 = sum1.time
        ipl1 = sum1.global_quantities.ip.value
        li_3 = sum1.global_quantities.li.value
        beta_pol = sum1.global_quantities.beta_pol.value
        n_e = sum1.volume_average.n_e.value
        t_e = sum1.volume_average.t_e.value
        t_i = sum1.volume_average.t_i_average.value
        z_eff = sum1.volume_average.zeff.value

        #li_3 = eq1.time_slice[:].global_quantities.li_3;

        
        self.outpGraph[0].Plot(t1, ipl1, 'I_pl, A')
        self.outpGraph[1].Plot(t1, n_e, 'N_e, A')
        self.outpGraph[2].Plot(t1, t_e, 'T_e, eV')
        self.outpGraph[3].Plot(t1, t_i, 'T_i, eV')
        self.outpGraph[4].Plot(t1, li_3, 'li_3')



def main():
    app = QtWidgets.QApplication(sys.argv)  # New instance QApplication
    window = ExampleApp(app)  # Create instance of ExampleApp
    window.show() 
    sys.exit(app.exec_())  # Start application

if __name__ == '__main__':  # If direct run, not import
    main() 
