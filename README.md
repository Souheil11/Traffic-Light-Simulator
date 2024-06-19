# Traffic-Light-Simulator
Traffic light simulator with accessibility feature and Timer

Description:
The mini project is a traffic light simulator that uses an ESP8266 board to imitate a real traffic light. The LEDs are synchronized to follow a specific pattern:
The loop starts with the red light on for 5 seconds.
The yellow light joins for an additional 3 seconds while the red light is still on.
Both lights are then switched off, and the green light is activated for 8 seconds.
The green light blinks three times
Then the yellow light is active for 2 seconds.
The loop then starts again from the beginning.
Additionally, I added a sound alert to the green light to help people with visual impairments know when the green light is active. The sound pattern changes and becomes faster while the green light starts to blink to alert of the near change.
I have also implemented a feature that incorporates a countdown timer, which tracks and displays the remaining seconds until the next lighting event. This addition enhances the user experience by providing a clear and convenient way to anticipate when the next light will occur.
