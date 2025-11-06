# Zombie Process

### When does it get removed?

| Situation                                       | What happens                                                                                                        |
| ----------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- |
| **Parent calls `wait()`**                       | Zombie entry is removed immediately.                                                                                |
| **Parent exits without calling `wait()`**       | Then the **zombie is adopted by `systemd` (PID 1)** — and **systemd calls `wait()`** automatically, cleaning it up. |
| **Parent stays alive but never calls `wait()`** | Zombie stays in the process table forever (until parent dies).                                                      |