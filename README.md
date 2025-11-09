# Onboard LED Blinking using STM32F407G-DISC1

This project blinks the four onboard LEDs on the STM32F407 Discovery board. Each LED is connected to a GPIO pin on port D:  
- PD12 – Green  
- PD13 – Orange  
- PD14 – Red  
- PD15 – Blue  

The LEDs are toggled in sequence using HAL_GPIO_WritePin and HAL_Delay.

## Hardware Needed
| Component | Description |
|----------|-------------|
| STM32F407G-DISC1 Board | Microcontroller board |
| USB Cable | Power & programming |
| STM32CubeIDE | Software toolchain |

## Pin Configuration
| LED Color | GPIO Pin |
|----------|---------|
| Green | PD12 |
| Orange | PD13 |
| Red | PD14 |
| Blue | PD15 |

## Steps to Run
1. Open STM32CubeIDE → New STM32 Project.
2. Select **STM32F407G-DISC1** board.
3. Set PD12–PD15 as **GPIO Output** in Pinout.
4. Generate Code → Open `Core/Src/main.c`.
5. Paste the provided program.
6. Build and flash to the board.
7. Observe LEDs blinking sequentially.

## Output Behavior
- LEDs blink one after another at 200ms intervals.
- Changing HAL_Delay changes blink speed.

## Conclusion
This experiment demonstrates basic GPIO output control on STM32 using HAL library, introducing timing and digital pin manipulation.
