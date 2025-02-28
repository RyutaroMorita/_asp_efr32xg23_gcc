# Operating Si4x6x with EFM32PG23

## Introduction

This TRX example demonstrates the simplest exchange of transmit and
receive operation between two nodes of Si4x6x.

## Getting Started

This example implements both the receiver (RX) and the transmitter (TX) nodes.
The implementation is therefore symmetric, as both nodes are capable of sending
and receiving messages.

----

Compile the project and download the application to two EFM32PG23 boards.

----

## Peripherals

This example requires a `Simple Button` instance and two `Simple LED` instances
(`led0` and `led1`) installed in the Project's `Software Components` window.

- Pressing the PB0 push button on the development kit initiates packet
  transmission.
- Toggles on LED1 indicate that a packet reception on the RX node was
  successful.
- Toggles on LED0 indicate that a packet transmission on the TX node was
  successful.
- Pressing the PB1 push button on the development kit starts unmodulated carrier 
  transmission.
