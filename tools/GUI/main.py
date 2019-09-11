
import sys
import os

from PyQt5 import QtWidgets
import design

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
    def __init__(self):
        super().__init__()
        self.setupUi(self)  # Initialise design
        self.initUi()
        
    def initUi(self):
        self.setWindowTitle('DINA GUI')
        
        
        self.btnBrowse.clicked.connect(self.BrowseFolder)
        self.btnSave.clicked.connect(self.SaveSetups)
        
        
        self.CSHeaders = ['CSU3','CSU2','CS1','CSL2','CSL3']
        self.PFHeaders = ['PF1','PF2','PF3','PF4','PF5','PF6']
        self.coilNames = self.CSHeaders + self.PFHeaders
         
        self.directory = ''
      
        #user = os.environ['USER']
        user = os.getenv('USER')
        #workdir = os.environ['KEPLER_DIR']
        print('user is ', user)
        #print('workdir is ', workdir)
      
        self.tableCurrents.itemClicked.connect(self.TableClicked)
        self.tableCurrents.itemSelectionChanged.connect(self.tableCurrentsSelectionChanged)                
        self.dataCurrentsHeaders = ['Time, s', 'Iplasma, MA']
        for i in range(len(self.coilNames)):
          self.dataCurrentsHeaders = self.dataCurrentsHeaders + [self.coilNames[i] + ', MA*t']
        #print(self.dataCurrentsHeaders)  
        self.tableCurrents.setHorizontalHeaderLabels(self.dataCurrentsHeaders)         
        
        
        self.tableVoltages.itemSelectionChanged.connect(self.tableVoltagesSelectionChanged)                       
        self.dataVoltagesHeaders = ['Time, s']
        for i in range(len(self.coilNames)):
          self.dataVoltagesHeaders = self.dataVoltagesHeaders + [self.coilNames[i] + ', V']
        self.tableVoltages.setHorizontalHeaderLabels(self.dataVoltagesHeaders)
        
        
        gridGaps = QtWidgets.QGridLayout()
        
        self.tableGap1.setHorizontalHeaderLabels(['Time, s', 'g1']) 
        gridGaps.addWidget(self.tableGap1, 0, 0)
        self.tableGap1.itemSelectionChanged.connect(self.tableGap1SelectionChanged) 

        self.tableGap2.setHorizontalHeaderLabels(['Time, s', 'g2']) 
        gridGaps.addWidget(self.tableGap2, 0, 1)
        self.tableGap2.itemSelectionChanged.connect(self.tableGap2SelectionChanged)

        self.tableGap3.setHorizontalHeaderLabels(['Time, s', 'g3']) 
        gridGaps.addWidget(self.tableGap3, 0, 2)
        self.tableGap3.itemSelectionChanged.connect(self.tableGap3SelectionChanged)        
        
        self.tableGap4.setHorizontalHeaderLabels(['Time, s', 'g4']) 
        gridGaps.addWidget(self.tableGap4, 0, 3)
        self.tableGap4.itemSelectionChanged.connect(self.tableGap4SelectionChanged) 

        self.tableGap5.setHorizontalHeaderLabels(['Time, s', 'g5']) 
        gridGaps.addWidget(self.tableGap5, 0, 4)
        self.tableGap5.itemSelectionChanged.connect(self.tableGap5SelectionChanged)

        self.tableGap6.setHorizontalHeaderLabels(['Time, s', 'g6'])  
        gridGaps.addWidget(self.tableGap6, 0, 5)
        self.tableGap6.itemSelectionChanged.connect(self.tableGap6SelectionChanged)        
        
        self.tableGap1_term.setHorizontalHeaderLabels(['Time, s', 'g1_term'])  
        gridGaps.addWidget(self.tableGap1_term, 1, 0)
        self.tableGap1_term.itemSelectionChanged.connect(self.tableGap1_termSelectionChanged) 

        self.tableGap2_term.setHorizontalHeaderLabels(['Time, s', 'g2_term']) 
        gridGaps.addWidget(self.tableGap2_term, 1, 1)
        self.tableGap2_term.itemSelectionChanged.connect(self.tableGap2_termSelectionChanged)

        self.tableGap3_term.setHorizontalHeaderLabels(['Time, s', 'g3_term'])  
        gridGaps.addWidget(self.tableGap3_term, 1, 2)
        self.tableGap3_term.itemSelectionChanged.connect(self.tableGap3_termSelectionChanged)        
        
        self.tableGap4_term.setHorizontalHeaderLabels(['Time, s', 'g4_term']) 
        gridGaps.addWidget(self.tableGap4_term, 1, 3)
        self.tableGap4_term.itemSelectionChanged.connect(self.tableGap4_termSelectionChanged) 

        self.tableGap5_term.setHorizontalHeaderLabels(['Time, s', 'g5_term']) 
        gridGaps.addWidget(self.tableGap5_term, 1, 4)
        self.tableGap5_term.itemSelectionChanged.connect(self.tableGap5_termSelectionChanged)

        self.tableGap6_term.setHorizontalHeaderLabels(['Time, s', 'g6_term']) 
        gridGaps.addWidget(self.tableGap6_term, 1, 5)
        self.tableGap6_term.itemSelectionChanged.connect(self.tableGap6_termSelectionChanged)        
        
        self.tableElong.setHorizontalHeaderLabels(['Time, s', 'Elongation'])  
        gridGaps.addWidget(self.tableElong, 0, 6)
        self.tableElong.itemSelectionChanged.connect(self.tableElongSelectionChanged)        
        
        self.tabGaps.setLayout(gridGaps)
        
        
        layoutContr = QtWidgets.QHBoxLayout()
        
        
        self.tableControlMarg.setHorizontalHeaderLabels(['Max Voltage, V', 'Max current, kA']) 
        self.tableControlMarg.setVerticalHeaderLabels(['VVS1', 'VVS3'] + self.coilNames) 
        layoutContr.addWidget(self.tableControlMarg)
        
        self.tableControl1.setVerticalHeaderLabels(['tcont2', 'Ip_div', 'ref_ramp', 'Ip_rd', 'trd_ref', 'Tu, s'])
        layoutContr.addWidget(self.tableControl1)
        
        self.tableControl2.setVerticalHeaderLabels(['c_a_tpl1', 'c_a_tpl1_eob', 'c_a_tpl2', 'c_a_tpl_min', 'y0', 'c1_y0', 'c2_y0'])
        layoutContr.addWidget(self.tableControl2)
        
        self.tabControl.setLayout(layoutContr)
        
        
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
        
        layGr = QtWidgets.QHBoxLayout()
        #layGr.addStretch(1)
        layGr.addWidget(self.gridLayoutWidget_3)
        layGr.addLayout(self.timeTraceGraph.layout)
        
        layout = QtWidgets.QVBoxLayout()
        layout.addLayout(layGr)
        layout.addWidget(self.tabWidgetInput)
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
        
        

    def tableCurrentsSelectionChanged(self):
      self.tableColumnPlot(self.tableCurrents, self.timeTraceGraph)                  
    def tableVoltagesSelectionChanged(self):
      self.tableColumnPlot(self.tableVoltages, self.timeTraceGraph)
      
    def tableGap1SelectionChanged(self):
      self.tableColumnPlot(self.tableGap1, self.timeTraceGraph)
    def tableGap2SelectionChanged(self):
      self.tableColumnPlot(self.tableGap2, self.timeTraceGraph)      
    def tableGap3SelectionChanged(self):
      self.tableColumnPlot(self.tableGap3, self.timeTraceGraph)
    def tableGap4SelectionChanged(self):
      self.tableColumnPlot(self.tableGap4, self.timeTraceGraph)       
    def tableGap5SelectionChanged(self):
      self.tableColumnPlot(self.tableGap5, self.timeTraceGraph)
    def tableGap6SelectionChanged(self):
      self.tableColumnPlot(self.tableGap6, self.timeTraceGraph)  
      
    def tableGap1_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap1_term, self.timeTraceGraph)
    def tableGap2_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap2_term, self.timeTraceGraph)      
    def tableGap3_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap3_term, self.timeTraceGraph)
    def tableGap4_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap4_term, self.timeTraceGraph)       
    def tableGap5_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap5_term, self.timeTraceGraph)
    def tableGap6_termSelectionChanged(self):
      self.tableColumnPlot(self.tableGap6_term, self.timeTraceGraph)       
      
    def tableElongSelectionChanged(self):
      self.tableColumnPlot(self.tableElong, self.timeTraceGraph)      
      
      
    def BrowseFolder(self):
      self.directory = QtWidgets.QFileDialog.getExistingDirectory(self, "Select folder")

      if self.directory: 
        self.labelDir.setText(self.directory)
        self.LoadTimeTable('scr_data.dat', self.tableCurrents)
        self.LoadTimeTable('volt.dat', self.tableVoltages)
        self.LoadTimeTableN('g1.dat', self.tableGap1)
        self.LoadTimeTableN('g2.dat', self.tableGap2)
        self.LoadTimeTableN('g3.dat', self.tableGap3)
        self.LoadTimeTableN('g4.dat', self.tableGap4)
        self.LoadTimeTableN('g5.dat', self.tableGap5)
        self.LoadTimeTableN('g6.dat', self.tableGap6)
        self.LoadTimeTableN('g1_term.dat', self.tableGap1_term)
        self.LoadTimeTableN('g2_term.dat', self.tableGap2_term)
        self.LoadTimeTableN('g3_term.dat', self.tableGap3_term)
        self.LoadTimeTableN('g4_term.dat', self.tableGap4_term)
        self.LoadTimeTableN('g5_term.dat', self.tableGap5_term)
        self.LoadTimeTableN('g6_term.dat', self.tableGap6_term) 
        self.LoadTimeTableN('elong_ref.dat', self.tableElong)
        
        self.LoadControlParameters()
        

    def LoadTimeTable(self, myfile, table):
          filename = self.directory + '/' + myfile  
          if os.path.isfile(filename): 
            f = open(filename, 'rt')
            lines0 = f.read().splitlines()
            f.close()
            
            lines0.pop(0)           
            
            lines1 = []
            for line in lines0:
                sps0 = line.split(' ')
                sps1 = []
                for numb in sps0:
                    if numb != ' ' and numb != '':
                        sps1.append(numb)                      
                lines1.append(sps1)
                       
            data = []
            n = len(lines1)
            for i in range(n):
              a = []
              m = len(lines1[i])
              for j in range(m):
                a.append(float(lines1[i][j]))
              data.append(a)


            table.setColumnCount(m) 
            table.setRowCount(n) 
                        
                       
            for i in range(len(data)):
              for j in range(len(data[i])):
                table.setItem(i, j, QtWidgets.QTableWidgetItem(str(data[i][j])))

            table.resizeColumnsToContents() 
                       

    def LoadTimeTableN(self, myfile, table):
          filename = self.directory + '/' + myfile  
          if os.path.isfile(filename): 
            f = open(filename, 'rt')
            lines0 = f.read().splitlines()
            f.close()
            
            lines0.pop(0)           
            
            nt = lines0.pop(0)
            #print(myfile, 'nt =', nt)
            lines0.pop(0)
                   
            lines1 = []
            for line in lines0:
                sps0 = line.split(' ')
                sps1 = []
                for numb in sps0:
                    if numb != ' ' and numb != '':
                        sps1.append(numb)                      
                lines1.append(sps1)
                       
            data = []
            n = len(lines1)
            for i in range(n):
              a = []
              m = len(lines1[i])
              for j in range(m):
                a.append(float(lines1[i][j]))
              data.append(a)


            table.setColumnCount(m) 
            table.setRowCount(n) 
                        
                       
            for i in range(len(data)):
              for j in range(len(data[i])):
                table.setItem(i, j, QtWidgets.QTableWidgetItem(str(data[i][j])))

            table.resizeColumnsToContents()       


    def LoadControlParameters(self):
          myfile = 'control_data.dat'
          filename = self.directory + '/' + myfile  
          if os.path.isfile(filename): 
            f = open(filename, 'rt')
            lines0 = f.read().splitlines()
            f.close()
            
            lines0.pop(0)           
            lines0.pop(1)
                   
            lines1 = []
            for line in lines0:
                sps0 = line.split(' ')
                sps1 = []
                for numb in sps0:
                    if numb != ' ' and numb != '':
                        sps1.append(numb)                      
                lines1.append(sps1)
                       
            data1 = []
            m = len(lines1[0])
            for j in range(m):
              data1.append(float(lines1[0][j]))

            data2 = []
            m = len(lines1[1])
            for j in range(m):
              data2.append(float(lines1[1][j]))              
             
            for j in range(len(data1)-1):
              self.tableControlMarg.setItem(j, 0, QtWidgets.QTableWidgetItem(str(data1[j])))
            for j in range(len(data2)):
              self.tableControlMarg.setItem(j+1, 1, QtWidgets.QTableWidgetItem(str(data2[j])))

            self.tableControlMarg.resizeColumnsToContents()
            
            
          myfile = 'control_data2.dat'
          filename = self.directory + '/' + myfile  
          if os.path.isfile(filename): 
            f = open(filename, 'rt')
            lines0 = f.read().splitlines()
            f.close()
            
            lines0.pop(0)           
            lines0.pop(1)
                   
            lines1 = []
            for line in lines0:
                sps0 = line.split(' ')
                sps1 = []
                for numb in sps0:
                    if numb != ' ' and numb != '':
                        sps1.append(numb)                      
                lines1.append(sps1)
                       

            data3 = []
            m = len(lines1[0])
            for j in range(m):
              data3.append(float(lines1[0][j]))
            data3.append(data1[-1])  

            data4 = []
            m = len(lines1[1])
            for j in range(m):
              data4.append(float(lines1[1][j]))              
             
            for j in range(len(data3)):
              self.tableControl1.setItem(j, 0, QtWidgets.QTableWidgetItem(str(data3[j])))

            self.tableControl1.resizeColumnsToContents() 
            
            for j in range(len(data4)):
              self.tableControl2.setItem(j, 0, QtWidgets.QTableWidgetItem(str(data4[j])))

            self.tableControl2.resizeColumnsToContents()            
            
            
            


    def SaveSetups(self): 
      if self.directory:
        self.SaveTimeTable('scr_data.dat', self.tableCurrents)
        self.SaveTimeTable('volt.dat', self.tableVoltages)
        self.SaveTimeTableN('g1.dat', self.tableGap1)
        self.SaveTimeTableN('g2.dat', self.tableGap2)
        self.SaveTimeTableN('g3.dat', self.tableGap3)
        self.SaveTimeTableN('g4.dat', self.tableGap4)
        self.SaveTimeTableN('g5.dat', self.tableGap5)
        self.SaveTimeTableN('g6.dat', self.tableGap6)
        self.SaveTimeTableN('g1_term.dat', self.tableGap1_term)
        self.SaveTimeTableN('g2_term.dat', self.tableGap2_term)
        self.SaveTimeTableN('g3_term.dat', self.tableGap3_term)
        self.SaveTimeTableN('g4_term.dat', self.tableGap4_term)
        self.SaveTimeTableN('g5_term.dat', self.tableGap5_term)
        self.SaveTimeTableN('g6_term.dat', self.tableGap6_term) 
        self.SaveTimeTableN('elong_ref.dat', self.tableElong)
        

    def SaveTimeTable(self, myfile, table): 
        currentsFile = self.directory + '/' + myfile
        f = open(currentsFile, 'wt')
            
        n = table.rowCount()
        m = table.columnCount()
        
        for col in range(m):
          f.write(table.horizontalHeaderItem(col).text() + '  ')
        f.write('\n')        
        
      
        for i in range(n):
          for j in range(m):
            d = float(table.item(i,j).text())
          
            f.write('   ' + '{0:10e}'.format(d))
          f.write('\n')
      
        f.close()


    def SaveTimeTableN(self, myfile, table): 
        currentsFile = self.directory + '/' + myfile
        f = open(currentsFile, 'wt')
            
        n = table.rowCount()
        m = table.columnCount()
        
        f.write('ktime\n')
        f.write('{0:4d}'.format(n))
        f.write('\n')    
        
        for col in range(m):
          f.write(table.horizontalHeaderItem(col).text() + '  ')
        f.write('\n')        
              
        for i in range(n):
          for j in range(m):
            d = float(table.item(i,j).text())
          
            f.write('   ' + '{0:10e}'.format(d))
          f.write('\n')
      
        f.close()
        

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
    window = ExampleApp()  # Create instance of ExampleApp
    window.show() 
    sys.exit(app.exec_())  # Start application

if __name__ == '__main__':  # If direct run, not import
    main() 
