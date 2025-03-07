# Case Study 2: CAN Communication with Interrupts - STM32F103C8

## Summary
This project demonstrates CAN communication using an STM32F103C8 microcontroller. The microcontroller transmits a CAN message every second and receives messages with a specific ID using interrupts. This setup simulates a real-world scenario where the microcontroller communicates with other CAN nodes.

---

## Main Functionality
1. **Transmission:**
   - The STM32 sends a CAN message with ID `0x030` and a 1-byte payload.
   - The payload alternates between `ACC` (1) and `NO_ACC` (0) every second.
2. **Reception:**
   - The STM32 receives CAN messages with ID `0x3AB` and processes the payload (e.g., speed data) in an interrupt callback.

---

## Function Descriptions
1. **`CAN_TX()` - Message Transmission:**
   - Checks if a CAN transmit mailbox is free.
   - Formats the message with an ID, DLC (Data Length Code), and payload.
   - Sends the message via the CAN peripheral.
2. **`CAN_RX()` - Message Reception:**
   - Waits until a message is available in the receive FIFO.
   - Extracts the ID, DLC, and payload from the received message.
3. **Interrupt Callbacks:**
   - `HAL_CAN_RxFifo0MsgPendingCallback`: Processes received messages.
   - `HAL_CAN_TxMailbox0CompleteCallback`: Handles transmission completion.
   - `HAL_CAN_ErrorCallback`: Handles CAN errors.

---

## Loop Behavior
- The transmission function runs every second in an infinite loop.
- The reception function processes incoming messages in the interrupt callback.

---

## Notes
- This project uses **interrupts** for efficient CAN communication.
- The CAN filter is configured to accept messages with ID `0x3AB`.
- The code is designed for use with an external CAN transceiver (e.g., MCP2551) and a CAN bus.
- This setup is useful for testing CAN communication in real-world applications.

---

## Simulation