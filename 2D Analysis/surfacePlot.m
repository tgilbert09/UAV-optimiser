clear all; close all; clc;

data = csvread('viscous_drag_landscape_results.csv');

x = data(:,1);
y = data(:,2);
z = data(:,3);

xlin = linspace(min(x),max(x),33);
ylin = linspace(min(y),max(y),33);

[X,Y] = meshgrid(xlin,ylin);

f = scatteredInterpolant(x,y,z);
Z = f(X,Y);

figure
mesh(X,Y,Z) %interpolated
axis tight; hold on
plot3(x,y,z,'.','MarkerSize',15) %nonuniform
xlabel('span (m)')
ylabel('chord (m)')
zlabel('C_D Viscous')