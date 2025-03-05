 # Case Study 1: Bare-metal Polling Mechanism - STM32 CAN Communication (Loopback Mode)

## Summary
This project demonstrates **CAN communication** using an **STM32** microcontroller in **loopback mode**. The microcontroller continuously transmits and receives CAN messages, allowing verification of both transmission and reception without requiring an external CAN transceiver.

## Main Functionality
- The STM32 **transmits** a message in the format:  
  **"CAN NB: X"**, where **X** is an incrementing counter.
- The same message is **received back** due to **loopback mode**, confirming successful transmission.

## Function Descriptions

### `CAN_TX()` - Message Transmission
- **Checks** if a CAN transmit mailbox is free.
- **Formats** the message with an ID, DLC (Data Length Code), and payload.
- **Sends** the message via the CAN peripheral.
- **Waits** until transmission is confirmed before proceeding.

### `CAN_RX()` - Message Reception
- **Waits** until a message is available in the receive FIFO.
- **Extracts** key information:
  - **ID** (Standard/Extended)
  - **DLC** (Number of bytes)
  - **Data** (Actual message content)
- **Processes** the received data (if required).

## Loop Behavior
- The transmission and reception functions run **continuously** in an infinite loop.
- Each received message is verified against the sent message.

---

### Notes
- This project follows a **bare-metal polling mechanism**, meaning:
  - It directly interacts with hardware registers **without an RTOS**.
  - The CPU **actively waits** for events instead of using interrupts.
- The project runs in **loopback mode**, meaning the messages are sent and received internally without external hardware.
- This setup is useful for **debugging and testing** CAN functionality before deploying to real-world applications.
- The code was **simulated in Keil** to observe the CAN message increments.

---

## Simulation
 



