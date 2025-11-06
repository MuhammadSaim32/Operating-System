# System call working

## Step-by-Step: `mkdir()` Flow

###  1.**Your Program (User Code)**

You write:

`#include <sys/stat.h>  int main() {     mkdir("test", 0777);     return 0; }`

This is your **user-space code**.  
You’re not talking to the kernel directly — you’re calling a **function from glibc**.

### 2. **glibc (GNU C Library Layer)**

- `mkdir()` in glibc is just a **wrapper function**.
- It takes your arguments (`"test"`, `0777`) and internally calls the **system call** version.

Inside glibc, it looks something like:

`int mkdir(const char *pathname, mode_t mode) {     return __mkdir(pathname, mode);   // internal call to system call }`

### 3. **System Call Interface (SCI)**

- glibc then triggers the **System Call Interface**, which is the real bridge to the kernel.
- It loads the **system call number** for `mkdir` into a CPU register (e.g. `rax`),  
    sets up the arguments, and executes the special CPU instruction `syscall`.

Example (in assembly idea):

`mov rax, 83        ; syscall number for mkdir mov rdi, pathname  ; 1st argument mov rsi, mode      ; 2nd argument syscall            ; switch to kernel mode```

This `syscall` instruction is what **transfers control to the kernel**.

---

### 4. **Kernel Mode (Linux Kernel)**

Now the **kernel** runs.  
It receives your system call request via the **System Call Table** — a table mapping numbers → functions.

- `83` → points to `sys_mkdir()` inside the kernel.
- Kernel checks permissions, filesystem, etc.
- Then creates the directory on disk.

Finally, it returns a result (0 for success, -1 for error).

### 5. **Back to glibc → Your Program**

- The kernel returns control to **glibc** via the SCI.
- glibc translates the kernel return value into a normal C return code.
- Then your program gets the result.

Example:

`if (mkdir("test", 0777) == 0)     printf("Directory created\n"); else     perror("mkdir failed");`

---

##  Summary Diagram

`Your Code → glibc wrapper → System Call Interface → Kernel → Filesystem → Back to User Code`

|Layer|Example Function|Role|
|---|---|---|
|**User Program**|`mkdir("test", 0777)`|Calls library function|
|**glibc**|`mkdir()` wrapper|Prepares and invokes system call|
|**SCI**|`syscall` instruction|Switches to kernel mode|
|**Kernel**|`sys_mkdir()`|Actually creates the directory|
|**Return**|→ back to user program|Returns result (success/error)|