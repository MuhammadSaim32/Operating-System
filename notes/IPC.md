# Inter-Process Communication (IPC)

Processes are isolated, but sometimes need to share data. Two main methods:
1. Message Passing

Processes send messages to each other via the kernel.
Example: Chat apps (one process sends, another receives).
Safe, since no direct memory access.
Kernel handles the transfer.
How it works:
Process A → sends message to kernel.
Kernel stores it and delivers to Process B.
Process B reads it.

2. Shared Memory

Kernel sets up a memory area that multiple processes can access.
Very fast, since processes read/write directly.
Needs synchronization (locks, semaphores) to avoid conflicts.
Example: Video players  (share video frames in memory).
### Spooling 

- Used when **device speed < process speed** (device is slow).
- Idea: Store jobs in a **queue (disk/memory buffer)** until device is ready.
- Device then processes jobs one by one.

**Example:**

- **Printing** → If 10 people send documents to a printer, the OS stores them in a **print spool** (queue). Printer takes jobs one by one.
# What is Buffering?

**Buffering** = Using a **temporary storage area (buffer)** to handle the speed difference between a **fast producer** and a **slow consumer** (or vice versa).

Think of a **bucket of water**:

- If water comes from a tap faster than you can drink, you fill a glass (buffer) first.
- You drink slowly from the glass while the tap can keep filling it up.
- The buffer (glass) **smooths the mismatch in speed**.

# Why do we need buffering?

In computers:

- Sometimes **data arrives too quickly** (e.g., keyboard typing).
- Sometimes **data arrives too slowly** (e.g., video from internet).

Without buffering, either data would be **lost** (if it arrives too fast) or the system would **pause too often** (if it arrives too slow).

# Real Examples of Buffering

###  **YouTube or Netflix Video**

- Internet speed is not constant (it may fluctuate).
- The app **downloads a chunk of video in advance** and stores it in a buffer.
- Even if your internet lags for a few seconds, the video **keeps playing smoothly from the buffer**.
- If the buffer empties → you see “Buffering…” on screen.

- **Fast producer, slow consumer** → Buffer prevents overflow/loss.
- **Slow producer, fast consumer** → Buffer preloads data (consumer waits initially), then smooths playback until buffer empties.
- Playback = the act of playing back stored audio or video data for the user (listening/watching).