# MECHANISM vs POLICY

##  WHAT IS A POLICY?

→ **Policy means: WHAT should happen**

It’s the **rule** or **decision** made by the OS.

 Think like a school rule:

- "Only teachers can go to the staff room." ← This is a **policy**

In OS:

- "This program is allowed to run"
- "This user can open this file"

Just the rule. Not how it works.

## WHAT IS A MECHANISM?

→ **Mechanism means: HOW it will happen**

It is the **tool or method** used to follow the rule (policy).

 Like the key to the staff room:

- **Lock and key system** enforces the policy

 In OS:

- A tool that **starts a program**
- A system that **checks file permissions**

 Just the method. Not the rule itself.

---

##  WHY KEEP THEM SEPARATE?

→ So we can **change the rule** without changing the whole system.

Example:

- Rule: Only teachers allowed → later changed to “Teachers + monitors allowed”
- We only update the **list** (policy), not the **lock system** (mechanism)

 In OS:

- Rule changes: Now allow another program to run
-  OS doesn’t need to rewrite its whole working — just update the rule

---

##  SUPER SHORT SUMMARY:

> 🔹 **Policy = What should happen (the rule)**  
> 🔹 **Mechanism = How it happens (the method/tool)**  
> 🔹 **They are kept separate to make OS easier to manage and change.**

---

# OPERATING SYSTEM NOTES

🔹 Topic: OS, Kernel, and Kernel Structures

---

##  1. WHAT IS AN OPERATING SYSTEM (OS)?

→ OS is a **software** that acts as a **bridge between user and hardware**.

🔸 Main Jobs:

- Run programs and apps
- Manage memory and CPU
- Control files and devices (keyboard, screen, etc.)
- Protect system from bad programs

 Think of it as a manager of the whole computer.

Example:

- Windows, Linux, macOS, Android — all are full operating systems.

---

## 2. WHAT IS A KERNEL?

→ Kernel is the **core part of the OS**.  
It directly talks to the hardware and handles everything in the background.

🔸 Main Jobs:

- Give CPU time to programs
- Allocate memory safely
- Control input/output devices
- Provide security

 Think of the **kernel as the brain** of the OS.

 Example:

- "Linux" is technically a **kernel**.
- Android uses the **Linux kernel**.
- Windows has its own **Windows NT kernel**.

---

## 3. DIFFERENCE: OS vs Kernel

| Aspect          | OS                          | Kernel                   |
| --------------- | --------------------------- | ------------------------ |
| Definition      | Full system (Kernel + Apps) | Core part of OS only     |
| Visible to user | Yes (GUI, apps)             | No (runs in background)  |
| Example         | Ubuntu, Windows 10          | Linux kernel, NT kernel  |
| Mode            | User mode + kernel mode     | Runs in kernel mode only |

 **Every OS contains a kernel**, but the kernel alone is **not the full OS**.

---

## 🔹 Topic: OS Structure and Role of Kernel

---

##  1. WHAT IS OS STRUCTURE?

→ OS Structure = The internal **design of an Operating System**.  
It shows **how the OS components are organized**, and **where the kernel fits**.

🔸 Every structure includes a **kernel**, but its size and role vary.

---

## 2. MONOLITHIC STRUCTURE

→ All core functions of the OS are inside **one large kernel**.

 Features inside the Kernel:

- Memory management
- CPU scheduling
- File system
- Device drivers
- System call interface

 All of these run in **kernel mode**.

🔹 Pros:

- Very fast (everything is connected)

🔸 Cons:

- Hard to update/debug

 Example: Early UNIX, Linux

 Summary:

> Monolithic = Kernel contains almost the **entire OS core**

---

##  3. MODULAR STRUCTURE

→ Like monolithic, but components are separated into **modules**.  
These modules can be **loaded/unloaded** as needed.

 Kernel still includes:

- Scheduler
- Memory management
- System calls
- Core drivers

But in separate plug-in files.

🔹 Pros:

- Flexible and easier to maintain

🔸 Cons:

- Slightly more overhead than monolithic

 Example: Modern Linux kernels (use Loadable Kernel Modules - LKMs)

 Summary:

