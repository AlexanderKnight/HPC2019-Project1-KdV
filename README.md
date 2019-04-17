# HPC2019-Project1-KdV
## Project 1 - HPC 2019 - KdV Equation

Midterm Project for HPC 2019

## Description

This code is designed to take an initial input, and evolve the state by the means of the Korteweg-de Vries equation of state, and 4th order Runge-Kutta.

NOTE: Currently, the code does not behave in the manner expected, despite being stable.
The KdV equation is meant to simulate a wave cresting, with some independent waves with differing phase velocities passing through eachother.
The current code keeps a stable wave, and corrects the wave from cresting too far. 
This is a bug that was not able to be corrected.

## How To Use:

The code consists of two main parts: generating the initial conditions and evolving those conditions.

### Generating Initial Condition:

There are four current functions that can be created for a domain of length $L$:

* $\sin\bigg(\frac{2\pi x}{L}\bigg)$
* $\cos\bigg(\frac{2\pi x}{L}\bigg)$
* $sech^2\bigg(\frac{L}{2}-x\bigg)$
* $\exp\bigg(-(x-\frac{L}{2})^2\bigg)$

In the file 'init_func_gen.cpp', you can define 'size' for the number of points in the simulation (the resolution), the starting point and ending point (end-start=L), and the choose the function you want to create.

When this is compiled and ran (which we will do below along the the evolution), you will get a data fle "KdVInitData.dat".
This file will be read into program to evolve.

### Evolving the simulation

To actually run the simulation, two parameters need to be chosen in main.cpp.
The first is 'numIter', which is the number of timesteps.
Since we generally have a small space step, we will need a much smaller timestep, so many timesteps are usually required to see anything.
$10^6$ is a good starting point.

The second value is 'save_every_nth_iter', which determines how often data will be exported.
With such small timesteps, there is often very little change between steps, so it is often helpful to only save every nth step for plotting.
We have found that having this value about three orders of magnitude lower than 'numIter'.
For example if numIter=$10^6$, then save_every_nth_iter=$10^3$ is a good ballpark to start in.

### Compiling and Running

First, clone the repo from Github.
Then in the HPC2019-Project1-KdV directory (which I will call the master directory from now on), create a build/ directory, to keep the master directory clean.
Change the parameters in init_func_gen.cpp and main.cpp to match what you want.
Change directory to build/ and execute the following commands:

```sh
cmake ..
make
./init_data
./kdv KdVInitData.dat
```

Depending on your parameters, this last step could take a long time, or could go quickly. 
It will output a datafile called 'EvolvedData.dat', which has been organized to be plotted with gnuplot.
Each timestep is organized by column, so to plot a particular timestep (say 300), you would just use

```sh
gnuplot -e "plot 'EvolvedData.dat' using 300"
```

To make a video, gnuplot can be utilized with ffmpeg. 
Assuming numIter=$10^5$ and save_every_nth_iter=$10^2$, then numIter/save_every = $10^3$, and 50 frames a second, we can do

```sh
for i in $(seq 1 1000)
do echo $i
gnuplot -e "set term png size 800,600; set output 'plot_$i.png'; plot 'EvolvedData.dat' using $i"
done
ffmpeg -y -r 50 image2 -s 1920x1080 -i plot_%d.png -vcodec libx264 -crf 25 plot.mp4
rm plot_*
```

That last line may be omitted if you want to keep all of the timestep plots.

