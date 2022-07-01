# EMG-inz
This is my engineering project. 

The Hc-05 folder contains very basic code for communicating with HC-05 Blueooth module. 
First if you want to configure HC-05 via AT commands you have to add a wire which conects EN pin with 3.3V on the Arduino board. 
!Before powering the module you have to hold the button on HC-05! 

Arduino folder contains a pretty simple idea of a system which is filtering the EMG signal from Myoware module. 
There is also zero-crossings method implemeneted which id the core part of the system if it comes to decide whetheer the seizure attack was. 

You have to install the app which is in EMG-sens repo to see the results. https://github.com/bszyca/EMG_sens

