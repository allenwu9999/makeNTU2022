# Smart Table
![IMG_6860-2](https://github.com/allenwu9999/makeNTU2022/assets/60618505/b70b905a-ffd6-4274-926b-1af176c63246)

## Award
***2022 MakeNTU Hackathon Best Solver***

***2022 MakeNTU Hackathon NXP Sponsor Award***

## DEMO

## Motivation

>*The perception of 'beauty' often stems from the abundance observed in everyday life.*
>
You step into the restaurant at the edge of the sunset, settling into the seat by the window, preparing to heal the fatigue of the day. You might gaze outside, pondering the chaos of Taipei after the sunset, or casually glance over the restaurant's decor, finally focusing on poorly replicated imitation paintings or flipping through slightly yellowed pages. You immerse yourself in the tranquil yet profound vastness under the pen of Haruki Murakami, deliberately absorbing the beauty of life in the leisure brought by the idle moments before your meal arrives.

However, the hurried and impatient words of the waiter, "Please go to the counter to order!" abruptly tear apart the utopian curtain. You just realized that, from that day on, the restaurant, in order to save labor costs, had transformed all its services into self-service. Customers not only had to order at the counter themselves but also fetch water, get their own utensils, clear their trays, and settle the bill. What used to be a leisurely and enjoyable dinner, filled with a sense of tranquility, had now turned into a battle for efficiency. Time was fragmented, resembling a rushed morning routine after oversleeping: brushing teeth with one hand, shaving with the other, grabbing an unfinished briefcase and shirt, and hurrying to work, leaving no room to breathe.

**"Do I really need to eat a meal in such a disheveled manner?"** The essence of this piece is to offer you that moment of tranquility before your meal, allowing you the space to contemplate the beauty within life.

## Block Diagram
![block_diagram](https://github.com/allenwu9999/makeNTU2022/assets/60618505/ea294d80-07d1-45db-b709-1904d274faab)



## How it works
1. Ordering Interface: Customers select their meals using the buttons on the ordering screen. The data will be transmitted to the backend
![圖片 2](https://github.com/allenwu9999/makeNTU2022/assets/60618505/56b4b28a-011a-4cb2-96e6-5c9ed03967a4)
DEMO: https://drive.google.com/file/d/1UslzkAR3LAmFFaSTm6TAvRL2SqEQnnhU/view?usp=share_link

---
2. Automatic Lighting System: The lights on the dining table will automatically turn on when there are customers and turn off when there are no customers.
![圖片 1](https://github.com/allenwu9999/makeNTU2022/assets/60618505/f7eb33fb-b7b5-437d-befe-29873f64166b)
DEMO: https://drive.google.com/file/d/1UslzkAR3LAmFFaSTm6TAvRL2SqEQnnhU/view?usp=share_link

---
3. Automatic Water Refilling System: Customers place their water cups on the tray to the right of the dining table. The tray will automatically transport the cups to the water reservoir to fill them with water and then return them to the customers.
![圖片 4](https://github.com/allenwu9999/makeNTU2022/assets/60618505/4751c7cc-374c-4a10-bdb1-ecd46e2be7de)
DEMO: https://drive.google.com/file/d/1bMpVjzrBUy6PdTVJwO0jDaBowTfo4Av_/view?usp=share_link

---
4. Automatic Tableware Delivery: Once the customer's meal is served, the utensils will be automatically transported to the table based on the size of the tray via the conveyor belt.
![圖片 3](https://github.com/allenwu9999/makeNTU2022/assets/60618505/b584ffc4-06ea-45a6-a8aa-ea8b9fc4a0b3)
DEMO: https://drive.google.com/file/d/1YFk7aJ4RxSP1xF0b1qjBJHdIDP8HYL3n/view?usp=share_link



## Technical Implementation
1. Ordering Interface: Display the menu on the LCD module and record the dishes ordered by the users. Transmit this information back to the backend.
---
2. Automatic Lighting System: Utilizing the image recognition chip provided by NXP, continuously convert the field of view inside the camera into images. Additionally, train a separate image recognition model to identify whether there are human figures within the field of view. If the result indicates the presence of a person, turn on the light; if the result shows no presence for a certain period, turn off the light.
---
3. Automatic Water Refilling System: When the user places the cup on the carrier, if the weight sensor module underneath detects insufficient water, it transports the cup to the area under the water reservoir. A servo motor is used to open the reservoir switch, allowing water to be filled. Once the weight sensor module detects an adequate water level, it closes the reservoir switch and delivers the water back to the user.
---
4. Automatic Tableware Delivery: Using the Raspberry Pi Camera to capture images of the dining table, utilizing Raspberry Pi for image processing to recognize the sizes of bowls and plates on the table. Transmitting signals to Arduino Mega to control servo motors, delivering the necessary utensils to the user via a conveyor belt.
