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
import math
import imas # UAL library
import matplotlib
matplotlib.use('Qt5Agg')
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.backends.backend_qt5agg import NavigationToolbar2QT as NavigationToolbar

from matplotlib.figure import Figure
import matplotlib.pyplot as plt

import numpy as np

#--------------new class for equilibrium window
class Second_window(QtWidgets.QWidget, eq_win4.Ui_Form_eq): #QtGui.QWidget
    def __init__(self, pulse, run, user, base, isum1, icp1, ieq1):
        super().__init__()
        self.buildUI()


        
        imas_obj1 = imas.ids(pulse, run)
        imas_obj1.open_env(user, base, '3')

        self.sum1 = isum1
        self.cp1 = icp1
        self.eq1 = ieq1
        self.pfa1 = imas_obj1.pf_active
        self.pfp1 = imas_obj1.pf_passive
        self.wall = imas_obj1.wall

        self.pfa1.get()
        self.pfp1.get()
        self.wall.get()   
           
        imas_obj1.close()
        
        self.t1 = self.sum1.time
        self.t2 = self.eq1.time
        self.tor = len(self.t2)
        #--------------------
        self.matSlider = QSlider()
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.matSlider.sizePolicy().hasHeightForWidth())
        self.matSlider.setSizePolicy(sizePolicy)
        self.matSlider.setOrientation(QtCore.Qt.Horizontal)
        self.matSlider.setRange(0,self.tor-1)
        self.matSlider.setValue(14)
        

        self.matSlider.valueChanged.connect(self.plotty)

        
        #--------------------
        self.data_gain()
        self.fig = plt.figure()
        self.canavas = FigureCanvas(self.fig)
        self.toolbar = NavigationToolbar(self.canavas, self)
        self.plotty()


#-------------------------------------fdfdsdf
        
        
        self.graplay.addWidget(self.canavas, 0, 0)
        self.graplay.addWidget(self.matSlider, 1, 0) 
        self.graplay.addWidget(self.toolbar, 2, 0) 
        
    
