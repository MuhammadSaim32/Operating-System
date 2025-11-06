# Segmentation
### **Definition**

Segmentation is a **memory management technique** that divides a process into **logical segments** like code, data, stack, and heap — each of **variable size**.

### **Key Points**

- Each segment has a **base** (starting address) and **limit** (length).
- Logical address = **(segment number, offset)**
- Physical address = **base + offset**
- Handled by the **OS and hardware**, not the user.
### **Main Segments**

1. **Code (Text)** – program instructions
2. **Data** – global/static variables
3. **Stack** – function calls, local variables
4. **Heap** – dynamic memory (`malloc`, `new`)

### **Comparison with Paging**

|Feature|Segmentation|Paging|
|---|---|---|
|Division|Logical|Physical|
|Size|Variable|Fixed|
|Fragmentation|External|Internal|
|Address|Segment + Offset|Page + Offset|

### **Formula**

`Physical Address = Base + Offset`

###  **In Simple Words**

> Segmentation divides memory by **purpose**, not size.  
> Each segment is a **logical part** of a program (code, data, stack, heap).



## Two Types of “Segmentation Explanations” You’ll See Online

###  **A. Theoretical Explanation (Textbook / Example Style)**

> “We can divide program logically — `add()` in one segment, `mul()` in another…”

This is used **only for explaining the concept** — to show that segmentation divides memory by _logical meaning_, not by fixed size.

 It’s just an **example** to help you _visualize_ what segmentation means —  
not how actual operating systems do it.

So, in those examples:

- 1 segment = `add()` function
- 1 segment = `mul()` function
- 1 segment = main code  
    This shows **logical division**, and how each segment can have **different sizes**.
### **B. Practical Explanation (How real OSes do it)**

In real systems (like Linux, Windows, etc.), the compiler + OS **automatically divide** your program into these segments:

- **Code (Text)** segment → contains _all_ compiled functions (`main`, `add`, `mul`, etc.)
- **Data** segment → global/static variables
- **Stack** segment → function calls and locals
- **Heap** segment → dynamically allocated memory

So you, the user, **don’t** define `add()` as a separate segment — the OS just groups _all code_ in the **code segment**.

##  How This Differs from Paging

### **Paging**

- Memory is divided into **fixed-size blocks** (pages), e.g. 4 KB
- The OS doesn’t care what’s inside — code, data, or stack.    
- Each 4 KB page is mapped independently.

So if your program is 8 KB → it takes **2 pages**, no problem.  
If it’s 9 KB → it takes **3 pages** (1 KB wasted = internal fragmentation).

OS doesn’t know that one page holds code and another holds stack.  
All pages look the same.


###  **Segmentation**

- Memory is divided by **logical meaning**.
- Each segment can be **different size** (no wasted space inside).
- But free memory gets scattered — causing **external fragmentation**.

So yes — in theory, you can say:

> “I’ll make separate segments for `add()` and `mul()` to avoid 4 KB page waste.”

That’s **true in theory**, but **not how modern OSes actually do it** —  
because **modern CPUs mostly use paging (or segmentation + paging)**.

##  Paging vs Segmentation Summary

| Feature              | Paging                 | Segmentation                     |
| -------------------- | ---------------------- | -------------------------------- |
| Divides by           | Fixed size (e.g. 4 KB) | Logical meaning (code/data/etc.) |
| Size                 | Fixed                  | Variable                         |
| Wastage              | Internal fragmentation | External fragmentation           |
| OS knows meaning     | No                     | Yes                              |
| Address format       | Page + Offset          | Segment + Offset                 |
| Who decides division | OS (by size)           | Programmer/Compiler (by logic)   |

##  Final Concept:

> Those online “add() and mul() segments” are **conceptual examples**  
> showing segmentation divides by logic.
> 
> In **real systems**, segmentation = **code/data/stack/heap**.
> Paging doesn’t care what’s inside — it just breaks everything into equal 4 KB pages.


**Locality of reference** means a program **accesses the same memory locations repeatedly or nearby ones** within a short time.