> Modular = Kernel with plug-and-play pieces (modules)

---

##  4. MICROKERNEL STRUCTURE

→ Only the **most essential parts** are inside the kernel:

- CPU scheduling
- Memory management



🔹 Pros:

- Very secure and stable

🔸 Cons:

- Slower due to communication between kernel ↔ user space

 Example: Minix, QNX, L4 (mostly used in research or embedded systems)

 Summary:

> Microkernel = Tiny kernel, rest of OS runs outside in user mode  
> The kernel manages almost everything important in the system (CPU, memory, file system, etc.)

---

##  EASY SUMMARY:

>  **Kernel = Brain** of the OS  
>  **OS = Kernel + GUI + Apps + Tools**  
>  **Monolithic** = All-in-one  
>  **Modular** = Like monolithic, but pluggable parts  
>  **Microkernel** = Small core kernel, rest outside

---

## In monolithic and modular OS structures:

 The entire core OS is considered the kernel.

That includes:

- Process manager
- Memory manager
- File system
- Device drivers
- System call interface
- Interrupt handlers
- And more...

##  So why we say "Kernel" and not "Whole OS"?

Because:

The kernel is the heart of the OS, but...

The full OS also includes user-space tools, like:

- Shells (bash, cmd.exe)
- GUI (Gnome, Windows Explorer)
- Utilities (ls, notepad, etc.)

These live outside the kernel and use system calls to ask the kernel for help.

 So, the kernel is the core, and the rest is user-space software built on top of it.

| Type          | Real Examples                     | Where it runs |
| ------------- | --------------------------------- | ------------- |
| Command Shell | Termux on Android, PowerShell     | User Space    |
| GUI Interface | MIUI/OneUI on Android, Windows UI | User Space    |
| App Software  | YouTube App, Chrome, Zoom         | User Space    |
| Games/Tools   | Free Fire, Calculator, Snapchat   | User Space    |



##  What Is Programmable Interrupt Timer (PIT)?

It’s a hardware timer chip that sends a signal to the CPU at regular intervals (e.g., every 10ms).

This signal is a hardware interrupt.

The purpose is to interrupt the currently running app and give CPU time to the OS.

This enables multitasking — switching between apps.

##  Why Do We Need PIT?

Imagine:

One app (e.g., a game or virus) runs forever and never gives up control.

Without interrupting it, other apps (e.g., WhatsApp) will never get CPU time.

"The OS configures a hardware component (like the Programmable Interrupt Timer) to generate a timer interrupt signal every few milliseconds. When this hardware interrupt fires, it tells the OS: 'Hey app, your time's up!'"

##  What Happens When PIT Interrupt Fires?

Let’s go step-by-step:

1. PIT sends interrupt → CPU detects it  
   The interrupt number for PIT is fixed (vector 32)

2. CPU does:  
   Saves the current app’s state:

   - Program counter (PC)
   - Registers
   - Stack pointer  
     This is called a context save

3. CPU switches to kernel mode  
   It jumps to the timer interrupt handler (timer_interrupt_handler())

4. OS scheduler runs:  
   It decides:

   - Should we resume this app?
   - Or switch to another app?

5. If switching:

   - Save current app's state in PCB (Process Control Block)
   - Pick another app’s saved state from memory
   - Load its registers, PC, stack → Context Restore

6. CPU jumps to new app → It runs  
   This is called a Context Switch.

##  This Whole Process = Preemptive Multitasking

"Preemptive" = forcibly taking control from one app  
"Multitasking" = switching between multiple apps

And it happens because of the Programmable Timer Interrupt!

###  Example in Simple Words:

You're running YouTube app  
Timer says:  "10ms done!" → Sends interrupt  
OS pauses YouTube, saves its state  
OS resumes WhatsApp app  
After 10ms, switches again

This switching is so fast (100+ times per second) that it looks like both apps run together — but in reality, CPU is switching back and forth very quickly.

---

##  What is the Vector Table?

It's like a map or directory in memory.

 It tells the CPU:

“If event X happens, go run code at address Y.”

 Where is it?

