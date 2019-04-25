clear all; close all; clc;

visc = csvread('viscous_drag_landscape_results.csv');
indu = csvread('induced_drag_landscape_results.csv');
indu_z = indu(:,3);
indu_z(indu_z==999)=NaN

x = visc(:,1);
y = visc(:,2);
z = visc(:,3)+indu_z;

removenan = [x y z]

%removenan(sum(isnan(removenan), 2) == 1, :) = [];

x = removenan(:,1);
y = removenan(:,2);
z = removenan(:,3);

[Zmin,Idx] = min(z(:));
[ZminRow,ZminCol] = ind2sub(size(z), Idx);

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
zlabel('Total Drag (N)')

fprintf('min drag %f at span %f and chord %f\n', Zmin, x(Idx), y(Idx))