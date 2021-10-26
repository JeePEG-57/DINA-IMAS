from pathlib import Path
from PyQt5 import QtWidgets, QtGui, QtCore
from PyQt5.QtWidgets import (QTabWidget, QWidget, QSlider, QFormLayout, QApplication,
                             QMenu, QMainWindow, QDockWidget,QMenuBar,QSizePolicy,
                             QLineEdit, QPushButton, QVBoxLayout, QComboBox,
                             QPlainTextEdit, QGridLayout, QMdiArea, QMdiSubWindow, QTableView, QAction) 
from PyQt5.QtWidgets import QApplication, QMainWindow, QTreeWidget, QTreeWidgetItem, \
                            QWidget, QGridLayout, QVBoxLayout, QLineEdit, \
                            QSlider, QPushButton, QHBoxLayout, QLabel, QMessageBox
import eq_win4
import sys
import math
import imas # UAL library
import matplotlib
matplotlib.use('Qt5Agg')
#matplotlib.use('GTK3Agg')
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar

from matplotlib.figure import Figure
import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches

import numpy as np

#--------------new class for equilibrium window
class Second_window(QtWidgets.QWidget, eq_win4.Ui_Form_eq): #QtGui.QWidget
    def __init__(self, pulse, run, user, base):
        super().__init__()
        self.buildUI()



        imas_entry_init = imas.DBEntry(imas.imasdef.MDSPLUS_BACKEND, base, pulse, run, user, data_version = '3')
        imas_entry_init.open()
        
        self.sum1 = imas_entry_init.get('summary')


        
        
        self.t1 = self.sum1.time
        self.tor = len(self.t1)
        
        #--------------------
        self.matSlider = QSlider()
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.matSlider.sizePolicy().hasHeightForWidth())
        self.matSlider.setSizePolicy(sizePolicy)
        self.matSlider.setOrientation(QtCore.Qt.Horizontal)
        self.matSlider.setRange(0,self.tor-1)
        

        self.matSlider.valueChanged.connect(self.plotty)
        
        self.DrawLegend = False
        self.DrawLimiter = True
        self.DrawLimiterActivePoint = True
        self.DrawBoundary = True
        self.DrawSeparatrix = True
        self.DrawSeparatrix2 = True
        self.DrawPsiInside = True
        self.DrawPsiOutside = True


        
        #--------------------
        
        self.fig = plt.figure()
        self.canvas = FigureCanvas(self.fig)
        self.toolbar = NavigationToolbar(self.canvas, self)
        
        
        self.graplay.addWidget(self.canvas, 0, 0)
        self.graplay.addWidget(self.matSlider, 1, 0) 
        self.graplay.addWidget(self.toolbar, 2, 0) 
        
        
        nrows = 5
        ncols = 2
        
        self.ax_j_profile = plt.subplot(nrows, ncols, 2)
        self.ax_q_profile = plt.subplot(nrows, ncols, 4)
        self.ax_T_profile = plt.subplot(nrows, ncols, 6)
        self.ax_N_profile = plt.subplot(nrows, ncols, 8)
        self.ax_Q_profile = plt.subplot(nrows, ncols, 10)
        self.ax_equil = plt.subplot(1, ncols, 1)
        
        self.canvas.draw()
        
        
        
        self.cp1 = imas_entry_init.get('core_profiles')
        self.cs1 = imas_entry_init.get('core_sources')
        self.eq1 = imas_entry_init.get('equilibrium')
        self.pfa1 = imas_entry_init.get('pf_active')
        self.pfp1 = imas_entry_init.get('pf_passive')
        self.wall = imas_entry_init.get('wall')
        
        
        
        imas_entry_init.close()
        
        self.data_gain()
        
        self.matSlider.setValue(int(self.tor/3))
        self.plotty()
        
        
        
    def data_gain(self):
      
      #self.psi2d_t=[]
      #for i in range(self.tor):
      #  self.psi2d_t.append(self.eq1.time_slice[i].profiles_2d[0].psi.transpose())

      CurrentMax = 0.0
      for loop in self.pfp1.loop:
        Current = max(abs(loop.current))
        CurrentMax = max(CurrentMax, Current)
      self.pfpCurrentMax = CurrentMax
      #print("pf_passive max loop current = " + str(self.pfpCurrentMax))

  
    def GetGeometryPath(self, geom):
      verts = []
      codes = []
      
      if (geom.geometry_type == 2):
        verts = [
          (geom.rectangle.r - 0.5*geom.rectangle.width, geom.rectangle.z - 0.5*geom.rectangle.height),  # left, bottom
          (geom.rectangle.r - 0.5*geom.rectangle.width, geom.rectangle.z + 0.5*geom.rectangle.height),  # left, top
          (geom.rectangle.r + 0.5*geom.rectangle.width, geom.rectangle.z + 0.5*geom.rectangle.height),  # right, top
          (geom.rectangle.r + 0.5*geom.rectangle.width, geom.rectangle.z - 0.5*geom.rectangle.height),  # right, bottom
          (0., 0.),  # ignored
        ]
        codes = [
            Path.MOVETO,
            Path.LINETO,
            Path.LINETO,
            Path.LINETO,
            Path.CLOSEPOLY,
        ]
        
      if (geom.geometry_type == 3):
        verts = [
          (geom.oblique.r, geom.oblique.z),  # left, bottom
          (geom.oblique.r + geom.oblique.length_alpha*math.cos(geom.oblique.alpha),
            geom.oblique.z + geom.oblique.length_alpha*math.sin(geom.oblique.alpha)),  # left, top
          (geom.oblique.r + geom.oblique.length_alpha*math.cos(geom.oblique.alpha) -  geom.oblique.length_beta*math.sin(geom.oblique.beta),
            geom.oblique.z + geom.oblique.length_alpha*math.sin(geom.oblique.alpha) +  geom.oblique.length_beta*math.cos(geom.oblique.beta)),  # right, bottom
          (geom.oblique.r - geom.oblique.length_beta*math.sin(geom.oblique.beta),
            geom.oblique.z + geom.oblique.length_beta*math.cos(geom.oblique.beta)),  # right, top
          (0., 0.),  # ignored
        ]
        codes = [
            Path.MOVETO,
            Path.LINETO,
            Path.LINETO,
            Path.LINETO,
            Path.CLOSEPOLY,
        ]
      
      if (geom.geometry_type == 1):
        n = len(geom.outline.r)
        for i in range(n):
          verts.append((geom.outline.r[i], geom.outline.z[i]))
          codes.append(Path.LINETO)
          
        if (n > 0):
          codes[0] = Path.MOVETO
          
          verts.append((0.0, 0.0))
          codes.append(Path.CLOSEPOLY)
      
      path = Path(verts, codes)
      
      return path
    
    
    def plotty(self):

        it = self.matSlider.value()
    

        
        #fig, axes = plt.subplots(nrows=6, ncols=3, dpi=100, facecolor = 'white')
        #ax1 = plt.subplot2grid((6,3), (0,0))
        #ax1.plot(t2, ipl2)
        #ax1.ylim(ylimdown_ipl,ylimup_ipl)
        #ax1.title ("Ipl(t)")
        #plt.show()
  
        #----------------------------------------PLOT-----------------------------------------------
        #plt.ion()
        #fig = plt.figure()
        
        #plt.text(0.9,0.9,'$time slice %f'%it)
        #a1=fig.add_subplot (6, 3, 1)

        
        ax = self.ax_j_profile
        ax.cla()
        x = self.cp1.profiles_1d[it].grid.rho_tor_norm
        y = self.cp1.profiles_1d[it].j_tor
        y1 = self.cp1.profiles_1d[it].j_bootstrap
        
        ax.plot(x, y, label = "j_tor")
        ax.plot(x, y1, label = "j_btstrp")
        ax.set_xlim([0.0, 1.0])
        ax.set_ylim([min(y)*1.05, 0.0])
        ax.set_title("j, A/m²")
        ax.legend(loc='center left',bbox_to_anchor=(1,0.5))


        ax = self.ax_q_profile
        ax.cla()
        x = self.cp1.profiles_1d[it].grid.rho_tor_norm
        y = self.cp1.profiles_1d[it].q
        
        ax.plot(x, y, 'r-', label="q")
        ax.set_xlim([0.0, 1.0])
        ax.set_ylim([0.0, max(y)*1.05])
        ax.set_title("q")
        ax.legend(loc='center left',bbox_to_anchor=(1,0.5))
    
    
        ax = self.ax_T_profile
        ax.cla()
        x = self.cp1.profiles_1d[it].grid.rho_tor_norm
        y = self.cp1.profiles_1d[it].electrons.temperature
        y1 = self.cp1.profiles_1d[it].t_i_average
        
        ax.plot(x, y, label = "Te")
        ax.plot(x, y1, label = "Ti")

        ax.set_xlim([0.0, 1.0])
        ax.set_ylim([0.0, max(y)*1.05])
        
        ax.set_title ("T, eV")
        ax.legend(loc='center left',bbox_to_anchor=(1,0.5))
  

  
        ax = self.ax_N_profile
        ax.cla()
        x = self.cp1.profiles_1d[it].grid.rho_tor_norm
        
        ideut = 0
        itrit = 1
        
        y = self.cp1.profiles_1d[it].electrons.density
        y1 = self.cp1.profiles_1d[it].ion[ideut].density
        y2 = self.cp1.profiles_1d[it].ion[itrit].density
        
        ax.plot(x, y, label = "Ne")
        ax.plot(x, y1, label = "Nd")
        ax.plot(x, y2, label = "Nt")

        ax.set_xlim([0.0, 1.0])
        ax.set_ylim([0.0, max(y)*1.05])
        
        ax.legend(loc='center left',bbox_to_anchor=(1,0.5))
        ax.set_title("Density, m⁻³")
        
        
        
        
        ax = self.ax_Q_profile
        ax.cla()
        
        isrc = 0
        
        x = self.cs1.source[isrc].profiles_1d[it].grid.rho_tor_norm
        
        y = self.cs1.source[isrc].profiles_1d[it].electrons.energy
        y1 = self.cs1.source[isrc].profiles_1d[it].total_ion_energy
        
        ax.plot(x, y, label = "Qe")
        ax.plot(x, y1, label = "Qi")
        
        ax.set_xlim([0.0, 1.0])
        ax.set_ylim([min(y), max(y)])
        ax.set_title ("Heat sources, W/m³")
        ax.legend(loc='center left',bbox_to_anchor=(1,0.5))
        
        
  
        #EQUILIBRIUM--------------
        ax = self.ax_equil
        ax.cla()
        
        x = self.eq1.time_slice[it].profiles_2d[0].grid.dim1
        y = self.eq1.time_slice[it].profiles_2d[0].grid.dim2
      
        psi2d = np.transpose(self.eq1.time_slice[it].profiles_2d[0].psi)
        
        psi_axis = self.eq1.time_slice[it].global_quantities.psi_axis
        psi_bnd = self.eq1.time_slice[it].boundary.psi
        psi_sep = self.eq1.time_slice[it].boundary_separatrix.psi
        psi_sep2 = self.eq1.time_slice[it].boundary_secondary_separatrix.psi
        
        
        
        if (psi_axis > psi_bnd):
          psi2d = -psi2d
          psi_axis = -psi_axis
          psi_bnd = -psi_bnd
          psi_sep = -psi_sep
          psi_sep2 = -psi_sep2
          
        
        psi_max = np.amax(psi2d)
        #print("psi max = " + str(psi_max))
        
        dsep = self.eq1.time_slice[it].boundary_separatrix.gap[30].value




        if (self.DrawLimiter):
          if (len(self.wall.description_2d) > 0):
            for unit in self.wall.description_2d[0].limiter.unit:
              ax.plot(unit.outline.r, unit.outline.z, 'k-', linewidth=1, label='limiter')
          else:
            print("No wall limiter data")
          
          
        if (self.DrawLimiterActivePoint):
          r = self.eq1.time_slice[it].boundary_separatrix.active_limiter_point.r
          z = self.eq1.time_slice[it].boundary_separatrix.active_limiter_point.z
          ax.plot(r, z, 'rx')


        n_levels = 9
        dpsi = (psi_bnd - psi_axis)/n_levels
        xmax = np.max(self.eq1.time_slice[it].boundary.outline.r)
        xmin = np.min(self.eq1.time_slice[it].boundary.outline.r)
        ymax = np.max(self.eq1.time_slice[it].boundary.outline.z)
        ymin = np.min(self.eq1.time_slice[it].boundary.outline.z)
        i_ymax = -1
        i_ymin = -1
        for i in range(len(y)):
          if (y[i] < ymin):
            i_ymin = i
          if (y[i] < ymax):
            i_ymax = i
            
        if (dpsi > 0.):
          if (self.DrawPsiOutside):
            vmax = psi_max
            vmin = psi_bnd
            levels = np.arange(vmin, vmax, dpsi)
            colors = 'blue'
            psi_ax = ax.contour(x, y, psi2d, levels=levels,
              colors=colors, linewidths=0.5, linestyles='solid')
              
            vmax = psi_bnd
            vmin = psi_axis
            levels = np.arange(vmin, vmax, dpsi)
            psi_ax = ax.contour(x, y[0:i_ymin], psi2d[0:i_ymin][:],
              levels=levels, colors=colors, linewidths=0.5, linestyles='solid')
            psi_ax = ax.contour(x, y[i_ymax:], psi2d[i_ymax:][:],
              levels=levels, colors=colors, linewidths=0.5, linestyles='solid')
          
          if (self.DrawPsiInside):
            vmax = psi_bnd
            vmin = psi_axis
            levels = np.arange(vmin, vmax, dpsi)
            colors = 'red'
            psi_ax = ax.contour(x, y[i_ymin:i_ymax], psi2d[i_ymin:i_ymax][:],
              levels=levels, colors=colors, linewidths=0.5, linestyles='solid')
           
        
        if (self.DrawBoundary):
          psi_sep_ax1 = ax.contour(x, y, psi2d, 
            levels=[psi_bnd], colors=['r'], linewidths=1, linestyles='solid')
          psi_sep_ax1.collections[0].set_label('boundary,    psi=' + "{:.2f}".format(psi_bnd))
        
        if (self.DrawSeparatrix):
          psi_sep_ax1 = ax.contour(x, y, psi2d,
            levels=[psi_sep], colors = ['b'], linewidths=1, linestyles='solid')
          psi_sep_ax1.collections[0].set_label('separatrix,   psi=' + "{:.2f}".format(psi_sep))
        
        if (self.DrawSeparatrix2):
          psi_sep_ax1 = ax.contour(x, y, psi2d,
            levels=[psi_sep2], colors = ['m'], linewidths=1, linestyles='solid')
          psi_sep_ax1.collections[0].set_label('separatrix2, psi=' + "{:.2f}".format(psi_sep2))
        
        
        for coil in self.pfa1.coil:
          for elem in coil.element:
            path = self.GetGeometryPath(elem.geometry)
            patch = patches.PathPatch(path, facecolor='orange', edgecolor='blue', lw=1)
            ax.add_patch(patch)


        CurrentMax = 0.
        for loop in self.pfp1.loop:
          CurrentMax = max(CurrentMax, abs(loop.current[it]))
        for loop in self.pfp1.loop:
          current = loop.current[it]
          
          r = current/CurrentMax
          g = -current/CurrentMax
          b = 0.5
          
          r = np.clip(r,0.,1.)
          g = np.clip(g,0.,1.)
          b = np.clip(b,0.,1.)
          
          for elem in loop.element:
            path = self.GetGeometryPath(elem.geometry)
            patch = patches.PathPatch(path, facecolor=(r, g, b), edgecolor=(r, g, b), lw=1)
            ax.add_patch(patch)


        Time = self.eq1.time_slice[it].time
        Ipl = self.eq1.time_slice[it].global_quantities.ip
        ax.set_title('Equilibrium \n time=%f s, Ip=%f MA'%(Time, Ipl*1.e-6))
        if (self.DrawLegend):
          ax.legend()
        ax.set_aspect('equal', adjustable='box')


        plt.subplots_adjust(wspace=0.2, hspace=0.6)
        self.canvas.draw()


    def buildUI(self):
        super().buildUI(self)
        #plotty()
        
        #self.setWindowTitle('TRY-1-2-3')

def main():
    app = QApplication(sys.argv)  # New instance QApplication
    
    shot = 135013
    run = 1
    user = "dubrovm"
    database = "test"
    
    window = Second_window(shot,run,user,database)
    window.setObjectName("EQUIL_win")
    window.show() 
    sys.exit(app.exec_())  # Start application

if __name__ == '__main__':  # If direct run, not import
    main() 
    