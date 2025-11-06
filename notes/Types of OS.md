## Batch Processing System 

### Definition

- A **batch processing system** is an early type of operating system where **jobs are collected, grouped into batches, and executed one after another without user interaction**.

### Working (Step by Step)

1. **User prepares job** → written on punch cards .
2. **Submit to operator (human)** → user gives job to computer operator.
3. **Operator groups jobs** → batches are made based on similar needs (e.g., same language compiler).
4. **Batch submitted to processor** → one batch at a time is loaded.
5. **Jobs in batch executed sequentially** → no manual intervention until the batch finishes.
### Characteristics

- Jobs are processed **sequentially** (one after another).
- **No direct interaction** between user and computer during execution.
- Uses **human operator** for job collection and submission.
- Best for **long  jobs**.

In a **Batch Processing System (old single-process OS)**:

- **Only one batch is submitted at a time.**
- From that batch, the system loads **one job into memory at a time**.
- That job runs till it **finishes** (or fails).
- Then the **next job** from the same batch is loaded into memory.

### Distributed OS
####  How Distributed OS actually work

1. **Installed on all machines**
    - A **Distributed OS** is not just one copy on one machine.
    - It runs on **all the computers** in the network.        
    - Each computer has its own local OS “part,” but all cooperate together to behave like **one big OS**.
2. **User login**
    - You (the user) log in from **any one computer** .
    - That machine talks to the rest of the network.
3. **Communication between machines**
    - The distributed OS instances (running on each computer) are **connected to each other**.
    - They share information about resources (CPU, memory, files).
4. **Task execution**
    - When you run a program, the OS decides **where it should run** (maybe locally, maybe on another computer).
    - If your program needs files stored on another computer, the OS fetches them automatically.
5. **Result back to user**
    - Even if your job was executed on a different machine, you see the result on **your screen** — as if your own computer did all the work.