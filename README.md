# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## PID Controller

PID stands for Proportional (P), Integral (I), and Dervative (D), respectively. 

* P is the most significant factor. When the P value is high, the car will make significant turn. When the P value is low, the vehicle is not able to make enough turn in sharp turn of the road.
* I just like a buffer to reduce the car to reach the center line. 
* D is to alleviate P's effects. When D is higher, P's effects would be lower, vice versa. 

The final hyperparameters are tuned as follows. Twiddle is implemented, and tested, which provides the basic range of P, I, D values. Then those values are further refined based on the car running results. For instance, for passing the sharp turn, P value would be increased, and D value should be decreased. However, the reverse approach is taken when the car turns significantly. Interestingly, with twiddle for every step would make the car keep changing direction, and the throttle is no more than 10. The value of tolerance, and different settings of initial values are also examined, but all did not show improved results. Therefore, here twiddle is only used for determining the base range of PID values. PID controller for throttle is not implemented, but I believe it would further improve the autonomus drive performance.

## Final result

The final values of P, I, and D are 0.15, 0.00001, and 2.5, respectively, and the highest speed achived is around 45 mph. A video of final result is available [here](https://youtu.be/4Qff3R-hq24).



