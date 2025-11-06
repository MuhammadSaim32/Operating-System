## Process Creation — Key OS Concepts

### 1. **Runtime Stack**

- Each process gets its **own stack** when created.
- Used to store:
    - Function parameters
    - Local variables
    - Return addresses
- Each function call creates a **stack frame**.
- `main()` also has its **own stack frame** — it’s the **first one** at the bottom of the stack.
### 2. **I/O Setup**

When a process starts, the OS also gives it **default I/O connections** (called **handles** or **file descriptors**):

|Descriptor|Name|Purpose|Usually Connected To|
|---|---|---|---|
|0|**stdin**|Input|Keyboard / file|
|1|**stdout**|Output|Screen / file|
|2|**stderr**|Error output|Screen|

These allow the process to **read and write** without knowing hardware details.
### 3. **Descriptor (Meaning)**

- A **descriptor** is just a **small integer ID** the OS gives to represent an open resource.
- Examples: files, sockets, pipes, devices.
- You use the number to perform I/O; the OS knows what real resource it refers to.

 Example:

`int fd = open("data.txt", O_RDONLY); read(fd, buffer, 100);`

- `fd` might be **3** → a file descriptor.
- The OS knows which file corresponds to it.