Located at a fixed memory location  
Also called: Interrupt Vector Table (IVT) or IDT (Interrupt Descriptor Table) in Intel systems  
It holds pointers to handler functions

---

### 🔹 1. Trap (Software syscall, intentional)

- App executes a trap instruction (e.g., int 0x80, syscall)
- CPU uses the trap vector number to look up the handler address in the IDT
- CPU switches to kernel mode (Ring 3 → Ring 0)
- Saves app's current state (like PC, flags, stack pointer)
- Jumps to the system call handler (e.g., sys_open())
- OS runs → returns control to app → switch back to user mode

### 🔹 2. Exception (Unexpected error)

- App causes an error (e.g., 5 / 0, illegal memory)
- CPU raises an exception internally
- Finds the exception vector number → checks IDT
- Saves current app state
- Switches to kernel mode
- Jumps to exception handler
-  OS may kill app, log error, or recover.

### 🔹 3. Interrupt (Hardware signal, like timer) ,  Hardware interrupt (asyncronous  events (I/O,keypress ,etc...) )

- Hardware sends signal (e.g., timer chip says “interrupt!”)
- CPU pauses current task
- Looks up interrupt vector in the IDT
- Saves the current state (registers, PC, etc.)
- Switches to kernel mode
- Jumps to interrupt handler (e.g., timer_interrupt_handler())
-  OS decides: resume app or do a context switch to another process.

---

### 🔍 Summary Table

| Type      | Source         | CPU Step 1            | CPU Step 2 | CPU Step 3            | Final Step                |
| --------- | -------------- | --------------------- | ---------- | --------------------- | ------------------------- |
| Trap      | App (software) | Look up vector in IDT | Save state | Switch to kernel mode | Jump to trap handler      |
| Exception | CPU (error)    | Look up vector in IDT | Save state | Switch to kernel mode | Jump to exception handler |
| Interrupt | Hardware       | Look up vector in IDT | Save state | Switch to kernel mode | Jump to interrupt handler |

---

## Definitions (Simple)

| Term      | Meaning                                                                                        |
| --------- | ---------------------------------------------------------------------------------------------- |
| Trap      | A signal generated by your own app (software) to ask kernel for help.                          |
| Interrupt | A signal generated by hardware (like timer, keyboard, disk) to get CPU’s attention.            |
| Exception | A signal caused by error or special condition during program execution (e.g., divide by zero). |

###  Real-World Examples

- Trap: When YouTube app says: "Please open a video file" → It traps into kernel using open().
- Interrupt: Timer chip says: "Time's up! Stop this app!" → CPU is interrupted.
- Exception: Your code does 5 / 0 → CPU throws an exception.

---

##  High vs Low Privilege Instructions
 CPUs (like Intel) divide instructions into privilege levels:

| Privilege Level | Who runs here?           | Example Instruction                 |
| --------------- | ------------------------ | ----------------------------------- |
| Ring 0          | Kernel mode (full power) | Access hardware, disable interrupts |
| Ring 3          | User mode (limited)      | Run apps like Chrome, Free Fire     |

🔍 Some instructions are only allowed in Ring 0:

- Talking to devices
- Disabling interrupts

If an app (in Ring 3) tries them —  CPU blocks it → sends exception → Trap to kernel(it's mean mode switch from user to kernel).

---

##  How Mode Switching Works

1. Start: OS is running in kernel mode

   - It prepares everything → memory, devices
   - It sets up user program (like YouTube) to run

2. Switch to user mode

   - OS sets a flag (CPL/RPL = Ring 3)
   - It jumps to user code → now app runs in low privilege mode

3. App asks for kernel help (Trap)

   - App does system call (like open())
   - CPU changes to kernel mode (Ring 0)
   - OS takes over

4. Mode Switch Back
   - When OS finishes → it goes back to user mode
   - App resumes

What if app misbehaves?  
Tries to run privileged instruction? 
CPU detects violation (instruction not allowed in user mode)  
→ stop program
→ Generates exception  
→ CPU switches to kernel mode  
→ Passes control to OS exception handler

