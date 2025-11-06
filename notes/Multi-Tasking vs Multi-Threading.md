
# Multi-Tasking vs Multi-Threading
##  Thread
- **Single = One task**
- **Sequence = Order**
    - The instructions are carried out **step by step, in order**.
- **Stream = Continuous flow of instructions(A stream = a continuous flow of something**.)
    - The CPU keeps fetching and executing instructions one after another, like a flow of water.

- **Process** = big container (like a kitchen).
- **Thread** = one person following _one recipe step by step_ (single sequence stream).

**Single sequence stream** =  One continuous flow of ordered instructions that the CPU executes step by step to complete a task.

Even though threads are executing within the runtime That line means

→ _Threads belong to the same program and look like they all run together, But in reality, the **Operating System** controls _when_ each thread actually runs by giving them **time slices**.