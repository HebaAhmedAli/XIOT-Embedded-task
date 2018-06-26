-I thoght of connecting the switch to interrupt pin so that it works independantly of my program and call the ISR whenever the switch change its state.
-I defined the variables that the ISR would change as volatile  to prevent the compiler from applying any optimizations on them as they can be changed at anytime.
-Then i need to check in my code for the change in switch state to send the required data to serial monitor -once- so i used the variables:toggle,old_toggle and switch_state.
-I also wrote a function to read the temprature sensor value every 3 seconds,convert it to celsius and print it 


-I wrote my code using arduino c which i already have past experience with as i made a team project using arduio.Here is the idea and tools we used:
Idea: basketball which moves according to an equation -entered in the program- in a 2d plane, 
while we can play and when the ball fall inside the basket a sensor sense it and we show the score on LCD.
Tools and Components: Arduino, Sensor, LCD, Motors, Drivers.
