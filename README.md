## PID control project for vehicle dynamics 
This is a project for Udacity Self-Driving Car Nanodegree program. In this project, I implemented a PID control S/W code for stabilized vehicle control. All codes are written with C++ and tested on the Udacity simulator. 

## Requirement 
- C++- Udacity simulator : [here](https://github.com/udacity/self-driving-car-sim/releases)
- uWebSocketIO : [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac
- For window users : [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) to install uWebSocketIO. 

## Other Important Dependencies
* cmake >= 3.5  
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1  
  * Linux: make is installed by default on most Linux distros  
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)  
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4  
  * Linux: gcc / g++ is installed by default on most Linux distros  
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)  
  * Windows: recommend using [MinGW](http://www.mingw.org/)
  
## Run the Project 
Once the install for uWebSocketIO is complete, the main program can be built and run by doing the following from the project top directory.

1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./pid

## About the Project 
The most important part in this project was to optimize the PID gain (Kp, Ki, Kd). There are a couple of methods to choose the suitable PID gain. At first, I tried the twiddle methodology based on the lecture. However, it does not work in this simulator because the gains could not properly be applied to simulator in real time. Secondly, I used the Ziegler-Nichols method. It seems that it works well for Kp. But, the gain of Ki and Kd could not be optimal mainly because of incorrect measurement of oscillating period (Tu). I figured out that the best way is the manual tuning with the understanding of the implication of each gain. First, I found the Kp with Ziegler-Nichols method. The stable oscillating Kp was 0.35. By multiplying 0.6 to 0.35, I got 0.2 for the final Kp gain. As the next step, I controlled Kd because the integral part do the main role of stabilizing the oscillating vehicle with the accumulated error. I figured out that the vehicle was fast stabilized when I set Kd 3.8. Finally, I controlled differential part - Ki - which contributes to reponse to abrupt deviation of the vehicle. 0.001 was enough and optimal number for Ki. It responded properly even to the highly curved road. In sum, I successfully ran a simulation lap until 60Km/h (Throttle = 0.6).

## Discussion/Issues 
When I increased the vehicle speed to over 70Km, the vehicle was getting unstable, and finally deviated from the road. I have to find the real-time optimization algorithm for PID gain as a next step. 
