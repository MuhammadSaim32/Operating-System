# Sync in OS

| Concept                | Meaning                                                    | Key Features                                                                                                                                                           |
| ---------------------- | ---------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Semaphore**          | Used to control **access to shared resources**.            | Can handle **multiple instances** of a resource (using a counter).  <br> Doesn’t _need_ an external lock — it’s built-in.  <br>Has `wait()` and `signal()` operations. |
| **Condition Variable** | Used for **waiting for a condition/state** to become true. |  Works with **locks (mutexes)** — always needs one.  <br> No counter — just sleeps/wakes threads.  <br>Has `wait()`, `notify_one()`, and `notify_all()`.               |

---

### So, in simple words:

> **Semaphore** = “Let only _N_ threads enter at once.”  
> → Good for _counting resources_ (like 5 printers).  
> → Has built-in synchronization logic (no need for separate mutex).

> **Condition Variable** = “Wait until a _condition_ becomes true.”  
> → Good for _thread coordination_ (like producer-consumer).  
> → Needs a mutex to safely check and wait on shared data.

---

### Example analogy:

| Situation                                                                    | Tool to use                 |
| ---------------------------------------------------------------------------- | --------------------------- |
| You have **3 printers** and **10 threads** that want to print → limit access |  **Semaphore (counting)**   |
| You have **one queue** and threads that must wait until data arrives         | <br> **Condition Variable** |


##  Problem Goal

We have a **shared resource** (like a file or database).
- **Multiple readers** can read it **at the same time** 
- But **only one writer** can write — and **no one else (reader or writer)** should access during writing.

- Many readers 
- One writer 

##  Shared Variables

```
mutex       = 1   // protects read_count (so only one thread updates it at a time)
rw_mutex    = 1   // ensures mutual exclusion for readers vs writers
read_count  = 0   // number of readers currently reading
```

---

##  Reader Process (pseudocode)

```
wait(mutex)                // lock before changing read_count
read_count = read_count + 1
if read_count == 1 then    // first reader locks writers
    wait(rw_mutex)
signal(mutex)              // allow others to change read_count

// --- Critical Section: reading ---
... read the data ...

wait(mutex)
read_count = read_count - 1
if read_count == 0 then    // last reader unlocks writer
    signal(rw_mutex)
signal(mutex)
```

##  Writer Process (pseudocode)


```
wait(rw_mutex)   
--- Critical Section: writing --- 
signal(rw_mutex) // release lock
```
