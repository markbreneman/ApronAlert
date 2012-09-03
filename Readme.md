## APRON ALERT

Apron Alert is experiment with soft circuits and connecting Arduino to twitter.To do this the project makes use of 

1. Arduino and Xbee
2. Python
3. Some additional python libraries in order to interface simply with twitter

## Documentation
A general overview of the hardware technology can be found here;

[SmartInteractionLab][0]

To get up and running codewise install, the basics: [Arduino][1] and [Python][2].  Then install the additional Python libraries found in the Additional Assets folder(unzip each archive then in terminal navigate to each folder(cd) and type python setup.py install).

Next register for a twitter developer account.[3]

After going through the developer registration process copy down the access key and OAuth info. Next open up the ApronAlert.py code in the Python folder and edit it accordingly to your developer keys. Save this file.

Then upload each Arduino sketch to the appropriate boards, one being the receiver, and one configured as the sender(this one is one in sewn into the apron.)

Lastly in terminal run the Apron Alert.py file using the command Python ApronAlert.py.  When this file is running the circuit will be live and posting to Twitter when the circuit is closed.

[0]:http://smartinteractionlab.com/apron-alert-internet-of-things-experiment/
[1]:http://www.arduino.cc/
[2]:http://docs.python.org/install/index.html
[3]:https://dev.twitter.com/
