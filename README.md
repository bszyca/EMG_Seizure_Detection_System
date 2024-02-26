# EMG_Seizure_Detection_System
This is my engineering project. 

The Hc-05 folder contains very basic code for communicating with HC-05 Blueooth module. 
First if you want to configure HC-05 via AT commands you have to add a wire which conects EN pin with 3.3V on the Arduino board. 
!Before powering the module you have to hold the button on HC-05! 

Schematic: 

![Zrzut ekranu 2022-07-01 105631](https://user-images.githubusercontent.com/91716038/176861887-3816549d-26af-43ec-ad36-e79abc3a1b14.png)


Arduino folder contains a pretty simple idea of a system which is filtering the EMG signal from Myoware module. 
There is also zero-crossings method implemeneted which id the core part of the system if it comes to decide whether the seizure attack occured. 

EMG Signal indicating seizure in Arduino IDE:

![Zrzut ekranu 2022-07-01 105718](https://user-images.githubusercontent.com/91716038/176861922-2d7f2f48-fcd2-4b08-a8f4-ff6fe5ef9822.png)

System: 
 
![Zrzut ekranu 2022-07-01 105735](https://user-images.githubusercontent.com/91716038/176861929-5bafc0a6-29a7-4691-b08c-8da852faa14e.png)



You have to install the app which is in EMG-sens repo to see the results. https://github.com/bszyca/EMG_sens


