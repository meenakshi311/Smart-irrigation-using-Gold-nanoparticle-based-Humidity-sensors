# Smart-irrigation-using-Gold-nanoparticle-based-Humidity-sensors
# Aim
The Smart Irrigation System using Gold Nanoparticle Printed Humidity Sensors is a cutting-edge technological solution designed to optimize the irrigation process in agricultural practices. This system utilizes humidity sensors based on gold printing technology to accurately measure the relative humidity of the environment. By monitoring and analyzing the humidity levels, the system determines the optimal time to water the crops, conserving water resources and promoting efficient plant growth.
# Working
The system consists of a humidity sensor connected to an Arduino board. The humidity sensor measures the resistance across its terminals, as resistance decreases, conductance increases; water, being a good conductor will lower the resistance of the humidity sensor and it is this value which is then converted into a humidity value using a calibration algorithm. The gold printed humidity sensors offer high sensitivity and reliability, ensuring accurate readings in various environmental conditions.
# Circuit Diagram
![image](https://github.com/meenakshi311/Smart-irrigation-using-Gold-nanoparticle-based-Humidity-sensors/assets/80347426/df56160e-ec86-4421-af35-3f9fde3e9be8)

# Connections
Connect GND, VCC pins of Humidity sensor to GND, VCC of Arduino respectively. Analog input of Sensor is connected to A1. Connect positive and negative terminals of battery to relay. vcc of relay to 5V of Arduino. Also connect the terminals of relay to DC motor.
# Algorithm
1.	Define the necessary constants for pin assignments and sensor ranges.<br>
2.	Initialize the output_value variable.<br>
3.	Enter the setup() function:<br>
o	Configure the pump_pin as an output pin.<br>
o	Begin serial communication.<br>
o	Print an initialization message.<br>
o	Add a delay of 2 seconds.<br>
4.	Enter the calculateHumidity() function:<br>
o	Accept the resistance value as input.<br>
o	Map the resistance value to the humidity range.<br>
o	Constrain the humidity value within the defined range.<br>
o	Return the calculated humidity.<br>
5.	Enter the loop() function:<br>
o	Read the analog value from the sensor_pin and store it in the output_value variable.<br>
o	Map the output_value to a resistance value using the specified ranges.<br>
o	Calculate the humidity using the resistance value by calling the calculateHumidity() function.<br>
o	Check if the output_value is greater than the threshold (600.00):<br>
	If true, turn on the water pump by setting the pump_pin to HIGH, wait for 3 seconds, and then turn it off by setting the pump_pin to LOW.<br>
	If false, turn off the water pump by setting the pump_pin to LOW.<br>
o	Add a delay of 1 second before the next iteration of the loop.<br>

# Results
1.	It has been observed that humidity sensors as susceptible to changes in the environmental conditions, for example – the soil sample kept in 29˚C gives different readings of humidity than the same sample kept at air conditioned weather settings at 24˚C. 
<br>
2.	The readings vary constantly in a very small range even under steady conditions.
<br>
3.	**Calibration of the sensor played a massive role in understanding its operation and output resistance range. **