#0--------------------------------------------------------------------------------------------------------------------EQUIL GRAPH-------------------------------------------------   

    def data_gain(self):

        
         
        #-----------------------------data filling for plotting---------------------------------------        
        

        #plasma current----------------------------  
        self.ipl2 =[]								#1 alternate
        for i in range(self.tor):
            self.ipl2.append(self.eq1.time_slice[i].global_quantities.ip)
        self.li_3 = self.sum1.global_quantities.li.value				#7
 
        #electron density-------------------------
        self.n_e = []								#15
        for i in range(self.tor):
            self.n_e.append(self.cp1.profiles_1d[i].electrons.density)

        #electron temperature---------------------
        self.t_e = []					#9
        for i in range(self.tor):
            self.t_e.append(self.cp1.profiles_1d[i].electrons.temperature)

        #ion temperature--------------------------
        self.t_i =[]				#12
        for i in range(self.tor):
            self.t_i.append(self.cp1.profiles_1d[i].t_i_average)

        #q95% and q_axis--------------------------------------
        self.q_95=[]								#4
        for i in range(self.tor):
            self.q_95.append(self.eq1.time_slice[i].global_quantities.q_95)
        self.q_axis=[]								#4
        for i in range(self.tor):
            self.q_axis.append(self.eq1.time_slice[i].global_quantities.q_axis)

        #ne nuzhno----------------------------------------

        #j_tor ----------------------------------------------
        self.j_tor=[]
        for i in range(self.tor):
            self.j_tor.append(self.cp1.profiles_1d[i].j_tor)					#3


        #eto koordinata X dlya profiles_1d--------------------------
        self.rho_tor=[]
        for i in range(self.tor):
            self.rho_tor.append(self.cp1.profiles_1d[i].grid.rho_tor_norm)


        #q profiles_1d------------------------------------------
        self.q=[]
        for i in range(self.tor):
            self.q.append(self.cp1.profiles_1d[i].q)
      
        #bootstrap profiles_1d-----------------------------------
        self.bstrap=[]
        for i in range(self.tor):
            self.bstrap.append(self.cp1.profiles_1d[i].j_bootstrap)


        #fusion power  ----------------------------------------------
        self.fpow=self.sum1.fusion.power.value
    

        #R_x for limiter--(now its also TAU-Energy)------------------------------------------
        self.r_x=[]								#4
        for i in range(self.tor):
            self.r_x.append(self.eq1.time_slice[i].boundary_separatrix.active_limiter_point.r)
            
        self.tau_e=[]								#4
        #for i in range(self.tor):
        self.tau_e=self.sum1.global_quantities.tau_energy.value

        #R_z for limiter--------------------------------------------------------  
        self.z_x=[]								#4
        for i in range(self.tor):
            self.z_x.append(self.eq1.time_slice[i].boundary_separatrix.active_limiter_point.z)
  
        #------------------------------EQUIL----------------------------------------------------
        
        self.psi_sep=[]
        self.psi_sep=self.eq1.time_slice[10].boundary_separatrix.psi

        #2 -d profiles--------------------------------------------------------------------------
        #ACTIVE zone(changed)
        self.axy=[]
        self.axx=[]
        self.psi2d=[]
        self.psi2d=self.eq1.time_slice[25].profiles_2d[0].psi
        self.pmag=[]
        self.pbound=[]
        self.psi2d_t=[]
        self.psi_sep_t=[]

        self.gran_r=[]
        self.gran_z=[]
        self.test_gran2d=[]
        self.axx=self.eq1.time_slice[25].profiles_2d[0].grid.dim1
        self.axy=self.eq1.time_slice[25].profiles_2d[0].grid.dim2
        for i  in range(self.tor):
          j0 = len(self.eq1.time_slice[i].boundary.outline.r)
          for j in range(len(self.eq1.time_slice[i].boundary.outline.r)):
              if self.eq1.time_slice[i].boundary.outline.r[j]==0.0:
     
                j0=j
         
                break
          self.gran_r.append(self.eq1.time_slice[i].boundary.outline.r[0:j0-1])
          self.gran_z.append(self.eq1.time_slice[i].boundary.outline.z[0:j0-1])

        for i  in range(self.tor):
            self.psi2d_t.append(self.eq1.time_slice[i].profiles_2d[0].psi.transpose())
            self.psi_sep_t.append(self.eq1.time_slice[i].boundary_separatrix.psi)
            self.pmag.append(self.eq1.time_slice[i].global_quantities.psi_axis)
            self.pbound.append(self.eq1.time_slice[i].global_quantities.psi_boundary)

        if self.pmag != self.pbound:
            self.p_s = self.pbound
            self.delaval=[]
            self.n_g=20
            self.d1=[]
            for i in range(self.tor):
                self.delaval.append(self.pmag[i]-self.pbound[i])
                self.d1.append(self.delaval[i]/self.n_g)
      

            self.avalb=self.pmag
            self.PL = []
            for j in range(0,self.n_g+19):
                for i in range(self.tor):
                    self.avalb.append(self.avalb[i]-self.d1[i])
                self.PL.append(self.avalb)
      
      
        #PASSIVE zone(not changed)
        self.limiterx=[]
        self.limitery=[]
        self.factx=[]
        self.facty=[]
        self.tor_geom=56
        #for i in range(tor):
        
        #print("Wall data")
        #print(len(self.wall.description_2d))
        #print(len(self.wall.description_2d[0].limiter.unit))
        #print(len(self.wall.description_2d[0].limiter.unit[0].outline.r))
        if (len(self.wall.description_2d) > 0):
          self.limiterx.append(self.wall.description_2d[0].limiter.unit[0].outline.r[:])
          self.limitery.append(self.wall.description_2d[0].limiter.unit[0].outline.z[:])
        else:
          print("No wall limiter data")
        
        for i in range(len(self.pfa1.coil)):
            for j in range(len(self.pfa1.coil[0].element)):
                self.factx.append(self.pfa1.coil[i].element[j].geometry.outline.r)
 	  
                self.facty.append(self.pfa1.coil[i].element[j].geometry.outline.z)

  
        #params to plot profiles_1d
   
        b=332
        #x = np.logspace(0, 1, 10)
  
        #----------------------------------------SET_AXIS_LIMITS-------------------------------------\
        #-Ipl- one axis - y
        self.ylimup_ipl=max(self.ipl2)*1.1
        self.ylimdown_ipl=min(self.ipl2)*0.9
    
        #q95 and q_axis limits one axis - y
        self.ylimup_q95=(max(self.q_95))*1.1
        self.ylimdown_q_95=min((self.q_95))*0.9
        self.ylimup_q_axis=(max(self.q_axis))*1.1
        self.ylimdown_q_axis=(min(self.q_axis))*0.9
        if self.ylimup_q95 >= self.ylimup_q_axis:
            self.ylimup_q_q = self.ylimup_q95
        else:
            self.ylimup_q_q = self.ylimup_q_axis
        if self.ylimdown_q_95 >= self.ylimdown_q_axis:
            self.ylimdown_q_q = self.ylimdown_q_95
        else:
            self.ylimdown_q_q = self.ylimdown_q_axis
   
        # li(3), fus.pow., Rx and Zx dont need (like ipl and q_95_axis, just for training)
   
        #1-d plots axis limits--------------------------------------------------------
        #-----------x_LIMITS---------
        self.xlimup_rho_tor=[]
        self.xlimdown_rho_tor=[]
        self.ylimup_j_tor=[]
        self.ylimdown_j_tor=[]
        self.ylimup_q=[]
        self.ylimdown_q=[]
        self.ylimup_t_e=[]
        self.ylimdown_t_e=[]
        self.ylimup_t_i=[]
        self.ylimdown_t_i=[]
        self.ylimup_n_e=[]
        self.ylimdown_n_e=[]
        self.ylimup_bootstr=[]
        self.ylimdown_bootstr=[]
  
  
    
        for i in range(self.tor): 
          
            self.xlimup_rho_tor.append(max(self.rho_tor[i])*1.1)
            self.xlimdown_rho_tor.append(min(self.rho_tor[i])*0.9)
    
          #------------y_LIMITS------------
            self.ylimup_j_tor.append(max(self.j_tor[i])*1.1)
            self.ylimdown_j_tor.append(min(self.j_tor[i])*0.9)
    
            self.ylimup_q.append(max(self.q[i])*1.1)
            self.ylimdown_q.append(min(self.q[i])*0.9)
    
            self.ylimup_t_e.append(max(self.t_e[i])*1.1)
            self.ylimdown_t_e.append(min(self.t_e[i])*0.9)
    
            self.ylimup_t_i.append(max(self.t_i[i])*1.1)
            self.ylimdown_t_i.append(min(self.t_i[i])*0.9)
    
            self.ylimup_n_e.append(max(self.n_e[i])*1.1)
            self.ylimdown_n_e.append(min(self.n_e[i])*0.9)
    
            self.ylimup_bootstr.append(max(self.bstrap[i])*1.1)
            self.ylimdown_bootstr.append(min(self.bstrap[i])*0.9)
        '''
        return tor, t1, t2, ipl2, ylimdown_ipl, ylimup_ipl, rho_tor, j_tor, ylimdown_j_tor, ylimup_j_tor, \
               xlimdown_rho_tor, xlimup_rho_tor, q_95, q_axis, ylimdown_q_q, ylimup_q_q, \
               q, ylimdown_q, ylimup_q, li_3, t_e, ylimdown_t_e, ylimup_t_e, fpow, t_i, \
               ylimdown_t_i, ylimup_t_i, limiterx, limitery, axx, axy, psi2d_t, \
               r_x, n_e, ylimdown_n_e, ylimup_n_e, z_x, bstrap, ylimdown_bootstr,ylimup_bootstr
        '''
    def plotty (self):
  
  
        
  
        a = self.matSlider.value()
    
        #fig, axes = plt.subplots(nrows=6, ncols=3, dpi=100, facecolor = 'white')
        #ax1 = plt.subplot2grid((6,3), (0,0))
        #ax1.plot(t2, ipl2)
        #ax1.ylim(ylimdown_ipl,ylimup_ipl)
        #ax1.title ("Ipl(t)")
        #plt.show()
  
        #----------------------------------------PLOT-----------------------------------------------
        #plt.ion()
        #fig = plt.figure()
        
        #plt.text(0.9,0.9,'$time slice %f'%a)
        #a1=fig.add_subplot (6, 3, 1)
        ax1=plt.subplot (6, 3, 1)
        plt.cla()
        plt.plot (self.t2, self.ipl2)
        #plt.xlim(-10,10)
        plt.ylim(self.ylimdown_ipl,self.ylimup_ipl)
        plt.title ("Ipl(t)")
   
        #a2=fig.add_subplot (6, 3, 3)
        ax2=plt.subplot (6, 3, 3)
        plt.cla()
        self.qql, = plt.plot (self.rho_tor[a],self.j_tor[a])
        #plt.plot (rho_tor[b], j_tor[b],'--', label='$slice # %a'%b)
        plt.title ("j_tor(rho)")
        plt.ylim([self.ylimdown_j_tor[a],self.ylimup_j_tor[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        #plt.legend(loc='center left',bbox_to_anchor=(1,0.5))

        ax3=plt.subplot (6, 3, 4)
        plt.cla()
        plt.plot (self.t2, self.q_95,'-', label='%s'%'q_95')
        plt.plot (self.t2, self.q_axis, '--',label='%s'%'q_axis')
        plt.title ("q95/axis")
        plt.ylim(self.ylimdown_q_q, self.ylimup_q_q)
        plt.legend(loc='center left',bbox_to_anchor=(-0.4,0.5))

        ax4=plt.subplot (6, 3, 6)
        plt.cla()
        self.ql, = plt.plot (self.rho_tor[a], self.q[a], 'r-')
        #plt.plot (rho_tor[b], q[b], '--', label='$slice # %a'%b)
        plt.ylim([self.ylimdown_q[a],self.ylimup_q[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        plt.title ("q")
        #plt.legend(loc='center left',bbox_to_anchor=(1,0.5))
  
        ax5=plt.subplot (6, 3, 7)
        plt.cla()
        plt.plot (self.t1, self.li_3)
        plt.title ("li(3)")
    
        ax6=plt.subplot (6, 3, 9)
        plt.cla()
        self.qqql, = plt.plot (self.rho_tor[a], self.t_e[a])
        #plt.plot (rho_tor[30], t_e[30], label='$slice # 30')
        plt.ylim([self.ylimdown_t_e[a],self.ylimup_t_e[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        plt.title ("Te")
        #plt.legend(loc='center left',bbox_to_anchor=(1,0.5))
  
        ax7=plt.subplot (6, 3, 10)
        plt.cla()
        plt.plot (self.t1, self.fpow)
        plt.title ("fus.pow.")
    
        ax8=plt.subplot (6, 3, 12)
        plt.cla()
        self.qqqql, = plt.plot (self.rho_tor[a], self.t_i[a])
        #plt.plot (rho_tor[30], t_i[30], label='$slice # 30')
        plt.ylim([self.ylimdown_t_i[a],self.ylimup_t_i[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        plt.title ("Ti")
        #plt.legend(loc='center left',bbox_to_anchor=(1,0.5))
  
  
        #---------------EQUILIBRIUM-------------------------------------------------------
        ax9=plt.subplot (1, 3, 2)
        plt.cla()

        plt.plot (np.array(self.limiterx).T, np.array(self.limitery).T,'k-', linewidth=1,  label='equilibrium')
        if self.r_x[a] != 0.0:
          plt.plot(self.r_x[a],self.z_x[a],'rx')
          plt.plot (self.gran_r[a],self.gran_z[a],'m', linewidth=0.5)

        psi_ax = plt.contourf(self.axx,self.axy,self.psi2d_t[a],20)
        dpsi = 1e-10+1e-5*(np.max(self.psi2d_t[a])-np.min(self.psi2d_t[a]))
        psi_sep_ax=plt.contourf(self.axx, self.axy, self.psi2d_t[a], levels=[self.psi_sep_t[a],dpsi+self.psi_sep_t[a]]) 

        
        plt.title ('equil \n time %f sec.'%self.t2[a])
        #plt.gca().set_aspect('square', adjustable='box')
        plt.axis('scaled')

        #--------------END_EQUILIBRIUM-------------------------------------------------------
        ax10=plt.subplot (6, 3, 13)
        plt.cla()
        plt.plot (self.t1, self.tau_e)
        plt.title ("tau_energy")

        ax11=plt.subplot (6, 3, 15)
        plt.cla()
        self.qqqqql, = plt.plot (self.rho_tor[a], self.n_e[a])

        plt.ylim([self.ylimdown_n_e[a],self.ylimup_n_e[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        plt.title ("Ne")

  
  
        ax12=plt.subplot (6, 3, 16)
        plt.cla()
        plt.plot (self.t1, self.z_x)
        plt.title ("Zx")
   
        ax13=plt.subplot (6, 3, 18)
        plt.cla()

        self.l, = plt.plot (self.rho_tor[a], self.bstrap[a], 'r-')
        plt.ylim([self.ylimdown_bootstr[a],self.ylimup_bootstr[a]])
        plt.xlim([self.xlimdown_rho_tor[a],self.xlimup_rho_tor[a]])
        plt.title ("bootstrap")


        #--------------------------------slider_end  
        plt.subplots_adjust(wspace=0.2, hspace=0.6)
        self.canavas.draw()


    #0--------------------------------------------------------------------------------------------------------------------EQUIL GRAPH-------------------------------------------------  
    #0-----------------------------------------------------   

    def buildUI(self):
        super().buildUI(self)
        #plotty()
        
        #self.setWindowTitle('TRY-1-2-3')
