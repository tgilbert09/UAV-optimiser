'''
Program to investigate viscous drag at various spans and chords

Uses XFOIL and takes aerofoil with lowest drag coefficient
Assumes lift = aircraft weight

.dat files created using xfoil
>> XFOIL >> naca XXXX >> save XXXX.dat

Uses daniel-de-vries/xfoil-python (pip install xfoil)
Tested and created on Windows 10 using Python 3.6 64bit
'''

import numpy as np
import csv
import os

if os.path.exists("viscous_drag_landscape_results.csv"):
    os.remove("viscous_drag_landscape_results.csv")

from math import isnan
from math import pi
from xfoil import XFoil
from xfoil.model import Airfoil

# Reads aerofoils to analyse from TOWS ('Theory of Wing Sections') file
# .dat file for aerofoil in TOWS file must be in nacaFoils folder
def importAerofoilTOWS():
    allAerofoils_str = []
    with open('TOWS.csv', 'r') as file:
        readIn = csv.reader(file)
        for row in readIn:
            allAerofoils_str.append(', '.join(row))
    return allAerofoils_str
        
class aerofoil:
    def __init__(self, name):
        self.name = name

    def aerofoilDat(self):
        file_data = np.genfromtxt("nacaFoils\\"+str(self.name)+".dat",\
                                  usecols=(0,1), skip_header=1, dtype=float)
        return file_data

    def aerofoilModelling(self):
        file_data = self.aerofoilDat()
        self.aerofoilModel = Airfoil(file_data[:,0], file_data[:,1])

    def computation(self, cl):
        xf.airfoil = self.aerofoilModel
        self.a, self.cd, cm, cp = xf.cl(cl)

def createAerofoilObj(allAerofoils_str):
    allAerofoils_obj = []
    for i in range(len(allAerofoils_str)):
        allAerofoils_obj.append(aerofoil(allAerofoils_str[i]))
        allAerofoils_obj[i].aerofoilModelling()
    return allAerofoils_obj

def initialiseAerofoils():
    allAerofoils_str = importAerofoilTOWS()
    allAerofoils_obj = createAerofoilObj(allAerofoils_str)
    return allAerofoils_obj


def liftCoCalc ():
    cl = (((mass*g)/span)/(chord*0.5*rho*velocity**2))
    cl = round(cl, 4)
    return cl

def runAnalysis():
    for i in range(len(allAerofoils_obj)):
        #print("{0: >2}. Computing naca {1.name}".format(i, allAerofoils_obj[i], width=5))
        allAerofoils_obj[i].computation(cl)

def convergenceCheck(allAerofoils_obj):
    for x in allAerofoils_obj:
        if isnan(x.cd):
            print("Aircraft mass {0: >3} kg - naca {1: >5} NOT CONVERGED - {1: >5} neglected".format(mass, x.name))
    filteredAerofoils_obj = [x for x in allAerofoils_obj if not isnan(x.cd)]
    return filteredAerofoils_obj

def rankAerofoils(filteredAerofoils_obj):
    filteredAerofoils_obj.sort(key=lambda filteredAerofoils_obj: filteredAerofoils_obj.cd)
    return filteredAerofoils_obj[0]

def sortResults():
    print("Error report:")
    filteredAerofoils_obj = convergenceCheck(allAerofoils_obj)
    bestAerofoil_obj = rankAerofoils(filteredAerofoils_obj)
    return bestAerofoil_obj

def displayResults():
    print("Best: naca {0} - Drag coefficient {1}".format(bestAerofoil_obj.name, bestAerofoil_obj.cd))

def saveResults():
    datarow = [span, root_chord, bestAerofoil_obj.cd]
    with open(r'viscous_drag_landscape_results.csv', 'a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(datarow)
    

rho = 1.1685
velocity = 41.6667
g = 9.81
reynolds_div_chord = 2794120

mass = 100

xf = XFoil()
xf.max_iter = 100

START_CHORD = 0.3
END_CHORD = 0.5
CHORD_POINTS_PER_METRE = 10

START_SPAN = 8
END_SPAN = 10
SPAN_POINTS_PER_METRE = 1

chord_points = int((END_CHORD-START_CHORD)*CHORD_POINTS_PER_METRE)
chord_increment = float((END_CHORD-START_CHORD)/chord_points)

span_points = int((END_SPAN-START_SPAN)*SPAN_POINTS_PER_METRE)
span_increment = float((END_SPAN-START_SPAN)/span_points)

print("Max iterations: {0}\nMass: {1}Kg".format(xf.max_iter, mass))

for j in range(chord_points+1):
    root_chord = START_CHORD+(j*chord_increment)
    chord = START_CHORD+(j*chord_increment)*(8/(3*pi))
    chord = round(chord, 2)
    for i in range(span_points+1):
        span = START_SPAN+(i*span_increment)
        span = round(span, 2)

        #Reynolds number, unit chord (see XFOIL docs UNITS section)
        xf.Re = reynolds_div_chord * chord

        print("\nSpan: {0}m\tChord: {1}m\tReynolds: {2}".format(span, root_chord, xf.Re))
              
        cl = liftCoCalc()
        allAerofoils_obj = initialiseAerofoils()
        runAnalysis()
        bestAerofoil_obj = sortResults()
        displayResults()
        saveResults()
